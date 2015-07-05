#pragma once

#include "CWMPPlayer4.h"

// MediaDlg 对话框

class MediaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MediaDlg)

public:
	MediaDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MediaDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWMPPlayer4 m_mediaPlay;
	virtual BOOL OnInitDialog();
};
