#pragma once 
#include "stdafx.h"
#include "MFCBoardClientDlg.h"

class CWhiteBoardClientSocket : public CSocket
{
// Attributes
private:
	CMFCBoardClientDlg		*m_pWBClientDlg;				/// �װ�ͻ��˶Ի���ָ��

// Operations
public:
	CWhiteBoardClientSocket();
	virtual ~CWhiteBoardClientSocket();

	/// ���װ�ͻ��˶Ի���ָ��Ĺ��캯��
	CWhiteBoardClientSocket( CMFCBoardClientDlg * pWBClientDlg );

// Overrides
public:
	virtual void OnReceive(int nErrorCode);
};


