// VideoChatSocket.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "VideoChatSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "VideoChatDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CVideoChatSocket

CVideoChatSocket::CVideoChatSocket()
{
}

CVideoChatSocket::~CVideoChatSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CVideoChatSocket, CSocket)
	//{{AFX_MSG_MAP(CVideoChatSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CVideoChatSocket member functions

void CVideoChatSocket::OnReceive(int nErrorCode) 
{
	m_pVideoChatDlg->OnReceive();
	CSocket::OnReceive(nErrorCode);
}
