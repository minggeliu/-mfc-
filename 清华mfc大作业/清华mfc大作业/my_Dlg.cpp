// my_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�廪mfc����ҵ.h"
#include "my_Dlg.h"
#include "afxdialogex.h"
#include <vector>
#include <math.h>


// my_Dlg �Ի���

IMPLEMENT_DYNAMIC(my_Dlg, CDialogEx)

my_Dlg::my_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(my_Dlg::IDD, pParent)
	, my_edit1(_T(""))
	, my_weight(0.01)
	, my_speed(1)
	, my_degree(45)
	, my_height(0)
	, my_color("red")
	, x0(30)
	, y0(400)
	, g(9.8)
	, mtopixe(400)
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
	DDX_Control(pDX, IDC_RADIO4, m_colorred);
}


BEGIN_MESSAGE_MAP(my_Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &my_Dlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &my_Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &my_Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &my_Dlg::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT2, &my_Dlg::OnEnChangeEdit2)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO4, &my_Dlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &my_Dlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &my_Dlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDOK, &my_Dlg::OnBnClickedOk)
	ON_WM_PAINT()
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

	m_speed1.SetCheck(1);	//�ٶ�1m/s

	UpdateData(false);		//��ʾ����Ƕ���

	m_hscrollbar.SetScrollRange(0, 40);
	m_hscrollbar.SetScrollPos(0);
	my_height = 0;

	m_colorred.SetCheck(1);	//��ɫ��ɫ

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
	my_edit1.Format(L"����:%.2fkg\t  �ٶ�:%.2fm/s\t  �����:%.2f��\t  �߶�:%.2fm\t  ��ɫ:%s",my_weight,my_speed,my_degree,my_height,my_color);
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


void my_Dlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if (my_degree > 90) my_degree = 90;
	else if (my_degree < 0) my_degree = 0;
	UpdateData(false);
	ShowDetail();
}


void my_Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
				if (iNowPos > 40) iNowPos = 40;
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
				if (iNowPos > 40) iNowPos = 40;
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


void my_Dlg::OnBnClickedRadio4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_color = "red";
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_color = "green";
	ShowDetail();
}


void my_Dlg::OnBnClickedRadio6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	my_color = "blue";
	ShowDetail();
}


void my_Dlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	EXPERIMENT temp;
	temp.degree = my_degree;
	temp.height = my_height;
	temp.speed = my_speed;
	temp.t = 0;
	if (my_color == "red") temp.color = EXPERIMENT::red;
	else if (my_color == "green") temp.color = EXPERIMENT::green;
	else if (my_color == "blue") temp.color = EXPERIMENT::blue;

	experiment.push_back(temp);

	CRect rect(x0 - 20, 100 - 20, 580 + 20, y0 + 20);		//ˢ������

	double x1, y1;
	temp.degree = temp.degree / 180 * 3.1415926;
	while (1) {
		x1 = (cos(temp.degree)*temp.speed*experiment[experiment.size() - 1].t)*mtopixe;
		y1 = (sin(temp.degree)*temp.speed*experiment[experiment.size() - 1].t - g*experiment[experiment.size() - 1].t*experiment[experiment.size() - 1].t / 2 + temp.height)*mtopixe;
		if (x1 < 0 || y1 < 0 || x1 > 550 || y1 > y0-100) { 
			if (x1 < 0) {
				experiment[experiment.size() - 1].t -= 0.001;
				x1 = (cos(temp.degree)*temp.speed*experiment[experiment.size() - 1].t);
				y1 = (sin(temp.degree)*temp.speed*experiment[experiment.size() - 1].t - g*experiment[experiment.size() - 1].t*experiment[experiment.size() - 1].t / 2 + temp.height);
				my_edit1.Format(L"����!��ɵ�����ȥ��~\t\tx:%fm\t\ty:%fm\t\tt:%fs", x1, y1, experiment[experiment.size() - 1].t);
				UpdateData(false);
				break;
			}
			if (x1 > 550) {
				experiment[experiment.size() - 1].t -= 0.001;
				x1 = (cos(temp.degree)*temp.speed*experiment[experiment.size() - 1].t);
				y1 = (sin(temp.degree)*temp.speed*experiment[experiment.size() - 1].t - g*experiment[experiment.size() - 1].t*experiment[experiment.size() - 1].t / 2 + temp.height);
				my_edit1.Format(L"�����������!\t\tx:%fm\t\ty:%fm\t\tt:%fs", x1, y1, experiment[experiment.size() - 1].t);
				UpdateData(false);
				break;
			}
			if(y1 > y0 - 100) {
				experiment[experiment.size() - 1].t -= 0.001;
				x1 = (cos(temp.degree)*temp.speed*experiment[experiment.size() - 1].t);
				y1 = (sin(temp.degree)*temp.speed*experiment[experiment.size() - 1].t - g*experiment[experiment.size() - 1].t*experiment[experiment.size() - 1].t / 2 + temp.height);
				my_edit1.Format(L"�����߶�����!\t\tx:%fm\t\ty:%fm\t\tt:%fs", x1, y1, experiment[experiment.size() - 1].t);
				UpdateData(false);
				break;
			}
			if (y1 < 0) {
				experiment[experiment.size() - 1].t -= 0.001;
				x1 = (cos(temp.degree)*temp.speed*experiment[experiment.size() - 1].t);
				y1 = (sin(temp.degree)*temp.speed*experiment[experiment.size() - 1].t - g*experiment[experiment.size() - 1].t*experiment[experiment.size() - 1].t / 2 + temp.height);
				my_edit1.Format(L"���:\t\tx:%fm\t\tt:%fs", x1, experiment[experiment.size() - 1].t);
				UpdateData(false);
				break; 
			}
			break;
		}
		else { 
			InvalidateRect(rect); 
			experiment[experiment.size() - 1].t += 0.001; 
		}
		
	}
	
}


void my_Dlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO:  �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	dc.SelectObject(&pen);
	CBrush brush;
	dc.MoveTo(x0, y0);
	dc.LineTo(580, y0);
	dc.MoveTo(x0, y0);
	dc.LineTo(x0, 100);
	dc.MoveTo(x0, y0);

	double t, x, y;
	
	for (unsigned int i = 0;i < experiment.size();i++) {
		t = 0;
		switch (experiment[i].color)
		{
		case EXPERIMENT::red:
			pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));dc.SelectObject(&pen);
			brush.CreateSolidBrush(RGB(255, 0, 0));dc.SelectObject(&brush);
			break;
		case EXPERIMENT::green:
			pen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));dc.SelectObject(&pen);
			brush.CreateSolidBrush(RGB(0, 255, 0));dc.SelectObject(&brush);
			break;
		case EXPERIMENT::blue:
			pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 255));dc.SelectObject(&pen);
			brush.CreateSolidBrush(RGB(0, 0, 255));dc.SelectObject(&brush);
			break;
		default:
			break;
		}
		experiment[i].degree = experiment[i].degree / 180 * 3.1415926;
		while (t < experiment[i].t) {
			x = x0 + (cos(experiment[i].degree)*experiment[i].speed*t)*mtopixe;
			y = y0 - (sin(experiment[i].degree)*experiment[i].speed*t - g*t*t / 2 + experiment[i].height)*mtopixe;
			dc.LineTo(x, y);
			t += 0.01;
		}
		x = x0 + (cos(experiment[i].degree)*experiment[i].speed*t)*mtopixe;
		y = y0 - (sin(experiment[i].degree)*experiment[i].speed*t - g*t*t / 2 + experiment[i].height)*mtopixe;
		dc.LineTo(x, y);
		dc.Ellipse(x - 10, y - 10, x + 10, y + 10);
		dc.MoveTo(x0, y0);
		experiment[i].degree = experiment[i].degree / 3.1415926 * 180;
	}
}
