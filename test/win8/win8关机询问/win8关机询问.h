// win8关机询问.h : main header file for the WIN8关机询问 application
//

#if !defined(AFX_WIN8_H__DB91D5B4_3058_4579_A98E_2915432A975A__INCLUDED_)
#define AFX_WIN8_H__DB91D5B4_3058_4579_A98E_2915432A975A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWin8App:
// See win8关机询问.cpp for the implementation of this class
//

class CWin8App : public CWinApp
{
public:
	CWin8App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWin8App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWin8App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIN8_H__DB91D5B4_3058_4579_A98E_2915432A975A__INCLUDED_)
