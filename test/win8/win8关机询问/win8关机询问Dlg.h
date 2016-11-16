// win8¹Ø»úÑ¯ÎÊDlg.h : header file
//

#if !defined(AFX_WIN8DLG_H__35C1DC06_1723_48F8_9575_4BC9DBE27AB1__INCLUDED_)
#define AFX_WIN8DLG_H__35C1DC06_1723_48F8_9575_4BC9DBE27AB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWin8Dlg dialog

class CWin8Dlg : public CDialog
{
// Construction
public:
	CWin8Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWin8Dlg)
	enum { IDD = IDD_WIN8_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWin8Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWin8Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	afx_msg void OnShutdown();
	afx_msg void Onlogout();
	afx_msg void OnRestart();
	afx_msg void Onby();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIN8DLG_H__35C1DC06_1723_48F8_9575_4BC9DBE27AB1__INCLUDED_)
