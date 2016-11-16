#if !defined(AFX_SHARESCREENCLIENTDLG_H__0159A38F_FFF7_4D90_A7E9_375665173D32__INCLUDED_)
#define AFX_SHARESCREENCLIENTDLG_H__0159A38F_FFF7_4D90_A7E9_375665173D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShareScreenClientDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientDlg dialog

class CInstantMessagingDlg;
class CShareScreenClientSocket;

class CShareScreenClientDlg : public CDialog
{
// Construction
public:
	CShareScreenClientDlg(CWnd* pParent = NULL);   // standard constructor

private:
	/// 初始化
	void Init();

	/// 调整各控件的位置
	void SetPosition();

	/// 向指定IP、PORT发送指定用户和数据
	void SendUserCommandToIP( CONTROLCOMMAND command, LPCSTR szIP, UINT uPort, const USER *pUser );

	/// 服务器关闭
	void ServerClosed();

	/// 被踢出共享屏幕
	void Kicked();

	/// 接收屏幕数据
	void ReceiveScreenData( BYTE *pReceivedData );

private:
	CInstantMessagingDlg	*m_pMainDlg;					/// 主对话框
	CImageList				m_imageList;					/// 头像图像列表
	CShareScreenClientSocket
							*m_pSSCSocket;					/// 共享屏幕客户端socket
	CString					m_strServerIP;					/// 服务器IP

	int						m_nServerScreenCX;				/// 服务器屏幕的宽
	int						m_nServerScreenCY;				/// 服务器屏幕的高

public:
	/// 接收网络数据
	void OnReceive();

	/// 返回对应的服务器IP
	CString GetServerIP(){ return m_strServerIP; }

	/// 同意添加请求
	void AcceptAddRequest( const USER userServer );

// Dialog Data
	//{{AFX_DATA(CShareScreenClientDlg)
	enum { IDD = IDD_SHARESCREEN_CLIENT };
	CScrollBar	m_sbHorizontal;
	CScrollBar	m_sbVertical;
	CStatic	m_staticScreen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareScreenClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShareScreenClientDlg)
	afx_msg void OnOk();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARESCREENCLIENTDLG_H__0159A38F_FFF7_4D90_A7E9_375665173D32__INCLUDED_)
