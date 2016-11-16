// ConSrvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCBoardClient.h"
#include "ConSrvDlg.h"
#include "afxdialogex.h"


// ConSrvDlg 对话框

IMPLEMENT_DYNAMIC(ConSrvDlg, CDialogEx)

ConSrvDlg::ConSrvDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ConSrvDlg::IDD, pParent)
{

}

ConSrvDlg::~ConSrvDlg()
{
}

void ConSrvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESSCONSER, m_IPAddrConServ);
	DDX_Control(pDX, IDC_EDIT_PORTCONSER, m_Port);
}


BEGIN_MESSAGE_MAP(ConSrvDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ConSrvDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ConSrvDlg 消息处理程序

BOOL ConSrvDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_IPAddrConServ.SetWindowText("192.168.1.102");
	m_Port.SetWindowText("8017");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void ConSrvDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_IPAddrConServ.GetWindowText( Ser_IP ) ;
	m_Port.GetWindowText( Ser_Port ) ;
	//MessageBox( Ser_IP , Ser_Port , 0 ) ;
	CDialogEx::OnOK();
}

CString ConSrvDlg::GetSerIP()
{
	return Ser_IP;
}

CString ConSrvDlg::GetSerPort()
{
	return Ser_Port;
}