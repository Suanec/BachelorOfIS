#pragma once
#include "StdAfx.h"
#include "resource.h"
#include "afxcmn.h"

// CAddUserDlg �Ի���

class CAddUserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddUserDlg)

public:
	CAddUserDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddUserDlg();

// �Ի�������
	enum { IDD = IDD_ADDUSER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	DWORD m_UserIP;
	afx_msg void OnBnClickedOk();
	void CAddUserDlg::Addfriend(CString) ;

	CIPAddressCtrl m_UserIPAddr;
};
