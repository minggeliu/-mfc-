
// �廪mfc����ҵSet.cpp : C�廪mfc����ҵSet ���ʵ��
//

#include "stdafx.h"
#include "�廪mfc����ҵ.h"
#include "�廪mfc����ҵSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�廪mfc����ҵSet ʵ��

// ���������� 2015��7��4��, 16:28

IMPLEMENT_DYNAMIC(C�廪mfc����ҵSet, CRecordset)

C�廪mfc����ҵSet::C�廪mfc����ҵSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = 0;
	column3 = L"";
	column4 = L"";
	column5 = 0.0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ���⣺�����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�廪mfc����ҵSet::GetDefaultConnect()
{
	return _T("DBQ=res\\db\\student.mdb;DefaultDir=res\\db;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=res\\db\\student.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString C�廪mfc����ҵSet::GetDefaultSQL()
{
	return _T("[��1]");
}

void C�廪mfc����ҵSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Long(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[�Ա�]"), column3);
	RFX_Text(pFX, _T("[ѧԺ]"), column4);
	RFX_Double(pFX, _T("[ѧ��]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// C�廪mfc����ҵSet ���

#ifdef _DEBUG
void C�廪mfc����ҵSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�廪mfc����ҵSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

