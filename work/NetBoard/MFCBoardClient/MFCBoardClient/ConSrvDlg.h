#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "stdafx.h"


// ConSrvDlg 对话框

class ConSrvDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConSrvDlg)

public:
	ConSrvDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ConSrvDlg();

// 对话框数据
	enum { IDD = IDD_CONNSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	CIPAddressCtrl m_IPAddrConServ;
	CEdit m_Port;
	afx_msg void OnBnClickedOk();
	CString GetSerIP();
	CString GetSerPort();
private:
	CString Ser_IP;
	CString Ser_Port;
};
