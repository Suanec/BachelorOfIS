
// MFCBoardClient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCBoardClientApp:
// �йش����ʵ�֣������ MFCBoardClient.cpp
//
class CWhiteBoardClientSocket;

class CMFCBoardClientApp : public CWinApp
{
public:
	CMFCBoardClientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCBoardClientApp theApp;