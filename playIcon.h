
// playIcon.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CplayIconApp:
// �йش����ʵ�֣������ playIcon.cpp
//

class CplayIconApp : public CWinApp
{
public:
	CplayIconApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CplayIconApp theApp;