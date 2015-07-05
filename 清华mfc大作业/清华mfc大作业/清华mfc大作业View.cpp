
// �廪mfc����ҵView.cpp : C�廪mfc����ҵView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�廪mfc����ҵ.h"
#endif

#include "�廪mfc����ҵSet.h"
#include "�廪mfc����ҵDoc.h"
#include "�廪mfc����ҵView.h"

#include "my_Dlg.h"
#include "DBDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�廪mfc����ҵView

IMPLEMENT_DYNCREATE(C�廪mfc����ҵView, CRecordView)

BEGIN_MESSAGE_MAP(C�廪mfc����ҵView, CRecordView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_OpenExp, &C�廪mfc����ҵView::OnOpenexp)
	ON_COMMAND(ID_32773, &C�廪mfc����ҵView::OnOpenSortAndSerach)
	ON_BN_CLICKED(IDSort, &C�廪mfc����ҵView::OnBnClickedSort)
END_MESSAGE_MAP()

// C�廪mfc����ҵView ����/����

C�廪mfc����ҵView::C�廪mfc����ҵView()
	: CRecordView(C�廪mfc����ҵView::IDD)
{
	m_pSet = NULL;
	// TODO:  �ڴ˴���ӹ������

}

C�廪mfc����ҵView::~C�廪mfc����ҵView()
{
}

void C�廪mfc����ҵView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->column1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->column2, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->column3, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->column4, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT6, m_pSet->column5, m_pSet);
}

BOOL C�廪mfc����ҵView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�廪mfc����ҵView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�廪mfc����ҵSet;
	CRecordView::OnInitialUpdate();

}


// C�廪mfc����ҵView ��ӡ

BOOL C�廪mfc����ҵView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�廪mfc����ҵView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�廪mfc����ҵView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// C�廪mfc����ҵView ���

#ifdef _DEBUG
void C�廪mfc����ҵView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�廪mfc����ҵView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�廪mfc����ҵDoc* C�廪mfc����ҵView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�廪mfc����ҵDoc)));
	return (C�廪mfc����ҵDoc*)m_pDocument;
}
#endif //_DEBUG


// C�廪mfc����ҵView ���ݿ�֧��
CRecordset* C�廪mfc����ҵView::OnGetRecordset()
{
	return m_pSet;
}



// C�廪mfc����ҵView ��Ϣ�������
void C�廪mfc����ҵView::OnOpenexp()
{
	// TODO:  �ڴ���������������
	my_Dlg m_Dlg1;
	m_Dlg1.DoModal();
}


void C�廪mfc����ҵView::OnOpenSortAndSerach()
{
	// TODO:  �ڴ���������������
	DBDlg m_DBDlg;
	if (m_DBDlg.DoModal() == IDOK) {		//IDOK���ڴ˴�������ť
		CString string;
		string.Format(L"%s desc", m_DBDlg.my_string);	//�Ӵ�С����
		m_pSet->Close();
		m_pSet->m_strSort = string;
		m_pSet->Open();
		UpdateData(false);
	}
	
}


void C�廪mfc����ҵView::OnBnClickedSort()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
		
}
