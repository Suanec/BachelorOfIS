// AddUserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "InstantMessaging.h"
#include "InstantMessagingDlg.h"
#include "AddUserDlg.h"
#include "afxdialogex.h"


// CAddUserDlg 对话框

IMPLEMENT_DYNAMIC(CAddUserDlg, CDialogEx)

CAddUserDlg::CAddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddUserDlg::IDD, pParent)
	, m_UserIP(0)
{

}

CAddUserDlg::~CAddUserDlg()
{
}

void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_IPAddress(pDX, IDC_IPADDRESS1, m_UserIP);
	DDX_Control(pDX, IDC_IPADDRESS1, m_UserIPAddr);
}


BEGIN_MESSAGE_MAP(CAddUserDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddUserDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddUserDlg 消息处理程序


void CAddUserDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	UpdateData(TRUE);
	CString UserIP;
	m_UserIPAddr.GetWindowText(UserIP);
	//::MessageBoxA(::AfxGetMainWnd()->GetSafeHwnd(),UserIP,"asdfasdf",0);
	this->m_UserIP;
	Addfriend(UserIP);
	
	
	CDialogEx::OnOK();
}

void CAddUserDlg::Addfriend(CString strFriendIP) 
{
	/// 判断地址是否合法
	if( inet_addr( strFriendIP ) == INADDR_NONE || strFriendIP.IsEmpty() )
	{
		return;
	}

	/// 判断IP是否是自己IP
	CStringList m_strlstIP;
	char szHostName[128]; 
	if( gethostname( szHostName, 128 ) == 0 ) 
	{
		struct hostent * pHost;	 
		pHost = gethostbyname( szHostName );   
		for( int i = 0; pHost != NULL && pHost->h_addr_list[ i ] != NULL; i++ )   
		{ 
			LPCSTR pszIP = inet_ntoa( *( struct in_addr * )pHost->h_addr_list[ i ] ); 
			m_strlstIP.AddTail( pszIP );
		}
		m_strlstIP.AddTail( "127.0.0.1" );
		m_strlstIP.AddTail( "127.1" );
	}
	if( m_strlstIP.Find( strFriendIP ) )
	{
		MessageBox( "不能添加自己为联系人！", "添加联系人" );
		return;
	}

	/// 不能为广播地址
	if( strFriendIP.Right( 3 ) == "255" )
	{
		return;
	}

	/// 定义数据包
	DATAPACKET dataPacket;
	dataPacket.command = REQUEST_ADD;
	
	/// 设置请求的用户结构
	USER user;
	//memcpy( user.strName, m_strNickName.GetBuffer( MAXNICKNAMELENGTH + 1 ), MAXNICKNAMELENGTH + 1 );
	//m_strNickName.ReleaseBuffer();
	
	/// 分配空间
	UINT uDataLength = sizeof( DATAPACKET ) + sizeof( USER );
	BYTE *pSendData = new BYTE[ uDataLength ];
	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	memcpy( pSendData + sizeof( DATAPACKET ), &user, sizeof( USER ) );

	/// 发送请求
	//m_pLisSocket->SendTo( pSendData, uDataLength, DEFAULT_PORT, strFriendIP );

	delete pSendData;
}
