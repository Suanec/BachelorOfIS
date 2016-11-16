#if !defined(AFX_SHARESCREENSERVERSOCKET_H__371F72FD_74E3_4A17_938D_A85B3317F74A__INCLUDED_)
#define AFX_SHARESCREENSERVERSOCKET_H__371F72FD_74E3_4A17_938D_A85B3317F74A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShareScreenServerSocket.h : header file
//

#include "ShareScreenServerDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerSocket command target

class CShareScreenServerSocket : public CSocket
{
// Attributes
private:
	CShareScreenServerDlg		*m_pSCServerDlg;				/// 共享屏幕服务器对话框指针

// Operations
public:
	CShareScreenServerSocket();
	virtual ~CShareScreenServerSocket();

	/// 带共享屏幕服务器对话框指针的构造函数
	CShareScreenServerSocket( CShareScreenServerDlg * pSCServerDlg );

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareScreenServerSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CShareScreenServerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARESCREENSERVERSOCKET_H__371F72FD_74E3_4A17_938D_A85B3317F74A__INCLUDED_)
