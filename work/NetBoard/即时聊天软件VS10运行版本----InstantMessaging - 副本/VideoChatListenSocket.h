#if !defined(AFX_VIDEOCHATLISTENSOCKET_H__0DA7D4C2_8E55_4196_93FF_442AFAAE286A__INCLUDED_)
#define AFX_VIDEOCHATLISTENSOCKET_H__0DA7D4C2_8E55_4196_93FF_442AFAAE286A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoChatListenSocket.h : header file
//

class CInstantMessagingDlg;

/////////////////////////////////////////////////////////////////////////////
// CVideoChatListenSocket command target

class CVideoChatListenSocket : public CSocket
{
// Attributes
private:
	CInstantMessagingDlg				*m_pMainDlg;			/// 主对话框指针

// Operations
public:
	CVideoChatListenSocket();
	virtual ~CVideoChatListenSocket();

	/// 带主对话框指针的构造函数
	CVideoChatListenSocket( CInstantMessagingDlg *pMainDlg ){ m_pMainDlg = pMainDlg; }

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoChatListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CVideoChatListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOCHATLISTENSOCKET_H__0DA7D4C2_8E55_4196_93FF_442AFAAE286A__INCLUDED_)
