
// MFCBoardClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBoardClient.h"
#include "MFCBoardClientDlg.h"
#include "afxdialogex.h"
#include "ConSrvDlg.h"
#include "WhiteBoardClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

DRAWINFO drinfo;        ///发送用的绘图信息记录单元。

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCBoardClientDlg 对话框




CMFCBoardClientDlg::CMFCBoardClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCBoardClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	/// 设置默认
	m_emTool		= PENCIL;
	m_nWidth		= WHITEBOARD_WIDTH_1;
	m_clDrawColor	= DEFAULT_WHITEBOARD_TOOL_COLOR;
}

void CMFCBoardClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDS_CONVAS, m_staticCanvas);
	DDX_Control(pDX, IDB_ERASER, m_btnEraser);
	DDX_Control(pDX, IDB_PENCIL, m_btnPencil);
	DDX_Control(pDX, IDB_LINE, m_btnLine);
	DDX_Control(pDX, IDB_RECTANGLE_EMPTY, m_btnRectangleEmpty);
	DDX_Control(pDX, IDB_RECTANGLE, m_btnRectangle);
	DDX_Control(pDX, IDB_ELLIPSE_EMPTY, m_btnEllipseEmpty);
	DDX_Control(pDX, IDB_ELLIPSE, m_btnEllipse);
	DDX_Control(pDX, IDS_COLOR, m_staticColor);
	DDX_Control(pDX, IDB_WIDTH_1, m_btnWidth1);
	DDX_Control(pDX, IDB_WIDTH_2, m_btnWidth2);
	DDX_Control(pDX, IDB_WIDTH_3, m_btnWidth3);
	DDX_Control(pDX, IDB_WIDTH_4, m_btnWidth4);
	DDX_Control(pDX, IDB_CLEAR, m_btnClear);
}

BEGIN_MESSAGE_MAP(CMFCBoardClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDB_ERASER, &CMFCBoardClientDlg::OnBnClickedEraser)
	ON_BN_CLICKED(IDB_PENCIL, &CMFCBoardClientDlg::OnBnClickedPencil)
	ON_BN_CLICKED(IDB_LINE, &CMFCBoardClientDlg::OnBnClickedLine)
	ON_BN_CLICKED(IDB_RECTANGLE_EMPTY, &CMFCBoardClientDlg::OnBnClickedRectangleEmpty)
	ON_BN_CLICKED(IDB_RECTANGLE, &CMFCBoardClientDlg::OnBnClickedRectangle)
	ON_BN_CLICKED(IDB_ELLIPSE_EMPTY, &CMFCBoardClientDlg::OnBnClickedEllipseEmpty)
	ON_BN_CLICKED(IDB_ELLIPSE, &CMFCBoardClientDlg::OnBnClickedEllipse)
	ON_BN_CLICKED(IDB_CLEAR, &CMFCBoardClientDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDB_WIDTH_1, &CMFCBoardClientDlg::OnBnClickedWidth1)
	ON_BN_CLICKED(IDB_WIDTH_2, &CMFCBoardClientDlg::OnBnClickedWidth2)
	ON_BN_CLICKED(IDB_WIDTH_3, &CMFCBoardClientDlg::OnBnClickedWidth3)
	ON_BN_CLICKED(IDB_WIDTH_4, &CMFCBoardClientDlg::OnBnClickedWidth4)
	ON_STN_CLICKED(IDS_COLOR, &CMFCBoardClientDlg::OnStnClickedColor)
	ON_WM_SIZING()
	ON_BN_CLICKED(IDB_CONNECT, &CMFCBoardClientDlg::OnBnClickedConnect)
    ON_COMMAND(IDM_CONNECT, &CMFCBoardClientDlg::OnMenuConnect)
    ON_BN_CLICKED(IDB_RESETSER, &CMFCBoardClientDlg::OnBnClickedResetser)
    ON_COMMAND(IDM_SETSER, &CMFCBoardClientDlg::OnSetser)
    ON_COMMAND(IDM_RESET, &CMFCBoardClientDlg::OnResetProg)
END_MESSAGE_MAP()


// CMFCBoardClientDlg 消息处理程序

BOOL CMFCBoardClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	Init();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCBoardClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCBoardClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	CPaintDC dc(this); // device context for painting
	
	CDC *pDC = m_staticColor.GetDC();
	CRect rect;
	m_staticColor.GetClientRect( &rect );
	rect.DeflateRect( 1, 1 );
	pDC->FillSolidRect( rect, m_clDrawColor );
	m_staticColor.ReleaseDC( pDC );	

	m_staticCanvas.Invalidate();	
}

void CMFCBoardClientDlg::Init()
{
	/// 获取主对话框
	//m_pMainDlg = ( CInstantMessagingDlg * )::AfxGetMainWnd();
	
	/// 设置橡皮檫的图标
	m_btnEraser.setBmp(	IDB_WHITEBOARD_ERASER_NORMAL,
		IDB_WHITEBOARD_ERASER_HOVER,
		IDB_WHITEBOARD_ERASER_DOWN,
		IDB_WHITEBOARD_ERASER_DISABLE );

	/// 设置画笔的图标
	m_btnPencil.setBmp(	IDB_WHITEBOARD_PENCIL_NORMAL,
		IDB_WHITEBOARD_PENCIL_HOVER,
		IDB_WHITEBOARD_PENCIL_DOWN,
		IDB_WHITEBOARD_PENCIL_DISABLE );

	/// 设置直线的图标
	m_btnLine.setBmp( IDB_WHITEBOARD_LINE_NORMAL,
		IDB_WHITEBOARD_LINE_HOVER,
		IDB_WHITEBOARD_LINE_DOWN,
		IDB_WHITEBOARD_LINE_DISABLE );

	/// 设置空心矩形的图标
	m_btnRectangleEmpty.setBmp(	IDB_WHITEBOARD_RECTANGLE_EMPTY_NORMAL,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_HOVER,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_DOWN,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_DISABLE );

	/// 设置实心矩形的图标
	m_btnRectangle.setBmp( IDB_WHITEBOARD_RECTANGLE_NORMAL,
		IDB_WHITEBOARD_RECTANGLE_HOVER,
		IDB_WHITEBOARD_RECTANGLE_DOWN,
		IDB_WHITEBOARD_RECTANGLE_DISABLE );

	/// 设置空心椭圆的图标
	m_btnEllipseEmpty.setBmp( IDB_WHITEBOARD_ELLIPSE_EMPTY_NORMAL,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_HOVER,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_DOWN,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_DISABLE );

	/// 设置实心椭圆的图标
	m_btnEllipse.setBmp( IDB_WHITEBOARD_ELLIPSE_NORMAL,
		IDB_WHITEBOARD_ELLIPSE_HOVER,
		IDB_WHITEBOARD_ELLIPSE_DOWN,
		IDB_WHITEBOARD_ELLIPSE_DISABLE );



	/// 设置线宽一的图标
	m_btnWidth1.setBmp( IDB_WHITEBOARD_WIDTH_1_NORMAL,
		IDB_WHITEBOARD_WIDTH_1_HOVER,
		IDB_WHITEBOARD_WIDTH_1_DOWN,
		IDB_WHITEBOARD_WIDTH_1_DISABLE );

	/// 设置线宽二的图标
	m_btnWidth2.setBmp( IDB_WHITEBOARD_WIDTH_2_NORMAL,
		IDB_WHITEBOARD_WIDTH_2_HOVER,
		IDB_WHITEBOARD_WIDTH_2_DOWN,
		IDB_WHITEBOARD_WIDTH_2_DISABLE );

	/// 设置线宽三的图标
	m_btnWidth3.setBmp( IDB_WHITEBOARD_WIDTH_3_NORMAL,
		IDB_WHITEBOARD_WIDTH_3_HOVER,
		IDB_WHITEBOARD_WIDTH_3_DOWN,
		IDB_WHITEBOARD_WIDTH_3_DISABLE );

	/// 设置线宽四的图标
	m_btnWidth4.setBmp( IDB_WHITEBOARD_WIDTH_4_NORMAL,
		IDB_WHITEBOARD_WIDTH_4_HOVER,
		IDB_WHITEBOARD_WIDTH_4_DOWN,
		IDB_WHITEBOARD_WIDTH_4_DISABLE );

	///设置清除图像按钮图标
	m_btnClear.setBmp( IDB_WHITEBOARD_CLEAR_NORMAL,
		IDB_WHITEBOARD_CLEAR_HOVER,
		IDB_WHITEBOARD_CLEAR_DOWN,
		IDB_WHITEBOARD_CLEAR_DISABLE );
	/// 设置选中的工具和线宽
	m_btnPencil.EnableWindow( FALSE );
	m_btnWidth1.EnableWindow( FALSE );

	// 初始化UDP套接字
	m_pWBCSocket = new CWhiteBoardClientSocket( (CMFCBoardClientDlg*)this ) ;
	m_pWBCSocket->Create( WHITEBOARD_CLIENT_PORT+10, SOCK_DGRAM );
    IsServer = WBNULL ;         /// 当前为初始状态
    ///初始化画图信息临时内存

    drinfo.nWidth = 1 ;

	/// 调整各控件的位置
	SetPosition();

	/// 设置画布的初始状态
	m_staticCanvas.SetTool( m_emTool );
	m_staticCanvas.SetWidth( m_nWidth );
	m_staticCanvas.SetColor( m_clDrawColor );
}

/// 调整各控件的位置
void CMFCBoardClientDlg::SetPosition()
{
	/// 控件未创建不调整
	if( !m_staticCanvas )
	{
		return ;
	}
	CRect rect;
	GetClientRect( &rect );

	CRect rectCanvas;
	m_staticCanvas.GetWindowRect( &rectCanvas );
	ScreenToClient( &rectCanvas );

	rectCanvas.right	= rect.right - 8;
	rectCanvas.bottom	= rect.bottom - 12;
	m_staticCanvas.MoveWindow( rectCanvas );
}	

void CMFCBoardClientDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	SetPosition();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCBoardClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCBoardClientDlg::OnBnClickedEraser()
{
	ResetTools();
	m_emTool = ERASER;
	m_btnEraser.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedPencil()
{
	ResetTools();
	m_emTool = PENCIL;
	m_btnPencil.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedLine()
{
	ResetTools();
	m_emTool = LINE;
	m_btnLine.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedRectangleEmpty()
{
	ResetTools();
	m_emTool = RECTANGLE_EMPTY;
	m_btnRectangleEmpty.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedRectangle()
{
	ResetTools();
	m_emTool = RECTANGLE;
	m_btnRectangle.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedEllipseEmpty()
{
	ResetTools();
	m_emTool = ELLIPSE_EMPTY;
	m_btnEllipseEmpty.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedEllipse()
{
	ResetTools();
	m_emTool = ELLIPSE;
	m_btnEllipse.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedClear()
{
	m_staticCanvas.ClearShape();
    m_emTool = CLEARGRAPHICS ;
    SendDrawInfoToServer( CPoint(0,0), CPoint(0,0) );
	ResetTools();
	m_emTool = PENCIL;
	m_btnPencil.EnableWindow( FALSE );
	m_staticCanvas.SetTool( m_emTool );
}


void CMFCBoardClientDlg::OnBnClickedWidth1()
{
	ResetWidth();
	m_nWidth = WHITEBOARD_WIDTH_1;
	m_btnWidth1.EnableWindow( FALSE );
	m_staticCanvas.SetWidth( m_nWidth );
}


void CMFCBoardClientDlg::OnBnClickedWidth2()
{
	ResetWidth();
	m_nWidth = WHITEBOARD_WIDTH_2;
	m_btnWidth2.EnableWindow( FALSE );
	m_staticCanvas.SetWidth( m_nWidth );
}


void CMFCBoardClientDlg::OnBnClickedWidth3()
{
	ResetWidth();
	m_nWidth = WHITEBOARD_WIDTH_3;
	m_btnWidth3.EnableWindow( FALSE );
	m_staticCanvas.SetWidth( m_nWidth );
}


void CMFCBoardClientDlg::OnBnClickedWidth4()
{
	ResetWidth();
	m_nWidth = WHITEBOARD_WIDTH_4;
	m_btnWidth4.EnableWindow( FALSE );
	m_staticCanvas.SetWidth( m_nWidth );
}


void CMFCBoardClientDlg::OnStnClickedColor()
{
	/// 弹出颜色获对话框
	CColorDialog clDlg;
	clDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	clDlg.m_cc.rgbResult = m_clDrawColor;
	if( IDCANCEL == clDlg.DoModal() )
	{
		return ;
	}

	/// 设置并画出
	m_clDrawColor = clDlg.GetColor();
	CDC *pDC = m_staticColor.GetDC();
	CRect rect;
	m_staticColor.GetClientRect( &rect );
	rect.DeflateRect( 1, 1 );
	pDC->FillSolidRect( rect, m_clDrawColor );
	m_staticColor.ReleaseDC( pDC );
	m_staticCanvas.SetColor( m_clDrawColor );
}


/// 恢复工具的状态
void CMFCBoardClientDlg::ResetTools()
{
	switch( m_emTool )
	{
	case ERASER:
		m_btnEraser.SetNormal();
		break;
	case PENCIL:
		m_btnPencil.SetNormal();
		break;
	case LINE:
		m_btnLine.SetNormal();
		break;
	case RECTANGLE_EMPTY:
		m_btnRectangleEmpty.SetNormal();
		break;
	case RECTANGLE:
		m_btnRectangle.SetNormal();
		break;
	case ELLIPSE_EMPTY:
		m_btnEllipseEmpty.SetNormal();
		break;
	case ELLIPSE:
		m_btnEllipse.SetNormal();
		break;
    case CLEARGRAPHICS:
		m_btnEraser.SetNormal();
		m_btnPencil.SetNormal();
		m_btnLine.SetNormal();
		m_btnRectangleEmpty.SetNormal();
		m_btnRectangle.SetNormal();
		m_btnEllipseEmpty.SetNormal();
		m_btnEllipse.SetNormal();
		break;
	default:
		break;
	}
}

///	恢复线宽
void CMFCBoardClientDlg::ResetWidth()
{
	switch( m_nWidth )
	{
	case WHITEBOARD_WIDTH_1:
		m_btnWidth1.SetNormal();
		break;
	case WHITEBOARD_WIDTH_2:
		m_btnWidth2.SetNormal();
		break;
	case WHITEBOARD_WIDTH_3:
		m_btnWidth3.SetNormal();
		break;
	case WHITEBOARD_WIDTH_4:
		m_btnWidth4.SetNormal();
		break;
	default:
		break;
	}
}

/// 限制窗口大小
void CMFCBoardClientDlg::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);
	
	/// 限制窗口的最小
	switch( fwSide )
	{
	case 1:
		pRect->left = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->right - WHITEBOARD_MIN_WIDTH : pRect->left;
		break;
	case 2:
		pRect->right = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->left + WHITEBOARD_MIN_WIDTH : pRect->right;
		break;
	case 3:
		pRect->top = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->bottom - WHITEBOARD_MIN_HEIGHT : pRect->top;
		break;
	case 4:
		pRect->left = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->right - WHITEBOARD_MIN_WIDTH : pRect->left;
		pRect->top = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->bottom - WHITEBOARD_MIN_HEIGHT : pRect->top;
		break;
	case 5:
		pRect->right = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->left + WHITEBOARD_MIN_WIDTH : pRect->right;
		pRect->top = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->bottom - WHITEBOARD_MIN_HEIGHT : pRect->top;
		break;
	case 6:
		pRect->bottom = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->top + WHITEBOARD_MIN_HEIGHT : pRect->bottom;
		break;
	case 7:
		pRect->left = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->right - WHITEBOARD_MIN_WIDTH : pRect->left;
		pRect->bottom = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->top + WHITEBOARD_MIN_HEIGHT : pRect->bottom;
		break;
	case 8:
		pRect->right = pRect->right - pRect->left < WHITEBOARD_MIN_WIDTH ? pRect->left + WHITEBOARD_MIN_WIDTH : pRect->right;
		pRect->bottom = pRect->bottom - pRect->top < WHITEBOARD_MIN_HEIGHT ? pRect->top + WHITEBOARD_MIN_HEIGHT : pRect->bottom;
		break;
	default:
		break;
	}	
}


/// 添加服务器和自己到用户列表框
void CMFCBoardClientDlg::AcceptAddRequest(  const USER userServer )
{
	///// 设置服务器IP
	//m_strServerIP = userServer.strIP;

	///// 自己的USER
	//USER userSelf;
	//memcpy( userSelf.strName , userSelf.strIP , MAXNICKNAMELENGTH + 1 );

	///// 接受请求加入白板
	//SendUserCommandToIP( WHITEBOARD_ADDREQUEST_ALLOW, m_strServerIP , WHITEBOARD_SERVER_PORT, &userSelf );
}

/// 被踢出白板
void CMFCBoardClientDlg::Kicked()
{
	///// 关闭UDP套接字
	//m_pWBCSocket->Close();

	///// 提示
	//MessageBox( "你被创建者踢出来了白板！", "白板" );

	///// 清除画布
	//m_staticCanvas.ClearCanvas();
	//
	///// 设置默认
	//ResetTools();
	//ResetWidth();
	//m_emTool		= PENCIL;
	//m_nWidth		= WHITEBOARD_WIDTH_1;
	//m_clDrawColor	= DEFAULT_WHITEBOARD_TOOL_COLOR;

	///// 关闭对话框
	//DestroyWindow();
}

/// 服务器关闭
void CMFCBoardClientDlg::ServerClosed()
{
	///// 关闭UDP套接字
	//m_pWBCSocket->Close();

	///// 提示
	//MessageBox( "创建者关闭了白板！", "白板" );

	///// 清除画布
	//m_staticCanvas.ClearCanvas();
	//
	///// 设置默认
	//ResetTools();
	//ResetWidth();
	//m_emTool		= PENCIL;
	//m_nWidth		= WHITEBOARD_WIDTH_1;
	//m_clDrawColor	= DEFAULT_WHITEBOARD_TOOL_COLOR;
	//
	///// 关闭对话框
	//DestroyWindow();
}

/// 接收屏幕数据
void CMFCBoardClientDlg::ReceiveDrawData( char *pReceivedData )
{
	DRAWINFO drawInfo;
	memcpy( &drawInfo, pReceivedData + sizeof( DATAPACKET ), sizeof( DRAWINFO ) );
	m_staticCanvas.Draw( drawInfo );
}


/// 从UDP中接收数据
void CMFCBoardClientDlg::OnReceive()
{
	/// 接收数据
	CString strIP = "0.0.0.0";
	UINT uPort = 8007;
	char szReceive[ MAXDATAPACKETLENGTH ];
	m_pWBCSocket->ReceiveFrom( szReceive, MAXDATAPACKETLENGTH, strIP, uPort );
    
    ///判断当前是否是服务器
    if( WBCLIENT != IsServer)
    {
        if( NULL == IsServer ) 
        {
            OnSetser();
        }
        if( WBSERVER == IsServer ) 
        {
            int index;
            for( index = 0; index<m_arrClntIP.GetSize(); index++ )
            {
                if( strIP == m_arrClntIP[ index ] ) break;
            }/// for
            if( index == m_arrClntIP.GetSize() )
                m_arrClntIP.InsertAt( index, strIP );
        }/// if( WBSERVER == IsServer ) 

    }/// if( WBCLIENT != IsServer)
    
    /// 装配数据包
	DATAPACKET dataPacket;
	memcpy( &dataPacket, szReceive, sizeof( DATAPACKET ) );
	
	/// 根据命令进行不同的处理
	switch( dataPacket.command )
	{
	case WHITEBOARD_SERVER_CLOSED:							/// 白板服务器关闭
		ServerClosed();
		break;
	case WHITEBOARD_CLIENT_KICKED:							/// 客户端被踢
		Kicked();
		break;
	case WHITEBOARD_DRAWINFO:						    	///	白板服务器的画图数据
		{
            if ( WBNULL == IsServer || WBCLIENT == IsServer )
                ReceiveDrawData( szReceive );
            else if ( WBSERVER == IsServer )
            {
                //memcpy( &user, szReceive + sizeof( DATAPACKET ), sizeof( USER ) );
		        //memcpy( user.strIP, strIP.GetBuffer( 16 ), 16 );
		        //strIP.ReleaseBuffer();
		        ReceiveClientDrawInfo( szReceive, strIP );
            }
        }
		break;
	default:
		break;
	}
}


/// 向指定IP、PORT发送指定数据
void CMFCBoardClientDlg::SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT uPort, const USER *pUser )
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
	m_pWBCSocket->SendTo( pSendData, uDataLength, uPort, szIP );
	
	delete pSendData;
}

/// 将画图信息发送到服务器
void CMFCBoardClientDlg::SendDrawInfoToServer(  const CPoint ptStart, const CPoint ptEnd )
{
	DRAWINFO drawInfo;
	drawInfo.color		= m_clDrawColor;
	drawInfo.nWidth		= m_nWidth;
	drawInfo.tool		= m_emTool;
	drawInfo.ptStart	= ptStart;
	drawInfo.ptEnd		= ptEnd;

	DATAPACKET dataPacket;
	dataPacket.command	= WHITEBOARD_DRAWINFO;

	UINT uDataLength	= sizeof( dataPacket ) + sizeof( DRAWINFO );
	BYTE *pSendData		= new BYTE[ uDataLength ];

	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	memcpy( pSendData + sizeof( DATAPACKET ), &drawInfo, sizeof( DRAWINFO ) );
	
	/// 发送数据
    //m_strServerIP = "192.168.1.102" ;
	m_pWBCSocket->SendTo( pSendData, uDataLength, WHITEBOARD_SERVER_PORT+11, m_strServerIP );
	
	delete [] pSendData;
}

/// 发送自己的绘画数据给所有客户端
void CMFCBoardClientDlg::SendDrawInfoToAllUser( const CPoint ptStart, const CPoint ptEnd )
{
	DRAWINFO drawInfo;
	drawInfo.color		= m_clDrawColor;
	drawInfo.nWidth		= m_nWidth;
	drawInfo.tool		= m_emTool;
	drawInfo.ptStart	= ptStart;
	drawInfo.ptEnd		= ptEnd;

	DATAPACKET dataPacket;
	dataPacket.command	= WHITEBOARD_DRAWINFO;

	UINT uDataLength	= sizeof( dataPacket ) + sizeof( DRAWINFO );
	BYTE *pSendData		= new BYTE[ uDataLength ];

	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	memcpy( pSendData + sizeof( DATAPACKET ), &drawInfo, sizeof( DRAWINFO ) );

	for( int nIndex = 0; nIndex < m_arrClntIP.GetSize(); nIndex++ )
	{
		/// 发送数据
		m_pWBCSocket->SendTo( pSendData, uDataLength, WHITEBOARD_CLIENT_PORT+10, 
			m_arrClntIP.GetAt( nIndex ) );
	}

	delete [] pSendData;
}

/// 接收客户端的绘图信息
void CMFCBoardClientDlg::ReceiveClientDrawInfo( char *pReceivedData, const CString strIP )
{
	/// 得到绘图信息
	DRAWINFO drawInfo;
	memcpy( &drawInfo, pReceivedData + sizeof( DATAPACKET ), sizeof( DRAWINFO ) );

	/// 服务器绘图
	m_staticCanvas.Draw( drawInfo );

	/// 将绘图信息传送给客户端
	for( int nIndex = 0; nIndex < m_arrClntIP.GetSize(); nIndex++ )
	{
		if( 0 != strcmp( strIP, m_arrClntIP.GetAt( nIndex ) ) )
		{
			/// 发送数据
			m_pWBCSocket->SendTo( pReceivedData, sizeof( DATAPACKET ) + sizeof( DRAWINFO ), 
				WHITEBOARD_CLIENT_PORT+10, 
			m_arrClntIP.GetAt( nIndex ) );
		}
	}
}

///弹出连接服务器窗口
void CMFCBoardClientDlg::OnBnClickedConnect()
{
	// TODO: 在此添加控件通知处理程序代码
	ConSrvDlg csdlg ;
	csdlg.DoModal();
    m_strServerIP = csdlg.GetSerIP();
}

///菜单连接服务器


void CMFCBoardClientDlg::OnMenuConnect()
{
    // TODO: 在此添加命令处理程序代码
    if( WBSERVER == IsServer ) 
    {
        MessageBox( "当前为服务器端！", "WhiteBoardServer" );
        return;
    }
    OnBnClickedConnect();
    if( m_strServerIP )
    {
        ///设置窗口为服务器
        ::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoardClient" );
        IsServer = WBCLIENT ;
    }
    else
    {
        ///保持原状
        return ;
    }
        
}


void CMFCBoardClientDlg::OnBnClickedResetser()
{
    // TODO: 在此添加控件通知处理程序代码
    ///地址记录链表清除
    m_arrClntIP.RemoveAll();
    ///当前IP清零
    m_strServerIP = "";
    //::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoard" );
    //IsServer = WBNULL ;
    //( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_HIDE );
}


void CMFCBoardClientDlg::OnSetser()
{
    // TODO: 在此添加命令处理程序代码
    IsServer = WBSERVER;
    ::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoardServer" );
    ( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_SHOW );
}


void CMFCBoardClientDlg::OnResetProg()
{
    // TODO: 在此添加命令处理程序代码
    m_arrClntIP.RemoveAll();
    m_strServerIP = "";
    IsServer = WBNULL;
    SetWindowTextA( "WhiteBoard" );
    ( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_HIDE );
}
