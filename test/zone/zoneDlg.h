// zoneDlg.h : header file
//

#if !defined(AFX_ZONEDLG_H__EA8B2AB5_D19D_4950_B5E5_630B82B0E6C1__INCLUDED_)
#define AFX_ZONEDLG_H__EA8B2AB5_D19D_4950_B5E5_630B82B0E6C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CZoneDlg dialog

class CZoneDlg : public CDialog
{
// Construction
public:
	CZoneDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CZoneDlg)
	enum { IDD = IDD_ZONE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZoneDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CZoneDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZONEDLG_H__EA8B2AB5_D19D_4950_B5E5_630B82B0E6C1__INCLUDED_)
