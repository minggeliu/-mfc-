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
}


BEGIN_MESSAGE_MAP(my_Dlg, CDialogEx)
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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常:  OCX 属性页应返回 FALSE
}
