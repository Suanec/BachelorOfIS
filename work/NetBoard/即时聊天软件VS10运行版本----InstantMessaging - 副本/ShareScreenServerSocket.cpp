// ShareScreenServerSocket.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "ShareScreenServerSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerSocket

CShareScreenServerSocket::CShareScreenServerSocket()
{
}

CShareScreenServerSocket::CShareScreenServerSocket( CShareScreenServerDlg * pSCServerDlg )
{
	m_pSCServerDlg = pSCServerDlg;
}

CShareScreenServerSocket::~CShareScreenServerSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CShareScreenServerSocket, CSocket)
	//{{AFX_MSG_MAP(CShareScreenServerSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CShareScreenServerSocket member functions

void CShareScreenServerSocket::OnReceive(int nErrorCode) 
{
	m_pSCServerDlg->OnReceive();
	CSocket::OnReceive(nErrorCode);
}
