#pragma once
#include "afxwin.h"

class EXPERMENT {
public:
	double speed;
	double degree;
	double height;
	CString color;
	double t;
};

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
	afx_msg void OnCbnSelchangeCombo1();
	double my_weight;
	// ��ʾ������
	void ShowDetail();
	double my_speed;
	// ��һ���ٶȵ�ѡ��ť�ؼ�
	CButton m_speed1;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	double my_degree;
	afx_msg void OnEnChangeEdit2();
	CScrollBar m_hscrollbar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	double my_height;
	CButton m_colorred;
	CString my_color;
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
};
