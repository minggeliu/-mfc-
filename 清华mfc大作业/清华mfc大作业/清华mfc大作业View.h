
// �廪mfc����ҵView.h : C�廪mfc����ҵView ��Ľӿ�
//

#pragma once

class C�廪mfc����ҵSet;

class C�廪mfc����ҵView : public CRecordView
{
protected: // �������л�����
	C�廪mfc����ҵView();
	DECLARE_DYNCREATE(C�廪mfc����ҵView)

public:
	enum{ IDD = IDD_MFC_FORM };
	C�廪mfc����ҵSet* m_pSet;

// ����
public:
	C�廪mfc����ҵDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C�廪mfc����ҵView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOpenexp();
};

#ifndef _DEBUG  // �廪mfc����ҵView.cpp �еĵ��԰汾
inline C�廪mfc����ҵDoc* C�廪mfc����ҵView::GetDocument() const
   { return reinterpret_cast<C�廪mfc����ҵDoc*>(m_pDocument); }
#endif

