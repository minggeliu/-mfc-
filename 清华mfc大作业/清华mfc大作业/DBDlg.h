#pragma once
#include "afxwin.h"

class C清华mfc大作业View;

// DBDlg 对话框

class DBDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DBDlg)

public:
	DBDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DBDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
