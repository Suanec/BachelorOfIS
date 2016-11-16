// ShareScreenClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "ShareScreenClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientDlg dialog

#include "InstantMessagingDlg.h"
#include "ShareScreenClientSocket.h"

CShareScreenClientDlg::CShareScreenClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShareScreenClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShareScreenClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShareScreenClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShareScreenClientDlg)
	DDX_Control(pDX, IDS_SCREEN, m_staticScreen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShareScreenClientDlg, CDialog)
	//{{AFX_MSG_MAP(CShareScreenClientDlg)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientDlg message handlers

BOOL CShareScreenClientDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	/// 初始化
	Init();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/// 初始化
void CShareScreenClientDlg::Init()
{
	/// 获取主对话框
	m_pMainDlg = ( CInstantMessagingDlg * )::AfxGetMainWnd();

	SetPosition();

	/// 初始化UDP套接字
	m_pSSCSocket = new CShareScreenClientSocket( this );
	m_pSSCSocket->Create( SHARESCREENCLIENT_PORT, SOCK_DGRAM );

	/// 设置服务器屏幕的宽与高
	m_nServerScreenCX = 0;
	m_nServerScreenCY = 0;
}

/// 调整各控件的位置
void CShareScreenClientDlg::SetPosition()
{
}


void CShareScreenClientDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	SetPosition();
}

void CShareScreenClientDlg::OnOk() 
{
}

void CShareScreenClientDlg::OnCancel() 
{	
	if( IDOK == MessageBox( "要关闭共享屏幕吗？", "关闭", MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON2 ) )
	{	
		/// 关闭共享屏幕的USER
		USER userSelf;
		userSelf.bHasCamera	= m_pMainDlg->HasCamera();
		userSelf.nFace		= m_pMainDlg->GetFace();
		memcpy( userSelf.strName, m_pMainDlg->GetNickName().GetBuffer( MAXNICKNAMELENGTH + 1 ), MAXNICKNAMELENGTH + 1 );
		
		SendUserCommandToIP( SHARESCREEN_CLIENT_CLOSED, m_strServerIP, SHARESCREENSERVER_PORT, &userSelf );

		/// 关闭UDP套接字
		m_pSSCSocket->Close();
		delete [] m_pSSCSocket;
		m_pSSCSocket = NULL;

		DestroyWindow();
	}
}

/// 从UDP中接收数据
void CShareScreenClientDlg::OnReceive()
{
	/// 接收数据
	CString strIP;
	UINT uPort;
	BYTE *szReceive;
	DWORD dwReceivDataLength = MAXDATAPACKETLENGTH;
	if( 0 != m_nServerScreenCX && 0 != m_nServerScreenCY )
	{
		WORD wBitCount = SHARESCREEN_BITCOUNT;
		DWORD dwPaletteSize = 0;
		if( wBitCount <= 8 )
		{
			dwPaletteSize = ( 1 << wBitCount ) * sizeof( RGBQUAD );
		}
		DWORD dwBmBitsSize	= ( ( m_nServerScreenCX * wBitCount + 31 ) / 32 ) * 4 * m_nServerScreenCY ;
		dwReceivDataLength = sizeof( DATAPACKET ) 
			+ sizeof( BITMAPINFOHEADER ) 
			+ dwPaletteSize 
			+ dwBmBitsSize;
	}
	szReceive = new BYTE[ dwReceivDataLength ];
	
	m_pSSCSocket->ReceiveFrom( szReceive, dwReceivDataLength, strIP, uPort );

	/// 装配数据包
	DATAPACKET dataPacket;
	memcpy( &dataPacket, szReceive, sizeof( DATAPACKET ) );

	/// 根据命令进行不同的处理
	switch( dataPacket.command )
	{
	case SHARESCREEN_SERVER_CLOSED:							/// 共享屏幕服务器关闭
		ServerClosed();
		break;
	case SHARESCREEN_CLIENT_KICKED:							/// 客户端被踢
		Kicked();
		break;
	case SHARESCREEN_SERVER_SCREEN_DIM:						/// 服务器屏幕尺寸
		memcpy( &m_nServerScreenCX, szReceive + sizeof( DATAPACKET ), sizeof( int ) );
		memcpy( &m_nServerScreenCY, szReceive + sizeof( DATAPACKET ) + sizeof( int ), sizeof( int ) );
		break;
	case SHARESCREEN_SERVER_SCREEN:							///	共享屏幕服务器的屏幕数据
		ReceiveScreenData( szReceive );
		break;
	default:
		break;
	}

	delete [] szReceive;
}

/// 向指定IP、PORT发送指定数据
void CShareScreenClientDlg::SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT uPort, const USER *pUser )
{
	DATAPACKET dataPacket;
	dataPacket.command	= command;
	
	/// 分配空间
	UINT uDataLength = sizeof( DATAPACKET );
	if( pUser )
	{
		uDataLength += sizeof( USER );
	}
	BYTE *pSendData = new BYTE[ uDataLength ];
	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	if( pUser )
	{
		memcpy( pSendData + sizeof( DATAPACKET ), pUser, sizeof( USER ) );
	}
	
	/// 发送数据
	m_pSSCSocket->SendTo( pSendData, uDataLength, uPort, szIP );

	delete pSendData;
}

/// 添加服务器和自己到用户列表框
void CShareScreenClientDlg::AcceptAddRequest(  const USER userServer )
{
	/// 设置服务器IP
	m_strServerIP = userServer.strIP;

	/// 自己的USER
	USER userSelf;
	userSelf.bHasCamera	= m_pMainDlg->HasCamera();
	userSelf.nFace		= m_pMainDlg->GetFace();
	memcpy( userSelf.strName, m_pMainDlg->GetNickName().GetBuffer( MAXNICKNAMELENGTH + 1 ), MAXNICKNAMELENGTH + 1 );

	/// 接受请求加入共享屏幕
	SendUserCommandToIP( SHARESCREEN_ADDREQUEST_ALLOW, m_strServerIP, SHARESCREENSERVER_PORT, &userSelf );
}

/// 被踢出共享屏幕
void CShareScreenClientDlg::Kicked()
{
	/// 关闭UDP套接字
	m_pSSCSocket->Close();

	/// 提示
	MessageBox( "你被创建者踢出来了共享屏幕！", "共享屏幕" );

	/// 关闭对话框
	DestroyWindow();
}

/// 服务器关闭
void CShareScreenClientDlg::ServerClosed()
{
	/// 关闭UDP套接字
	m_pSSCSocket->Close();

	/// 提示
	MessageBox( "创建者关闭了共享屏幕！", "共享屏幕" );

	/// 关闭对话框
	DestroyWindow();
}

/// 接收屏幕数据
void CShareScreenClientDlg::ReceiveScreenData( BYTE *pReceivedData )
{
	DATAPACKET dataPacket;
	memcpy( &dataPacket, pReceivedData, sizeof( DATAPACKET ) );

	/// 计算图像的本身长度
	WORD wBitCount = SHARESCREEN_BITCOUNT;
	DWORD dwPaletteSize = 0;
	if( wBitCount <= 8 )
	{
		dwPaletteSize = ( 1 << wBitCount ) * sizeof( RGBQUAD );
	}
	DWORD dwBmBitsSize	= ( ( m_nServerScreenCX * wBitCount + 31 ) / 32 ) * 4 * m_nServerScreenCY ;
	DWORD dwBmpLength	= sizeof( BITMAPINFOHEADER ) + dwPaletteSize + dwBmBitsSize;

	BYTE *pBI = new BYTE[ dwBmpLength ];

	/// 数据被压缩过
	if( dwBmpLength > dataPacket.dwLength )
	{
		DWORD dwPBILength;
		uncompress( pBI, &dwPBILength, pReceivedData + sizeof( DATAPACKET ), dataPacket.dwLength );
	}
	else
	{
		memcpy( pBI, pReceivedData + sizeof( DATAPACKET ), dataPacket.dwLength );
	}

	m_nServerScreenCX = ( ( BITMAPINFOHEADER * )pBI )->biWidth;
	m_nServerScreenCY = ( ( BITMAPINFOHEADER * )pBI )->biHeight;

	HDC hDC			= ::GetDC( NULL );
	HBITMAP hBitmap	= ::CreateCompatibleBitmap( hDC, m_nServerScreenCX, m_nServerScreenCY );
	::SelectObject( hDC, hBitmap );

	::SetDIBits( hDC, hBitmap, 0, m_nServerScreenCY, 
		( LPSTR )pBI + sizeof( BITMAPINFOHEADER ) + dwPaletteSize, 
		( BITMAPINFO * )pBI, DIB_RGB_COLORS );

	HBITMAP hOldBitmap = m_staticScreen.SetBitmap( hBitmap );

	::DeleteObject( hOldBitmap );
	::ReleaseDC( NULL, hDC );

	/// 删除申请的内存
	delete pBI;
}