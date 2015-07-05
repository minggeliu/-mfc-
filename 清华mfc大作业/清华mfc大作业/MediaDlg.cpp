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
}


BEGIN_MESSAGE_MAP(MediaDlg, CDialogEx)
END_MESSAGE_MAP()


// MediaDlg 消息处理程序
