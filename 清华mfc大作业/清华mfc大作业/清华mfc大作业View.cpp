
// 清华mfc大作业View.cpp : C清华mfc大作业View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "清华mfc大作业.h"
#endif

#include "清华mfc大作业Set.h"
#include "清华mfc大作业Doc.h"
#include "清华mfc大作业View.h"

#include "my_Dlg.h"
#include "DBDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C清华mfc大作业View

IMPLEMENT_DYNCREATE(C清华mfc大作业View, CRecordView)

BEGIN_MESSAGE_MAP(C清华mfc大作业View, CRecordView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRecordView::OnFilePrintPreview)
	ON_COMMAND(ID_OpenExp, &C清华mfc大作业View::OnOpenexp)
	ON_COMMAND(ID_32773, &C清华mfc大作业View::OnOpenSortAndSerach)
	ON_BN_CLICKED(IDSort, &C清华mfc大作业View::OnBnClickedSort)
END_MESSAGE_MAP()

// C清华mfc大作业View 构造/析构

C清华mfc大作业View::C清华mfc大作业View()
	: CRecordView(C清华mfc大作业View::IDD)
{
	m_pSet = NULL;
	// TODO:  在此处添加构造代码

}

C清华mfc大作业View::~C清华mfc大作业View()
{
}

void C清华mfc大作业View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_FieldText(pDX, IDC_EDIT1, m_pSet->m_ID, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT2, m_pSet->column1, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT3, m_pSet->column2, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT4, m_pSet->column3, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT5, m_pSet->column4, m_pSet);
	DDX_FieldText(pDX, IDC_EDIT6, m_pSet->column5, m_pSet);
}

BOOL C清华mfc大作业View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C清华mfc大作业View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_清华mfc大作业Set;
	CRecordView::OnInitialUpdate();

}


// C清华mfc大作业View 打印

BOOL C清华mfc大作业View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C清华mfc大作业View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void C清华mfc大作业View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// C清华mfc大作业View 诊断

#ifdef _DEBUG
void C清华mfc大作业View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C清华mfc大作业View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C清华mfc大作业Doc* C清华mfc大作业View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C清华mfc大作业Doc)));
	return (C清华mfc大作业Doc*)m_pDocument;
}
#endif //_DEBUG


// C清华mfc大作业View 数据库支持
CRecordset* C清华mfc大作业View::OnGetRecordset()
{
	return m_pSet;
}



// C清华mfc大作业View 消息处理程序
void C清华mfc大作业View::OnOpenexp()
{
	// TODO:  在此添加命令处理程序代码
	my_Dlg m_Dlg1;
	m_Dlg1.DoModal();
}


void C清华mfc大作业View::OnOpenSortAndSerach()
{
	// TODO:  在此添加命令处理程序代码
	DBDlg m_DBDlg;
	if (m_DBDlg.DoModal() == IDOK) {		//IDOK键在此处是排序按钮
		CString string;
		string.Format(L"%s desc", m_DBDlg.my_string);	//从大到小排序
		m_pSet->Close();
		m_pSet->m_strSort = string;
		m_pSet->Open();
		UpdateData(false);
	}
	
}


void C清华mfc大作业View::OnBnClickedSort()
{
	// TODO:  在此添加控件通知处理程序代码
		
}
