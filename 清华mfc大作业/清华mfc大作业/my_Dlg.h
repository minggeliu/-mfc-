#pragma once
#include "afxwin.h"


// my_Dlg �Ի���

class my_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(my_Dlg)

public:
	my_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~my_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString my_edit1;
	CComboBox m_combo;
	virtual BOOL OnInitDialog();
};
