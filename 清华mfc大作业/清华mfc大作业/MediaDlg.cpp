// MediaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�廪mfc����ҵ.h"
#include "MediaDlg.h"
#include "afxdialogex.h"


// MediaDlg �Ի���

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


// MediaDlg ��Ϣ�������


BOOL MediaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_mediaPlay.put_URL(L"res/¼��4.avi");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣:  OCX ����ҳӦ���� FALSE
}
