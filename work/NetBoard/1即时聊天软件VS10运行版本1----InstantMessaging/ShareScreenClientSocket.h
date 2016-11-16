#if !defined(AFX_SHARESCREENCLIENTSOCKET_H__CD4473AB_86A1_40D5_AFC6_67C5F3D11792__INCLUDED_)
#define AFX_SHARESCREENCLIENTSOCKET_H__CD4473AB_86A1_40D5_AFC6_67C5F3D11792__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShareScreenClientSocket.h : header file
//

#include "ShareScreenClientDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientSocket command target

class CShareScreenClientSocket : public CSocket
{
// Attributes
private:
	CShareScreenClientDlg		*m_pSCClientDlg;				/// 共享屏幕客户端对话框指针

// Operations
public:
	CShareScreenClientSocket();
	virtual ~CShareScreenClientSocket();

	/// 带共享屏幕客户端对话框指针的构造函数
	CShareScreenClientSocket( CShareScreenClientDlg * pSCClientDlg );

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareScreenClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CShareScreenClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARESCREENCLIENTSOCKET_H__CD4473AB_86A1_40D5_AFC6_67C5F3D11792__INCLUDED_)
