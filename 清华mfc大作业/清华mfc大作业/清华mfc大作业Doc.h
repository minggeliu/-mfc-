
// �廪mfc����ҵDoc.h : C�廪mfc����ҵDoc ��Ľӿ�
//


#pragma once
#include "�廪mfc����ҵSet.h"


class C�廪mfc����ҵDoc : public CDocument
{
protected: // �������л�����
	C�廪mfc����ҵDoc();
	DECLARE_DYNCREATE(C�廪mfc����ҵDoc)

// ����
public:
	C�廪mfc����ҵSet m_�廪mfc����ҵSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C�廪mfc����ҵDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
