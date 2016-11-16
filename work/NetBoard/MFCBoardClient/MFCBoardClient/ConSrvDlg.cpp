// ConSrvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCBoardClient.h"
#include "ConSrvDlg.h"
#include "afxdialogex.h"


// ConSrvDlg �Ի���

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


// ConSrvDlg ��Ϣ�������

BOOL ConSrvDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_IPAddrConServ.SetWindowText("192.168.1.102");
	m_Port.SetWindowText("8017");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}


void ConSrvDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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