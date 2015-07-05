// DBDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "清华mfc大作业.h"
#include "DBDlg.h"
#include "afxdialogex.h"


// DBDlg 对话框

IMPLEMENT_DYNAMIC(DBDlg, CDialogEx)

DBDlg::DBDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DBDlg::IDD, pParent)
	, my_string("ID")
	, my_keyword(_T(""))
	, my_string2("")
{

}

DBDlg::~DBDlg()
{
}

void DBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_DBcombo);
	DDX_Text(pDX, IDC_EDIT1, my_keyword);
}


BEGIN_MESSAGE_MAP(DBDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &DBDlg::OnCbnSelchangeCombo1)
	//ON_BN_CLICKED(IDSort, &DBDlg::OnBnClickedSort)
	ON_EN_CHANGE(IDC_EDIT1, &DBDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DBDlg 消息处理程序


BOOL DBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_DBcombo.AddString(L"ID");
	m_DBcombo.AddString(L"姓名");
	m_DBcombo.AddString(L"年龄");
	m_DBcombo.AddString(L"性别");
	m_DBcombo.AddString(L"学院");
	m_DBcombo.AddString(L"学费");
	m_DBcombo.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常:  OCX 属性页应返回 FALSE
}


void DBDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	switch (m_DBcombo.GetCurSel())
	{
	case 0:
		my_string = "ID";break;
	case 1:
		my_string = "姓名";break;
	case 2:
		my_string = "年龄";break;
	case 3:
		my_string = "性别";break;
	case 4:
		my_string = "学院";break;
	case 5:
		my_string = "学费";break;
	default:
		break;
	}
}


void DBDlg::OnBnClickedSort()
{
	// TODO:  在此添加控件通知处理程序代码
	
}


void DBDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	//my_string2 = my_keyword;
	//MessageBox(my_string2);
}
