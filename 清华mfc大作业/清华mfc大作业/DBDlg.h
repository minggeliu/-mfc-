#pragma once
#include "afxwin.h"

class C�廪mfc����ҵView;

// DBDlg �Ի���

class DBDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DBDlg)

public:
	DBDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DBDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_DBcombo;
	CString my_string;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedSort();
	CString my_keyword;
	afx_msg void OnEnChangeEdit1();
	CString my_string2;
};
