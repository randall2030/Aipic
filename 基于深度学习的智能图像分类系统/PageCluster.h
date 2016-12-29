#pragma once
#include"Cluster.h"
#include "afxwin.h"

// PageCluster 对话框

class PageCluster : public CDialogEx
{
	DECLARE_DYNAMIC(PageCluster)

public:
	PageCluster(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageCluster();
	void SetPath(String path);
// 对话框数据
	enum { IDD = IDD_DIALOG_Cluster };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	string folder_write_path;
public:
	afx_msg void OnBnClickedPageclusterstart();
	afx_msg void OnBnClickedPageclusterquit();
	// //类别标签 ListBox
	CListBox lb_label;
	// //类别数量 ListBox
	CListBox lb_number;
	afx_msg void OnLbnDblclkListCluster();
};
