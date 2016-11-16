#pragma once 
#include "stdafx.h"
#include "MFCBoardClientDlg.h"

class CWhiteBoardClientSocket : public CSocket
{
// Attributes
private:
	CMFCBoardClientDlg		*m_pWBClientDlg;				/// 白板客户端对话框指针

// Operations
public:
	CWhiteBoardClientSocket();
	virtual ~CWhiteBoardClientSocket();

	/// 带白板客户端对话框指针的构造函数
	CWhiteBoardClientSocket( CMFCBoardClientDlg * pWBClientDlg );

// Overrides
public:
	virtual void OnReceive(int nErrorCode);
};


