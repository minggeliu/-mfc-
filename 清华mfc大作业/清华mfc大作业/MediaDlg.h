#pragma once

#include "CWMPPlayer4.h"

// MediaDlg �Ի���

class MediaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MediaDlg)

public:
	MediaDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MediaDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CWMPPlayer4 m_mediaPlay;
	virtual BOOL OnInitDialog();
};
