// MediaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "清华mfc大作业.h"
#include "MediaDlg.h"
#include "afxdialogex.h"


// MediaDlg 对话框

IMPLEMENT_DYNAMIC(MediaDlg, CDialogEx)

MediaDlg::MediaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MediaDlg::IDD, pParent)
{

}

MediaDlg::~MediaDlg()
{
}

void MediaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OCX1, m_mediaPlay);
}


BEGIN_MESSAGE_MAP(MediaDlg, CDialogEx)
END_MESSAGE_MAP()


// MediaDlg 消息处理程序


BOOL MediaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_mediaPlay.put_URL(L"res/录像4.avi");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常:  OCX 属性页应返回 FALSE
}
