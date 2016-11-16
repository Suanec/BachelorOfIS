
// MFCBoardClientDlg.cpp : ʵ���ļ�
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

DRAWINFO drinfo;        ///�����õĻ�ͼ��Ϣ��¼��Ԫ��

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCBoardClientDlg �Ի���




CMFCBoardClientDlg::CMFCBoardClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCBoardClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	/// ����Ĭ��
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


// CMFCBoardClientDlg ��Ϣ�������

BOOL CMFCBoardClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	Init();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCBoardClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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
	/// ��ȡ���Ի���
	//m_pMainDlg = ( CInstantMessagingDlg * )::AfxGetMainWnd();
	
	/// ������Ƥ�ߵ�ͼ��
	m_btnEraser.setBmp(	IDB_WHITEBOARD_ERASER_NORMAL,
		IDB_WHITEBOARD_ERASER_HOVER,
		IDB_WHITEBOARD_ERASER_DOWN,
		IDB_WHITEBOARD_ERASER_DISABLE );

	/// ���û��ʵ�ͼ��
	m_btnPencil.setBmp(	IDB_WHITEBOARD_PENCIL_NORMAL,
		IDB_WHITEBOARD_PENCIL_HOVER,
		IDB_WHITEBOARD_PENCIL_DOWN,
		IDB_WHITEBOARD_PENCIL_DISABLE );

	/// ����ֱ�ߵ�ͼ��
	m_btnLine.setBmp( IDB_WHITEBOARD_LINE_NORMAL,
		IDB_WHITEBOARD_LINE_HOVER,
		IDB_WHITEBOARD_LINE_DOWN,
		IDB_WHITEBOARD_LINE_DISABLE );

	/// ���ÿ��ľ��ε�ͼ��
	m_btnRectangleEmpty.setBmp(	IDB_WHITEBOARD_RECTANGLE_EMPTY_NORMAL,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_HOVER,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_DOWN,
		IDB_WHITEBOARD_RECTANGLE_EMPTY_DISABLE );

	/// ����ʵ�ľ��ε�ͼ��
	m_btnRectangle.setBmp( IDB_WHITEBOARD_RECTANGLE_NORMAL,
		IDB_WHITEBOARD_RECTANGLE_HOVER,
		IDB_WHITEBOARD_RECTANGLE_DOWN,
		IDB_WHITEBOARD_RECTANGLE_DISABLE );

	/// ���ÿ�����Բ��ͼ��
	m_btnEllipseEmpty.setBmp( IDB_WHITEBOARD_ELLIPSE_EMPTY_NORMAL,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_HOVER,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_DOWN,
		IDB_WHITEBOARD_ELLIPSE_EMPTY_DISABLE );

	/// ����ʵ����Բ��ͼ��
	m_btnEllipse.setBmp( IDB_WHITEBOARD_ELLIPSE_NORMAL,
		IDB_WHITEBOARD_ELLIPSE_HOVER,
		IDB_WHITEBOARD_ELLIPSE_DOWN,
		IDB_WHITEBOARD_ELLIPSE_DISABLE );



	/// �����߿�һ��ͼ��
	m_btnWidth1.setBmp( IDB_WHITEBOARD_WIDTH_1_NORMAL,
		IDB_WHITEBOARD_WIDTH_1_HOVER,
		IDB_WHITEBOARD_WIDTH_1_DOWN,
		IDB_WHITEBOARD_WIDTH_1_DISABLE );

	/// �����߿����ͼ��
	m_btnWidth2.setBmp( IDB_WHITEBOARD_WIDTH_2_NORMAL,
		IDB_WHITEBOARD_WIDTH_2_HOVER,
		IDB_WHITEBOARD_WIDTH_2_DOWN,
		IDB_WHITEBOARD_WIDTH_2_DISABLE );

	/// �����߿�����ͼ��
	m_btnWidth3.setBmp( IDB_WHITEBOARD_WIDTH_3_NORMAL,
		IDB_WHITEBOARD_WIDTH_3_HOVER,
		IDB_WHITEBOARD_WIDTH_3_DOWN,
		IDB_WHITEBOARD_WIDTH_3_DISABLE );

	/// �����߿��ĵ�ͼ��
	m_btnWidth4.setBmp( IDB_WHITEBOARD_WIDTH_4_NORMAL,
		IDB_WHITEBOARD_WIDTH_4_HOVER,
		IDB_WHITEBOARD_WIDTH_4_DOWN,
		IDB_WHITEBOARD_WIDTH_4_DISABLE );

	///�������ͼ��ťͼ��
	m_btnClear.setBmp( IDB_WHITEBOARD_CLEAR_NORMAL,
		IDB_WHITEBOARD_CLEAR_HOVER,
		IDB_WHITEBOARD_CLEAR_DOWN,
		IDB_WHITEBOARD_CLEAR_DISABLE );
	/// ����ѡ�еĹ��ߺ��߿�
	m_btnPencil.EnableWindow( FALSE );
	m_btnWidth1.EnableWindow( FALSE );

	// ��ʼ��UDP�׽���
	m_pWBCSocket = new CWhiteBoardClientSocket( (CMFCBoardClientDlg*)this ) ;
	m_pWBCSocket->Create( WHITEBOARD_CLIENT_PORT+10, SOCK_DGRAM );
    IsServer = WBNULL ;         /// ��ǰΪ��ʼ״̬
    ///��ʼ����ͼ��Ϣ��ʱ�ڴ�

    drinfo.nWidth = 1 ;

	/// �������ؼ���λ��
	SetPosition();

	/// ���û����ĳ�ʼ״̬
	m_staticCanvas.SetTool( m_emTool );
	m_staticCanvas.SetWidth( m_nWidth );
	m_staticCanvas.SetColor( m_clDrawColor );
}

/// �������ؼ���λ��
void CMFCBoardClientDlg::SetPosition()
{
	/// �ؼ�δ����������
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	/// ������ɫ��Ի���
	CColorDialog clDlg;
	clDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	clDlg.m_cc.rgbResult = m_clDrawColor;
	if( IDCANCEL == clDlg.DoModal() )
	{
		return ;
	}

	/// ���ò�����
	m_clDrawColor = clDlg.GetColor();
	CDC *pDC = m_staticColor.GetDC();
	CRect rect;
	m_staticColor.GetClientRect( &rect );
	rect.DeflateRect( 1, 1 );
	pDC->FillSolidRect( rect, m_clDrawColor );
	m_staticColor.ReleaseDC( pDC );
	m_staticCanvas.SetColor( m_clDrawColor );
}


/// �ָ����ߵ�״̬
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

///	�ָ��߿�
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

/// ���ƴ��ڴ�С
void CMFCBoardClientDlg::OnSizing(UINT fwSide, LPRECT pRect) 
{
	CDialog::OnSizing(fwSide, pRect);
	
	/// ���ƴ��ڵ���С
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


/// ��ӷ��������Լ����û��б��
void CMFCBoardClientDlg::AcceptAddRequest(  const USER userServer )
{
	///// ���÷�����IP
	//m_strServerIP = userServer.strIP;

	///// �Լ���USER
	//USER userSelf;
	//memcpy( userSelf.strName , userSelf.strIP , MAXNICKNAMELENGTH + 1 );

	///// �����������װ�
	//SendUserCommandToIP( WHITEBOARD_ADDREQUEST_ALLOW, m_strServerIP , WHITEBOARD_SERVER_PORT, &userSelf );
}

/// ���߳��װ�
void CMFCBoardClientDlg::Kicked()
{
	///// �ر�UDP�׽���
	//m_pWBCSocket->Close();

	///// ��ʾ
	//MessageBox( "�㱻�������߳����˰װ壡", "�װ�" );

	///// �������
	//m_staticCanvas.ClearCanvas();
	//
	///// ����Ĭ��
	//ResetTools();
	//ResetWidth();
	//m_emTool		= PENCIL;
	//m_nWidth		= WHITEBOARD_WIDTH_1;
	//m_clDrawColor	= DEFAULT_WHITEBOARD_TOOL_COLOR;

	///// �رնԻ���
	//DestroyWindow();
}

/// �������ر�
void CMFCBoardClientDlg::ServerClosed()
{
	///// �ر�UDP�׽���
	//m_pWBCSocket->Close();

	///// ��ʾ
	//MessageBox( "�����߹ر��˰װ壡", "�װ�" );

	///// �������
	//m_staticCanvas.ClearCanvas();
	//
	///// ����Ĭ��
	//ResetTools();
	//ResetWidth();
	//m_emTool		= PENCIL;
	//m_nWidth		= WHITEBOARD_WIDTH_1;
	//m_clDrawColor	= DEFAULT_WHITEBOARD_TOOL_COLOR;
	//
	///// �رնԻ���
	//DestroyWindow();
}

/// ������Ļ����
void CMFCBoardClientDlg::ReceiveDrawData( char *pReceivedData )
{
	DRAWINFO drawInfo;
	memcpy( &drawInfo, pReceivedData + sizeof( DATAPACKET ), sizeof( DRAWINFO ) );
	m_staticCanvas.Draw( drawInfo );
}


/// ��UDP�н�������
void CMFCBoardClientDlg::OnReceive()
{
	/// ��������
	CString strIP = "0.0.0.0";
	UINT uPort = 8007;
	char szReceive[ MAXDATAPACKETLENGTH ];
	m_pWBCSocket->ReceiveFrom( szReceive, MAXDATAPACKETLENGTH, strIP, uPort );
    
    ///�жϵ�ǰ�Ƿ��Ƿ�����
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
    
    /// װ�����ݰ�
	DATAPACKET dataPacket;
	memcpy( &dataPacket, szReceive, sizeof( DATAPACKET ) );
	
	/// ����������в�ͬ�Ĵ���
	switch( dataPacket.command )
	{
	case WHITEBOARD_SERVER_CLOSED:							/// �װ�������ر�
		ServerClosed();
		break;
	case WHITEBOARD_CLIENT_KICKED:							/// �ͻ��˱���
		Kicked();
		break;
	case WHITEBOARD_DRAWINFO:						    	///	�װ�������Ļ�ͼ����
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


/// ��ָ��IP��PORT����ָ������
void CMFCBoardClientDlg::SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT uPort, const USER *pUser )
{
	DATAPACKET dataPacket;
	dataPacket.command	= command;
	
	/// ����ռ�
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
	
	/// ��������
	m_pWBCSocket->SendTo( pSendData, uDataLength, uPort, szIP );
	
	delete pSendData;
}

/// ����ͼ��Ϣ���͵�������
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
	
	/// ��������
    //m_strServerIP = "192.168.1.102" ;
	m_pWBCSocket->SendTo( pSendData, uDataLength, WHITEBOARD_SERVER_PORT+11, m_strServerIP );
	
	delete [] pSendData;
}

/// �����Լ��Ļ滭���ݸ����пͻ���
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
		/// ��������
		m_pWBCSocket->SendTo( pSendData, uDataLength, WHITEBOARD_CLIENT_PORT+10, 
			m_arrClntIP.GetAt( nIndex ) );
	}

	delete [] pSendData;
}

/// ���տͻ��˵Ļ�ͼ��Ϣ
void CMFCBoardClientDlg::ReceiveClientDrawInfo( char *pReceivedData, const CString strIP )
{
	/// �õ���ͼ��Ϣ
	DRAWINFO drawInfo;
	memcpy( &drawInfo, pReceivedData + sizeof( DATAPACKET ), sizeof( DRAWINFO ) );

	/// ��������ͼ
	m_staticCanvas.Draw( drawInfo );

	/// ����ͼ��Ϣ���͸��ͻ���
	for( int nIndex = 0; nIndex < m_arrClntIP.GetSize(); nIndex++ )
	{
		if( 0 != strcmp( strIP, m_arrClntIP.GetAt( nIndex ) ) )
		{
			/// ��������
			m_pWBCSocket->SendTo( pReceivedData, sizeof( DATAPACKET ) + sizeof( DRAWINFO ), 
				WHITEBOARD_CLIENT_PORT+10, 
			m_arrClntIP.GetAt( nIndex ) );
		}
	}
}

///�������ӷ���������
void CMFCBoardClientDlg::OnBnClickedConnect()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ConSrvDlg csdlg ;
	csdlg.DoModal();
    m_strServerIP = csdlg.GetSerIP();
}

///�˵����ӷ�����


void CMFCBoardClientDlg::OnMenuConnect()
{
    // TODO: �ڴ���������������
    if( WBSERVER == IsServer ) 
    {
        MessageBox( "��ǰΪ�������ˣ�", "WhiteBoardServer" );
        return;
    }
    OnBnClickedConnect();
    if( m_strServerIP )
    {
        ///���ô���Ϊ������
        ::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoardClient" );
        IsServer = WBCLIENT ;
    }
    else
    {
        ///����ԭ״
        return ;
    }
        
}


void CMFCBoardClientDlg::OnBnClickedResetser()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    ///��ַ��¼�������
    m_arrClntIP.RemoveAll();
    ///��ǰIP����
    m_strServerIP = "";
    //::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoard" );
    //IsServer = WBNULL ;
    //( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_HIDE );
}


void CMFCBoardClientDlg::OnSetser()
{
    // TODO: �ڴ���������������
    IsServer = WBSERVER;
    ::SetWindowTextA( this->GetSafeHwnd(), "WhiteBoardServer" );
    ( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_SHOW );
}


void CMFCBoardClientDlg::OnResetProg()
{
    // TODO: �ڴ���������������
    m_arrClntIP.RemoveAll();
    m_strServerIP = "";
    IsServer = WBNULL;
    SetWindowTextA( "WhiteBoard" );
    ( this->GetDlgItem( IDB_RESETSER ) )->ShowWindow( SW_HIDE );
}
