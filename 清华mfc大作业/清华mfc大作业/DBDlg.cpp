// DBDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�廪mfc����ҵ.h"
#include "DBDlg.h"
#include "afxdialogex.h"


// DBDlg �Ի���

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


// DBDlg ��Ϣ�������


BOOL DBDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_DBcombo.AddString(L"ID");
	m_DBcombo.AddString(L"����");
	m_DBcombo.AddString(L"����");
	m_DBcombo.AddString(L"�Ա�");
	m_DBcombo.AddString(L"ѧԺ");
	m_DBcombo.AddString(L"ѧ��");
	m_DBcombo.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣:  OCX ����ҳӦ���� FALSE
}


void DBDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	switch (m_DBcombo.GetCurSel())
	{
	case 0:
		my_string = "ID";break;
	case 1:
		my_string = "����";break;
	case 2:
		my_string = "����";break;
	case 3:
		my_string = "�Ա�";break;
	case 4:
		my_string = "ѧԺ";break;
	case 5:
		my_string = "ѧ��";break;
	default:
		break;
	}
}


void DBDlg::OnBnClickedSort()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}


void DBDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	//my_string2 = my_keyword;
	//MessageBox(my_string2);
}
