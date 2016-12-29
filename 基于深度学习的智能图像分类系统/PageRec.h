#pragma once
#include<vector>
#include "Caffe.h"
#include "afxcmn.h"
using namespace std;
// PageMain 对话框

class PageMain : public CDialogEx
{
	DECLARE_DYNAMIC(PageMain)

public:
	PageMain(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~PageMain();
	void SetImgVec(vector<Mat> images);
// 对话框数据
	enum { IDD = IDD_DIALOG_Main };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	vector<Mat> images;
public:
	afx_msg void OnBnClickedPagerecstart();
	afx_msg void OnBnClickedPagerecquit();
	// //目标识别页的进度条
	CProgressCtrl pageRecProgress;
};
