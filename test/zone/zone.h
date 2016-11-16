// zone.h : main header file for the ZONE application
//

#if !defined(AFX_ZONE_H__3B12FC89_2162_4CA1_B159_52553F420DE4__INCLUDED_)
#define AFX_ZONE_H__3B12FC89_2162_4CA1_B159_52553F420DE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CZoneApp:
// See zone.cpp for the implementation of this class
//

class CZoneApp : public CWinApp
{
public:
	CZoneApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZoneApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CZoneApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZONE_H__3B12FC89_2162_4CA1_B159_52553F420DE4__INCLUDED_)
