
// 清华mfc大作业View.h : C清华mfc大作业View 类的接口
//

#pragma once

class C清华mfc大作业Set;

class C清华mfc大作业View : public CRecordView
{
protected: // 仅从序列化创建
	C清华mfc大作业View();
	DECLARE_DYNCREATE(C清华mfc大作业View)

public:
	enum{ IDD = IDD_MFC_FORM };
	C清华mfc大作业Set* m_pSet;

// 特性
public:
	C清华mfc大作业Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C清华mfc大作业View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpenexp();
};

#ifndef _DEBUG  // 清华mfc大作业View.cpp 中的调试版本
inline C清华mfc大作业Doc* C清华mfc大作业View::GetDocument() const
   { return reinterpret_cast<C清华mfc大作业Doc*>(m_pDocument); }
#endif

