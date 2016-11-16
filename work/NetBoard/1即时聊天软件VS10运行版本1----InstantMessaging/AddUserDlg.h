#pragma once
#include "StdAfx.h"
#include "resource.h"
#include "afxcmn.h"

// CAddUserDlg 对话框

class CAddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUserDlg)

public:
	CAddUserDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddUserDlg();

// 对话框数据
	enum { IDD = IDD_ADDUSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_UserIP;
	afx_msg void OnBnClickedOk();
	void CAddUserDlg::Addfriend(CString) ;

	CIPAddressCtrl m_UserIPAddr;
};
