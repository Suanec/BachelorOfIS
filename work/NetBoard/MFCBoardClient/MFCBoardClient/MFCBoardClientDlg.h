
// MFCBoardClientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "resource.h"
#include "AdvButton.h"
//#include "WhiteBoardClientSocket.h"
#include "canvasstatic.h"

class CWhiteBoardClientSocket;
// CMFCBoardClientDlg 对话框
class CMFCBoardClientDlg : public CDialogEx
{
// 构造
public:
	CMFCBoardClientDlg(CWnd* pParent = NULL);	// 标准构造函数
private:
	/// 初始化工作
	void Init();
	
	/// 向指定IP、PORT发送指定用户和数据
	void SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT nPort, const USER *pUser );
	
	/// 调整各控件的位置
	void SetPosition();
	
	/// 恢复工具的状态
	void ResetTools();
	
	///	恢复线宽
	void ResetWidth();

	/// 服务器关闭
	void ServerClosed();

	/// 被踢出共享屏幕
	void Kicked();

	/// 接收绘画数据
	void ReceiveDrawData( char *pReceivedData );

private:
	CMFCBoardClientDlg  	*m_pMainDlg;		/// 主对话框
	//CImageList				m_imageList;		/// 头像图像列表
	CString					m_strServerIP;		/// 服务器IP
	CWhiteBoardClientSocket	
							*m_pWBCSocket;		/// 白板客户端socket
	
	TOOL					m_emTool;			/// 工具
	int						m_nWidth;			/// 线宽
	COLORREF				m_clDrawColor;		/// 颜色
	//CWhiteBoardClientSocket *m_pSkt;	    	/// 白板客户端Socket
public:
	/// 接收网络数据
	void OnReceive();

	/// 返回对应的服务器IP
	CString GetServerIP(){ return m_strServerIP; }

    ///发送绘图信息给所有用户
    void SendDrawInfoToAllUser( const CPoint ptStart, const CPoint ptEnd );

    ///接收客户端绘图信息
    void ReceiveClientDrawInfo( char *pReceivedData, const CString strIP );


	/// 同意添加请求
	void AcceptAddRequest( const USER userServer );

	/// 将画图信息发送到服务器
	void SendDrawInfoToServer( const CPoint ptStart, const CPoint ptEnd );

// 对话框数据
	enum { IDD = IDD_MFCBOARDCLIENT_DIALOG };

    
    ///判断是否是服务器枚举实例
    ISSERVER                IsServer;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

    ///保存当前客户端IP地址。
    CArray< CString ,CString >              m_arrClntIP;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CCanvasStatic m_staticCanvas;
	afx_msg void OnBnClickedEraser(); 
	afx_msg void OnBnClickedPencil();
	afx_msg void OnBnClickedLine();
	afx_msg void OnBnClickedRectangleEmpty();
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedEllipseEmpty();
	afx_msg void OnBnClickedEllipse();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedWidth1();
	afx_msg void OnBnClickedWidth2();
	afx_msg void OnBnClickedWidth3();
	afx_msg void OnBnClickedWidth4();
	CAdvButton m_btnEraser;
	CAdvButton m_btnPencil;
	CAdvButton m_btnLine;
	CAdvButton m_btnRectangleEmpty;
	CAdvButton m_btnRectangle;
	CAdvButton m_btnEllipseEmpty;
	CAdvButton m_btnEllipse;
	CStatic    m_staticColor;
	CAdvButton m_btnWidth1;
	CAdvButton m_btnWidth2;
	CAdvButton m_btnWidth3;
	CAdvButton m_btnWidth4;

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnStnClickedColor();
	CAdvButton   m_btnClear;
	afx_msg void OnBnClickedConnect();
    afx_msg void OnMenuConnect();
    afx_msg void OnBnClickedResetser();
    afx_msg void OnSetser();
    afx_msg void OnResetProg();
};
