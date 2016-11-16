#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "stdafx.h"


// ConSrvDlg �Ի���

class ConSrvDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ConSrvDlg)

public:
	ConSrvDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ConSrvDlg();

// �Ի�������
	enum { IDD = IDD_CONNSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
