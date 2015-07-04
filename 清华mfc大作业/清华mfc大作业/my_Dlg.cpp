// my_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "清华mfc大作业.h"
#include "my_Dlg.h"
#include "afxdialogex.h"


// my_Dlg 对话框

IMPLEMENT_DYNAMIC(my_Dlg, CDialogEx)

my_Dlg::my_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(my_Dlg::IDD, pParent)
	, my_edit1(_T(""))
	, my_weight(0.01)
	, my_speed(1)
	, my_degree(45)
	, my_height(0)
{

}

my_Dlg::~my_Dlg()
{
}

void my_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, my_edit1);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_RADIO1, m_speed1);
	DDX_Text(pDX, IDC_EDIT2, my_degree);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_hscrollbar);
}


BEGIN_MESSAGE_MAP(my_Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &my_Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &my_Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &my_Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &my_Dlg::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT2, &my_Dlg::OnEnChangeEdit2)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// my_Dlg 消息处理程序


BOOL my_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_combo.AddString(L"10g");
	m_combo.AddString(L"100g");
	m_combo.AddString(L"1kg");
	m_combo.SetCurSel(0);

	m_speed1.SetCheck(1);

	UpdateData(false);		//显示抛射角度数

	m_hscrollbar.SetScrollRange(0, 500);
	m_hscrollbar.SetScrollPos(0);
	my_height = 0;

	ShowDetail();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常:  OCX 属性页应返回 FALSE
}


void my_Dlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	switch (m_combo.GetCurSel())
	{
	case 0:
		my_weight = 0.01;break;
	case 1:
		my_weight = 0.1;break;
	case 2:
		my_weight = 1;break;
	default:
		break;
	}
	ShowDetail();
}


// 显示各参数
void my_Dlg::ShowDetail()
{
	my_edit1.Format(L"质量:%.2fkg\t\t速度:%.2fm/s\t\t抛射角:%.2f°\t\t高度:%.2fm",my_weight,my_speed,my_degree,my_height);
	UpdateData(false);
}


void my_Dlg::OnBnClickedRadio1()
{
	// TODO:  在此添加控件通知处理程序代码
	my_speed = 1;
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	my_speed = 2;
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	my_speed = 3;
	ShowDetail();
}


void my_Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	if (my_degree > 90) my_degree = 90;
	else if (my_degree < 0) my_degree = 0;
	UpdateData(false);
	ShowDetail();
}


void my_Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	int iNowPos;
	switch (nSBCode)
	{
		if (pScrollBar == &m_hscrollbar) {
			case SB_THUMBTRACK:
				m_hscrollbar.SetScrollPos(nPos);
				my_height = nPos * 1.00 / 100;
				ShowDetail();break;
			case SB_LINERIGHT:
				iNowPos = m_hscrollbar.GetScrollPos();
				iNowPos++;
				if (iNowPos > 500) iNowPos = 500;
				m_hscrollbar.SetScrollPos(iNowPos);
				my_height = iNowPos * 1.00 / 100;
				ShowDetail();break;
			case SB_LINELEFT:
				iNowPos = m_hscrollbar.GetScrollPos();
				iNowPos--;
				if (iNowPos < 0) iNowPos = 0;
				m_hscrollbar.SetScrollPos(iNowPos);
				my_height = iNowPos * 1.00 / 100;
				ShowDetail();break;
			case SB_PAGERIGHT:
				iNowPos = m_hscrollbar.GetScrollPos();
				iNowPos += 10;
				if (iNowPos > 500) iNowPos = 500;
				m_hscrollbar.SetScrollPos(iNowPos);
				my_height = iNowPos * 1.00 / 100;
				ShowDetail();break;
			case SB_PAGELEFT:
				iNowPos = m_hscrollbar.GetScrollPos();
				iNowPos -= 10;
				if (iNowPos < 0) iNowPos = 0;
				m_hscrollbar.SetScrollPos(iNowPos);
				my_height = iNowPos * 1.00 / 100;
				ShowDetail();break;
		}
	default:
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
