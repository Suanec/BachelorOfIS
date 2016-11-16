// ShareScreenServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "ShareScreenServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerDlg dialog

#include "InstantMessagingDlg.h"
#include "ShareScreenServerSocket.h"

CShareScreenServerDlg::CShareScreenServerDlg(CWnd* pParent /*=NULL*/)
: CDialog(CShareScreenServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShareScreenServerDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
	m_imageList.Create( 16, 16, ILC_MASK | ILC_COLOR24, 0, 0 );
	CBitmap bitmap32;
	CBitmap bitmap16;
	HBITMAP hBitmap;
	for( int nIndex = 0; nIndex < MAXFACES; nIndex++ )
	{
		bitmap32.LoadBitmap( IDB_BITMAP1 + nIndex );
		hBitmap = ( HBITMAP )::CopyImage( ( HBITMAP )bitmap32, IMAGE_BITMAP, 16, 16, LR_COPYDELETEORG );
		bitmap16.Attach( hBitmap );
		m_imageList.Add( &bitmap16, FACEBGCOLOR );
		bitmap16.DeleteObject();
		bitmap32.DeleteObject();
		::DeleteObject( hBitmap );
	}
}


void CShareScreenServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShareScreenServerDlg)
	DDX_Control(pDX, IDE_INFORMATION, m_editInformation);
	DDX_Control(pDX, IDC_LIST_OUTOFSHARESCREEN, m_listCtrlOutOfShareScreen);
	DDX_Control(pDX, IDC_LIST_INSHARESCREEN, m_listCtrlInShareScreen);
	DDX_Control(pDX, IDB_DELFRIENDS, m_btnDeleteFriends);
	DDX_Control(pDX, IDB_ADDFRIENDS, m_btnAddFriends);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShareScreenServerDlg, CDialog)
//{{AFX_MSG_MAP(CShareScreenServerDlg)
ON_BN_CLICKED(IDB_ADDFRIENDS, OnAddfriends)
ON_BN_CLICKED(IDB_DELFRIENDS, OnDelfriends)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerDlg message handlers

void CShareScreenServerDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CShareScreenServerDlg::OnCancel() 
{
	if( IDOK == MessageBox( "要关闭共享屏幕吗？", "关闭", MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON2 ) )
	{
		/// 关掉定时器
		KillTimer( TIMER_SHARESCREEN );

		/// 向所有客户端发送关闭服务器消息
		for( int nIndex = 0; nIndex < m_listCtrlInShareScreen.GetItemCount(); nIndex++ )
		{
			USER user = m_arrFriendsInShareScreen.GetAt( nIndex );
			SendUserCommandToIP( SHARESCREEN_SERVER_CLOSED, user.strIP, SHARESCREENCLIENT_PORT, NULL );
		}
		
		/// 关闭UDP套接字
		m_pSSSSocket->Close();
		delete [] m_pSSSSocket;
		m_pSSSSocket = NULL;
		
		/// 清空用户列表
		m_arrFriendsInShareScreen.RemoveAll();
		m_arrFriendsOutOfShareScreen.RemoveAll();
		
		DestroyWindow();
	}
}

BOOL CShareScreenServerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	/// 初始化
	Init();	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

/// 初始化
void CShareScreenServerDlg::Init()
{
	/// 获取主对话框
	m_pMainDlg = ( CInstantMessagingDlg * )::AfxGetMainWnd();
	
	/// 设置添加联系人的图标
	m_btnAddFriends.setBmp( IDB_CHATROOM_ADD_NORMAL, 
		IDB_CHATROOM_ADD_HOVER, 
		IDB_CHATROOM_ADD_DOWN, 
		IDB_CHATROOM_ADD_DISABLE );
	
	/// 设置删除联系人的图标
	m_btnDeleteFriends.setBmp( IDB_CHATROOM_DEL_NORMAL, 
		IDB_CHATROOM_DEL_HOVER, 
		IDB_CHATROOM_DEL_DOWN, 
		IDB_CHATROOM_DEL_DISABLE );
	
	/// 设置用户列表框的图像
	m_listCtrlInShareScreen.SetImageList( &m_imageList, LVSIL_SMALL );
	m_listCtrlInShareScreen.SetExtendedStyle( m_listCtrlInShareScreen.GetExtendedStyle() | 
		LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );
	m_listCtrlInShareScreen.InsertColumn( 0, "" );
	
	m_listCtrlOutOfShareScreen.SetImageList( &m_imageList, LVSIL_SMALL );
	m_listCtrlOutOfShareScreen.SetExtendedStyle( m_listCtrlOutOfShareScreen.GetExtendedStyle() | 
		LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES );
	m_listCtrlOutOfShareScreen.InsertColumn( 0, "" );
	
	/// 设置不在共享屏幕的好友，并全部选中
	m_pMainDlg->GetFriendsArray( m_arrFriendsOutOfShareScreen );
	for( int nIndex = 0; nIndex < m_arrFriendsOutOfShareScreen.GetSize(); nIndex++ )
	{
		USER user = m_arrFriendsOutOfShareScreen.GetAt( nIndex );
		CString strText;
		strText.Format( "%s(%s)", user.strName, user.strIP );
		m_listCtrlOutOfShareScreen.InsertItem( nIndex, strText, user.nFace );
		m_listCtrlOutOfShareScreen.SetCheck( nIndex );
		m_listCtrlOutOfShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
	}
		
	/// 设置　添加　和　删除　按钮的状态
	if( 0 == m_arrFriendsOutOfShareScreen.GetSize() )
	{
		m_btnAddFriends.EnableWindow( FALSE );	
	}
	else
	{	
		m_btnAddFriends.SetNormal();
	}
	m_btnDeleteFriends.EnableWindow( FALSE );
	
	// 初始化UDP套接字
	m_pSSSSocket = new CShareScreenServerSocket( this );
	m_pSSSSocket->Create( SHARESCREENSERVER_PORT, SOCK_DGRAM );

	/// 设置定时器
	SetTimer( TIMER_SHARESCREEN, DEFAULT_SHARESCREEN_REFRESH, NULL );
}

/// 向指定IP、PORT发送指定数据
void CShareScreenServerDlg::SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT uPort, const USER *pUser )
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
	m_pSSSSocket->SendTo( pSendData, uDataLength, uPort, szIP );
	
	delete pSendData;
}

/// 从UDP中接收数据
void CShareScreenServerDlg::OnReceive()
{
	/// 接收数据
	CString strIP;
	UINT uPort;
	char szReceive[ MAXDATAPACKETLENGTH ];
	m_pSSSSocket->ReceiveFrom( szReceive, MAXDATAPACKETLENGTH, strIP, uPort );
	
	/// 装配数据包
	DATAPACKET dataPacket;
	memcpy( &dataPacket, szReceive, sizeof( DATAPACKET ) );
	USER user;
	
	/// 根据命令进行不同的处理
	switch( dataPacket.command )
	{
	case SHARESCREEN_ADDREQUEST_DENY:							/// 客户端拒绝加入共享屏幕服务器
		break;
	case SHARESCREEN_ADDREQUEST_ALLOW:							/// 客户端允许加入共享屏幕服务器
		memcpy( &user, szReceive + sizeof( DATAPACKET ), sizeof( USER ) );
		memcpy( user.strIP, strIP.GetBuffer( 16 ), 16 );
		strIP.ReleaseBuffer();
		AddUserToShareScreen( user );
		break;
	case SHARESCREEN_CLIENT_CLOSED:								/// 客户端关闭共享屏幕
		memcpy( &user, szReceive + sizeof( DATAPACKET ), sizeof( USER ) );
		memcpy( user.strIP, strIP.GetBuffer( 16 ), 16 );
		strIP.ReleaseBuffer();
		DelUserFromShareScreen( user );
		break;
	default:
		break;
	}
}

void CShareScreenServerDlg::OnAddfriends() 
{
	/// 发起共享屏幕请求的USER
	USER userSelf;
	userSelf.bHasCamera	= m_pMainDlg->HasCamera();
	userSelf.nFace		= m_pMainDlg->GetFace();
	memcpy( userSelf.strName, m_pMainDlg->GetNickName().GetBuffer( MAXNICKNAMELENGTH + 1 ), MAXNICKNAMELENGTH + 1 );
	
	for( int nIndex = 0; nIndex < m_listCtrlOutOfShareScreen.GetItemCount(); nIndex++ )
	{
		if( m_listCtrlOutOfShareScreen.GetCheck( nIndex ) )
		{
			USER user = m_arrFriendsOutOfShareScreen.GetAt( nIndex );
			SendUserCommandToIP( SHARESCREEN_ADDREQUEST, user.strIP, DEFAULT_PORT, &userSelf );
		}
	}
}

void CShareScreenServerDlg::OnDelfriends() 
{
	static BOOL bFirst = TRUE;
	for( int nIndex = 0; nIndex < m_listCtrlInShareScreen.GetItemCount(); nIndex++ )
	{
		if( m_listCtrlInShareScreen.GetCheck( nIndex ) )
		{
			if( bFirst == TRUE )
			{
				/// 提示
				CString strPrompt;
				strPrompt.Format( "您是否要从共享屏幕删除这些好友？" );
				
				/// 拒绝请求
				if( IDCANCEL == MessageBox( strPrompt, "共享屏幕", MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON1 ) )
				{
					return;
				}
				bFirst = FALSE;
			}
			
			USER user = m_arrFriendsInShareScreen.GetAt( nIndex );
			
			/// 向被删除用户发送删除消息
			SendUserCommandToIP( SHARESCREEN_CLIENT_KICKED, user.strIP, SHARESCREENCLIENT_PORT, NULL );
			Sleep( 100 );
			
			/// 更新接收编辑框
			CString strDelText;
			CTime time = CTime::GetCurrentTime();
			CString strTime = time.Format( "%H:%M:%S" );
			strDelText.Format( "%s(%s) %s 停止观看您的屏幕！\r\n\r\n", 
				user.strName, user.strIP, strTime.GetBuffer( 10 ) );
			strTime.ReleaseBuffer( -1 );
			CString strReceiveText;
			m_editInformation.GetWindowText( strReceiveText );
			m_editInformation.SetWindowText( strReceiveText + strDelText );
			m_editInformation.LineScroll( m_editInformation.GetLineCount() );
			
			m_arrFriendsOutOfShareScreen.Add( user );
			CString strText;
			strText.Format( "%s(%s)", user.strName, user.strIP );
			m_listCtrlOutOfShareScreen.InsertItem( m_listCtrlOutOfShareScreen.GetItemCount(), strText, user.nFace );
			m_listCtrlOutOfShareScreen.SetCheck( m_listCtrlOutOfShareScreen.GetItemCount() - 1, TRUE );
			m_listCtrlOutOfShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			m_arrFriendsInShareScreen.RemoveAt( nIndex );
			m_listCtrlInShareScreen.DeleteItem( nIndex );
			m_listCtrlInShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			nIndex--;
		}
	}
	bFirst = TRUE;
	
	UpdateButtons();
}

/// 更新添加和删除按钮
void CShareScreenServerDlg::UpdateButtons()
{
	/// 更改添加好友的按钮状态
	if( 0 != m_arrFriendsInShareScreen.GetSize() )
	{
		m_btnDeleteFriends.SetNormal();
	}
	else
	{
		m_btnDeleteFriends.EnableWindow( FALSE );
	}
	
	/// 更改删除好友的按钮
	if( 0 != m_arrFriendsOutOfShareScreen.GetSize() )
	{
		m_btnAddFriends.SetNormal();
	}
	else
	{
		m_btnAddFriends.EnableWindow( FALSE );
	}
}

/// 向共享屏幕添加用户
void CShareScreenServerDlg::AddUserToShareScreen( const USER user )
{
	for( int nIndex = 0; nIndex < m_arrFriendsOutOfShareScreen.GetSize(); nIndex++ )
	{
		USER userNew = m_arrFriendsOutOfShareScreen.GetAt( nIndex );
		if( 0 == strcmp(user.strIP, userNew.strIP ) )
		{	
			/// 更新接收编辑框
			CString strJoinText;
			CTime time = CTime::GetCurrentTime();
			CString strTime = time.Format( "%H:%M:%S" );
			strJoinText.Format( "%s(%s) %s 可以观看您的屏幕了！\r\n\r\n", 
				userNew.strName, userNew.strIP, strTime.GetBuffer( 10 ) );
			strTime.ReleaseBuffer( -1 );

			CString strReceiveText;
			m_editInformation.GetWindowText( strReceiveText );
			m_editInformation.SetWindowText( strReceiveText + strJoinText );
			m_editInformation.LineScroll( m_editInformation.GetLineCount() );
			
			/// 更新共享屏幕列表
			m_arrFriendsInShareScreen.Add( userNew );
			
			CString strText;
			strText.Format( "%s(%s)", userNew.strName, userNew.strIP );
			m_listCtrlInShareScreen.InsertItem( m_listCtrlInShareScreen.GetItemCount(), strText, userNew.nFace );
			m_listCtrlInShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			m_arrFriendsOutOfShareScreen.RemoveAt( nIndex );
			m_listCtrlOutOfShareScreen.DeleteItem( nIndex );
			m_listCtrlOutOfShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			break;
		}
	}
	
	UpdateButtons();

	SendDIMToFriends( user );
}

/// 移除用户
void CShareScreenServerDlg::DelUserFromShareScreen( const USER user )
{	
	for( int nIndex = 0; nIndex < m_arrFriendsInShareScreen.GetSize(); nIndex++ )
	{
		USER userDel = m_arrFriendsInShareScreen.GetAt( nIndex );
		if( 0 == strcmp(user.strIP, userDel.strIP ) )
		{
			/// 更新接收编辑框
			CString strDelText;
			CTime time = CTime::GetCurrentTime();
			CString strTime = time.Format( "%H:%M:%S" );
			strDelText.Format( "%s(%s) %s 停止观看您的屏幕！\r\n\r\n", 
				userDel.strName, userDel.strIP, strTime.GetBuffer( 10 ) );
			strTime.ReleaseBuffer( -1 );
			CString strReceiveText;
			m_editInformation.GetWindowText( strReceiveText );
			m_editInformation.SetWindowText( strReceiveText + strDelText );
			m_editInformation.LineScroll( m_editInformation.GetLineCount() );
			
			m_arrFriendsOutOfShareScreen.Add( userDel );
			CString strText;
			strText.Format( "%s(%s)", userDel.strName, userDel.strIP );
			m_listCtrlOutOfShareScreen.InsertItem( m_listCtrlOutOfShareScreen.GetItemCount(), strText, userDel.nFace );
			m_listCtrlOutOfShareScreen.SetCheck( m_listCtrlOutOfShareScreen.GetItemCount() - 1, TRUE );
			m_listCtrlOutOfShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			m_arrFriendsInShareScreen.RemoveAt( nIndex );
			m_listCtrlInShareScreen.DeleteItem( nIndex );
			m_listCtrlInShareScreen.SetColumnWidth( 0, LVSCW_AUTOSIZE_USEHEADER );
			break;
		}
	}
	
	UpdateButtons();
}

/// 得到屏幕的dib数据
void CShareScreenServerDlg::GetScreenDIB( BYTE *&pDIB, DWORD &dwDIBLength )
{
	/// 得到桌面的HDC
	HDC hDeskDC = ::GetDC( NULL );
	CRect rect;
	rect.top = 0;
	rect.left = 0;
	rect.right = GetSystemMetrics( SM_CXSCREEN );
	rect.bottom = GetSystemMetrics( SM_CYSCREEN );

	/// 创建与桌面兼容的HDC和bitmap
	HDC hdc = ::CreateCompatibleDC( hDeskDC );
	HBITMAP hbmp = ::CreateCompatibleBitmap( hDeskDC, rect.Width(), rect.Height() );
	::SelectObject( hdc, hbmp );
	::SetStretchBltMode( hdc, COLORONCOLOR );

	/// 获取桌面到兼容HDC
	::StretchBlt( hdc, 0, 0, rect.Width(), rect.Height(), hDeskDC, 
		rect.left, rect.top, rect.Width(), rect.Height(), SRCCOPY );

	/// 画鼠标
	CPoint mouse;
	GetCursorPos( &mouse );
	::DrawIcon( hdc, mouse.x - 10, mouse.y - 10, ::GetCursor() );

	/// 设置BITMAPINFOHEADER
	WORD wBitCount = SHARESCREEN_BITCOUNT;
	DWORD dwPaletteSize = 0;
	if( wBitCount <= 8 )
	{
		dwPaletteSize = ( 1 << wBitCount ) * sizeof( RGBQUAD );
	}
	BITMAP bm;
	::GetObject( hbmp, sizeof( bm ), &bm );

	BITMAPINFOHEADER bi;
	bi.biSize			= sizeof( BITMAPINFOHEADER );
	bi.biWidth			= bm.bmWidth;
	bi.biHeight			= bm.bmHeight;
	bi.biPlanes			= 1;
	bi.biBitCount		= wBitCount;
	bi.biCompression	= BI_RGB;
	bi.biSizeImage		= 0;
	bi.biXPelsPerMeter	= 0;
	bi.biYPelsPerMeter	= 0;
	bi.biClrUsed		= 0;
	bi.biClrImportant	= 0;
	DWORD dwBmBitsSize	= ( ( bm.bmWidth * wBitCount + 31 ) / 32 ) * 4 * bm.bmHeight ;
	bi.biSizeImage	= dwBmBitsSize;

	/// 长度为：bmp的信息头长度+调色板长度+数据
	dwDIBLength = sizeof( BITMAPINFOHEADER ) + dwPaletteSize + dwBmBitsSize;
	pDIB = new BYTE[ dwDIBLength ];

	/// 设置pDIB前为信息头
	*( LPBITMAPINFOHEADER )pDIB =bi;

	/// 获取DIB数据
	::GetDIBits( hdc, hbmp, 0, ( UINT )bm.bmHeight, ( LPSTR )pDIB + sizeof( BITMAPINFOHEADER ) + dwPaletteSize,
		( BITMAPINFO * )pDIB, DIB_RGB_COLORS );

	::DeleteObject( hbmp );
	::DeleteObject( hdc );
	::ReleaseDC( NULL, hDeskDC );

	/// 压缩数据
	DWORD dwMaxCompressLength	= compressBound( dwDIBLength );
	BYTE *pCompress				= new BYTE[ dwMaxCompressLength ];
	DWORD dwCompressLength;
	compress( pCompress, &dwCompressLength, pDIB, dwDIBLength );

	// 压缩有效，则使用压缩后的数据，否则使用原数据
	if( dwCompressLength < dwDIBLength )
	{
		BYTE *pTmp	= pDIB;
		pDIB		= pCompress;
		dwDIBLength = dwCompressLength;
		delete pTmp;
	}
	else
	{
		delete [] pCompress;
	}
}

/// 向好友传输桌面图面
void CShareScreenServerDlg::SendScreenToFriends()
{
	BYTE *pCompressData;
	DWORD dwDataLength;
	
	/// 获得桌面图像数据
	GetScreenDIB( pCompressData, dwDataLength );

	/// 组装数据包
	DATAPACKET dataPacket;
	dataPacket.command	= SHARESCREEN_SERVER_SCREEN;
	dataPacket.dwLength = dwDataLength;

	DWORD dwSendDataLength	= sizeof( DATAPACKET ) + dwDataLength;
	BYTE *pSendData			= new BYTE[ dwSendDataLength ];

	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	memcpy( pSendData + sizeof( DATAPACKET ), pCompressData, dwDataLength );

	delete pCompressData;

	BYTE *pDataTmp;
	DWORD dwSendedLength;
	DWORD dwSendedCount;

	/// 向所在好友传输入桌面数据
	for( int nIndex = 0; nIndex < m_arrFriendsInShareScreen.GetSize(); nIndex++ )
	{
		USER user = m_arrFriendsInShareScreen.GetAt( nIndex );

		pDataTmp		= pSendData;
		dwSendedLength	= 0;
		dwSendedCount	= 0;

		do
		{
			dwSendedLength	= m_pSSSSocket->SendTo( pDataTmp, 
				dwSendDataLength, 
				SHARESCREENCLIENT_PORT, 
				user.strIP );
			dwSendedCount	+= dwSendedLength;
			pDataTmp		+= dwSendedCount;
		}while( dwSendedCount < dwSendDataLength );
	}

	/// 删除申请的内存
	delete [] pSendData;
}

/// 向好友传输桌面的尺寸
void CShareScreenServerDlg::SendDIMToFriends( const USER user )
{
	int cx = GetSystemMetrics( SM_CXSCREEN );
	int cy = GetSystemMetrics( SM_CYSCREEN );

	DATAPACKET dataPacket;
	dataPacket.command	= SHARESCREEN_SERVER_SCREEN_DIM;

	/// 分配空间
	UINT uDataLength = sizeof( DATAPACKET ) + sizeof( int ) * 2;
	BYTE *pSendData = new BYTE[ uDataLength ];
	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	memcpy( pSendData + sizeof( DATAPACKET ), &cx, sizeof( int ) );
	memcpy( pSendData + sizeof( DATAPACKET ) + sizeof( int ), &cy, sizeof( int ) );
	
	/// 发送数据
	m_pSSSSocket->SendTo( pSendData, uDataLength, SHARESCREENCLIENT_PORT, user.strIP );
	
	delete pSendData;
}

void CShareScreenServerDlg::OnTimer(UINT nIDEvent) 
{
	switch( nIDEvent )
	{
	case TIMER_SHARESCREEN:								/// 共享屏幕的timer号
		SendScreenToFriends();
		break;
	default:
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
