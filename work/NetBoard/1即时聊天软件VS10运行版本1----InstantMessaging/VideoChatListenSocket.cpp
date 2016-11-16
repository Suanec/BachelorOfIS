// VideoChatListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "VideoChatListenSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "InstantMessagingDlg.H"

/////////////////////////////////////////////////////////////////////////////
// CVideoChatListenSocket

CVideoChatListenSocket::CVideoChatListenSocket()
{
}

CVideoChatListenSocket::~CVideoChatListenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CVideoChatListenSocket, CSocket)
	//{{AFX_MSG_MAP(CVideoChatListenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CVideoChatListenSocket member functions

void CVideoChatListenSocket::OnAccept(int nErrorCode) 
{
	m_pMainDlg->OnAcceptVideoChat();
	CSocket::OnAccept(nErrorCode);
}
