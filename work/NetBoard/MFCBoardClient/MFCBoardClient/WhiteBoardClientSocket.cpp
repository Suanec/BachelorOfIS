#include "stdafx.h"
#include "WhiteBoardClientSocket.h"

/////////////////////////////////////////////////////////////////////////////
// CWhiteBoardClientSocket

CWhiteBoardClientSocket::CWhiteBoardClientSocket()
{
}

CWhiteBoardClientSocket::CWhiteBoardClientSocket( CMFCBoardClientDlg * pWBClientDlg )
{
	m_pWBClientDlg = pWBClientDlg;
}

CWhiteBoardClientSocket::~CWhiteBoardClientSocket()
{
}



/////////////////////////////////////////////////////////////////////////////
// CWhiteBoardClientSocket member functions

void CWhiteBoardClientSocket::OnReceive(int nErrorCode) 
{
	m_pWBClientDlg->OnReceive();
	CSocket::OnReceive(nErrorCode);
}
