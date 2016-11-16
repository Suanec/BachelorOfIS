// ShareScreenClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "ShareScreenClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientSocket

CShareScreenClientSocket::CShareScreenClientSocket()
{
}

CShareScreenClientSocket::CShareScreenClientSocket(  CShareScreenClientDlg * pSCClientDlg )
{
	m_pSCClientDlg = pSCClientDlg;
}

CShareScreenClientSocket::~CShareScreenClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CShareScreenClientSocket, CSocket)
	//{{AFX_MSG_MAP(CShareScreenClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CShareScreenClientSocket member functions

void CShareScreenClientSocket::OnReceive(int nErrorCode) 
{
	m_pSCClientDlg->OnReceive();
	CSocket::OnReceive(nErrorCode);
}
