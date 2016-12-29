// PageMain.cpp : 实现文件
//

#include "stdafx.h"
#include "基于深度学习的智能图像分类系统.h"
#include "PageRec.h"
#include "afxdialogex.h"


// PageMain 对话框

IMPLEMENT_DYNAMIC(PageMain, CDialogEx)

PageMain::PageMain(CWnd* pParent /*=NULL*/)
	: CDialogEx(PageMain::IDD, pParent)
{

}

PageMain::~PageMain()
{
}

void PageMain::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PageRecPROGRESS, pageRecProgress);
}


BEGIN_MESSAGE_MAP(PageMain, CDialogEx)
	ON_BN_CLICKED(IDC_PageRecStart, &PageMain::OnBnClickedPagerecstart)
	ON_BN_CLICKED(IDC_PageRecQuit, &PageMain::OnBnClickedPagerecquit)
END_MESSAGE_MAP()


// PageMain 消息处理程序


void PageMain::OnBnClickedPagerecstart()
{
	namedWindow("pageRecWindow", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("pageRecWindow");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_PageRecWindow)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	//
	//识别结果输出至文件
	fstream in_imagePath;
	fstream out_rec_result, out_resultForCluster;

	in_imagePath.open("images_path.txt", ios::in);
	out_rec_result.open("caffe_rec_result.txt", ios::out);
	out_resultForCluster.open("resultForCluster.txt", ios::out);


	// TODO:  在此添加控件通知处理程序代码
	Caffe caffe;
	string label;

	pageRecProgress.SetRange(0, images.size());
	pageRecProgress.SetStep(1);

	if (this->images.size() > 0){
		for (int i = 0; i < this->images.size(); i++){
			pageRecProgress.StepIt();
			Mat img;
			resize(this->images.at(i), img, Size(250, 250));
			label = caffe.Recognize(img);
			putText(img,label,Point(50,50),1,1.0,Scalar(0,255,0));
			imshow("pageRecWindow", img);
			waitKey(50);
			string line;
			getline(in_imagePath, line);

			out_rec_result << label << endl;
			out_resultForCluster << line << " " << label << endl;
		}
	}
	in_imagePath.close();
	out_rec_result.close();
	out_resultForCluster.close();
}


void PageMain::OnBnClickedPagerecquit()
{
	if (MessageBox("确认退出", "", MB_YESNO | MB_ICONQUESTION) == IDYES){
		this->SendMessage(WM_CLOSE);
	}
}
void PageMain::SetImgVec(vector<Mat> images){
	this->images = images;
}