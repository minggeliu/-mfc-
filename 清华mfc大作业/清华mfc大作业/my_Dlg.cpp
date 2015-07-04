// my_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�廪mfc����ҵ.h"
#include "my_Dlg.h"
#include "afxdialogex.h"


// my_Dlg �Ի���

IMPLEMENT_DYNAMIC(my_Dlg, CDialogEx)

my_Dlg::my_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(my_Dlg::IDD, pParent)
	, my_edit1(_T(""))
	, my_weight(0.01)
	, my_speed(1)
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
}


BEGIN_MESSAGE_MAP(my_Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &my_Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &my_Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &my_Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &my_Dlg::OnBnClickedRadio3)
END_MESSAGE_MAP()


// my_Dlg ��Ϣ�������


BOOL my_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_combo.AddString(L"10g");
	m_combo.AddString(L"100g");
	m_combo.AddString(L"1kg");
	m_combo.SetCurSel(0);

	m_speed1.SetCheck(1);

	ShowDetail();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣:  OCX ����ҳӦ���� FALSE
}


void my_Dlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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


// ��ʾ������
void my_Dlg::ShowDetail()
{
	my_edit1.Format(L"����:%.2fkg\t�ٶ�:%.2fm/s",my_weight,my_speed);
	UpdateData(false);
}


void my_Dlg::OnBnClickedRadio1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_speed = 1;
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_speed = 2;
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_speed = 3;
	ShowDetail();
}
