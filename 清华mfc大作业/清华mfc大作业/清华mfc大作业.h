
// �廪mfc����ҵ.h : �廪mfc����ҵ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�廪mfc����ҵApp:
// �йش����ʵ�֣������ �廪mfc����ҵ.cpp
//

class C�廪mfc����ҵApp : public CWinApp
{
public:
	C�廪mfc����ҵApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�廪mfc����ҵApp theApp;
