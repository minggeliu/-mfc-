#pragma once
#include "afxwin.h"
#include <vector>

class EXPERIMENT {
public:
	double speed;
	double degree;
	double height;
	enum COLOR
	{
		red,green,blue
	}color;
	double t;
};

// my_Dlg 对话框

class my_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(my_Dlg)

public:
	my_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~my_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString my_edit1;
	CComboBox m_combo;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	double my_weight;
	// 显示各参数
	void ShowDetail();
	double my_speed;
	// 第一个速度单选按钮控件
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
	afx_msg void OnBnClickedOk();

	std::vector<EXPERIMENT> experiment;
	afx_msg void OnPaint();
	int x0;
	int y0;
	double g;
	// 坐标单位米转换到像素的放大倍数
	int mtopixe;
};
