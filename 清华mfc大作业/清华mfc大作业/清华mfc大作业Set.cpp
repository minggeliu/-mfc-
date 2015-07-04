
// 清华mfc大作业Set.cpp : C清华mfc大作业Set 类的实现
//

#include "stdafx.h"
#include "清华mfc大作业.h"
#include "清华mfc大作业Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C清华mfc大作业Set 实现

// 代码生成在 2015年7月4日, 16:28

IMPLEMENT_DYNAMIC(C清华mfc大作业Set, CRecordset)

C清华mfc大作业Set::C清华mfc大作业Set(CDatabase* pdb)
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
//#error 安全问题：连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString C清华mfc大作业Set::GetDefaultConnect()
{
	return _T("DBQ=res\\db\\student.mdb;DefaultDir=res\\db;Driver={Microsoft Access Driver (*.mdb)};DriverId=25;FIL=MS Access;FILEDSN=res\\db\\student.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString C清华mfc大作业Set::GetDefaultSQL()
{
	return _T("[表1]");
}

void C清华mfc大作业Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Long(pFX, _T("[年龄]"), column2);
	RFX_Text(pFX, _T("[性别]"), column3);
	RFX_Text(pFX, _T("[学院]"), column4);
	RFX_Double(pFX, _T("[学费]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// C清华mfc大作业Set 诊断

#ifdef _DEBUG
void C清华mfc大作业Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C清华mfc大作业Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

