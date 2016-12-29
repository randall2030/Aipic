// 基于深度学习的智能图像分类系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "基于深度学习的智能图像分类系统.h"
#include "基于深度学习的智能图像分类系统Dlg.h"
#include "afxdialogex.h"
#include "common.h"
#include "Caffe.h"
#include "Cluster.h"
#include "BasicFuncation.h"
#include"ImageMatch.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
string folder_read_path;
string folder_write_path;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C基于深度学习的智能图像分类系统Dlg 对话框



C基于深度学习的智能图像分类系统Dlg::C基于深度学习的智能图像分类系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C基于深度学习的智能图像分类系统Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C基于深度学习的智能图像分类系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, lb_imgPath);

	//DDX_Control(pDX, IDC_ShowLabel, static_text_show_label);
	//DDX_Control(pDX, IDC_LIST_CLuster, list_box_cluster);
	//DDX_Control(pDX, IDC_LIST2, list_box_cluster_num);
	//DDX_Control(pDX, IDC_PROGRESS2, progress_bar);
}

BEGIN_MESSAGE_MAP(C基于深度学习的智能图像分类系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_EXIT, &C基于深度学习的智能图像分类系统Dlg::OnBnClickedExit)		
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_32773, &C基于深度学习的智能图像分类系统Dlg::ReadDatasetFromFolder)
	ON_COMMAND(ID_32784, &C基于深度学习的智能图像分类系统Dlg::SelectOutputFolder)
	ON_COMMAND(ID_32785, &C基于深度学习的智能图像分类系统Dlg::StartRecognize)
	ON_COMMAND(ID_32787, &C基于深度学习的智能图像分类系统Dlg::StartCluster)
	ON_COMMAND(ID_32786, &C基于深度学习的智能图像分类系统Dlg::StartDerepet)
	ON_COMMAND(ID_32775, &C基于深度学习的智能图像分类系统Dlg::GUI_Quit)
	ON_LBN_SELCHANGE(IDC_LIST1, &C基于深度学习的智能图像分类系统Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_Last, &C基于深度学习的智能图像分类系统Dlg::OnBnClickedButtonLast)
	ON_BN_CLICKED(IDC_BUTTON_Next, &C基于深度学习的智能图像分类系统Dlg::OnBnClickedButtonNext)
END_MESSAGE_MAP()


// C基于深度学习的智能图像分类系统Dlg 消息处理程序

BOOL C基于深度学习的智能图像分类系统Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	//pageMain->ShowWindow(SW_SHOWNORMAL);
	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	BUTTUON_CONTRAL_CLUSTER = false;
	SetTimer(1,10,NULL);

	namedWindow("window", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("window");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_Pic_PageMain)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);

	namedWindow("window_temp", WINDOW_AUTOSIZE);
	hWnd = (HWND)cvGetWindowHandle("window_temp");
	hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_pageMainPic_temp)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	//添加按钮图片
	//HBITMAP   hBitmap;
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDB_BITMAP6)); // IDB_BITMAP_TEST为资源图片ID 
	//((CButton *)GetDlgItem(IDC_BUTTON_DeRepetit))->SetBitmap(hBitmap);
	//
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)); // IDB_BITMAP_TEST为资源图片ID 
	//((CButton *)GetDlgItem(IDC_Folder_Out))->SetBitmap(hBitmap);
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)); // IDB_BITMAP_TEST为资源图片ID 
	//((CButton *)GetDlgItem(IDC_BUTTON_CLUSTER))->SetBitmap(hBitmap);
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP10)); // IDB_BITMAP_TEST为资源图片ID 
	//((CButton *)GetDlgItem(IDC_BUTTON_test))->SetBitmap(hBitmap);
	//hBitmap = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP11)); // IDB_BITMAP_TEST为资源图片ID 
	//((CButton *)GetDlgItem(ID_EXIT))->SetBitmap(hBitmap);
	lb_imgPath.SetHorizontalExtent(100);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C基于深度学习的智能图像分类系统Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C基于深度学习的智能图像分类系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC   dc(this);              
		CRect   rect;
		GetClientRect(&rect);		
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1); //IDB_BITMAP是你自己的图对应的ID   ，由于我刚刚加入的位图资源                        
		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap *pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C基于深度学习的智能图像分类系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void C基于深度学习的智能图像分类系统Dlg::OnBnClickedExit()
{
	// TODO:  在此添加控件通知处理程序代码
	if (MessageBox("确认退出", "", MB_YESNO | MB_ICONQUESTION) == IDYES){
		this->SendMessage(WM_CLOSE);
	}
}

void C基于深度学习的智能图像分类系统Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnTimer(nIDEvent);
}

HBRUSH C基于深度学习的智能图像分类系统Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//if (nCtlColor == CTLCOLOR_LISTBOX)
	//{
	//	pDC->SetBkMode(TRANSPARENT);
	//	return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	//}
	if (nCtlColor == CTLCOLOR_BTN)
	{
		pDC->SetBkMode(TRANSPARENT);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	if (pWnd->GetDlgCtrlID() == IDC_ShowLabel)//可以用CTLCOLOR_STATIC表示静态控件
	{
		CFont m_font;   //声明变量
		m_font.CreatePointFont(250, "宋体"); //设置字体大小和类型
		pDC->SelectObject(&m_font);       //设置字体 
		pDC->SetTextColor(RGB(255, 255, 255)); //设置字体颜色
		pDC->SetBkMode(TRANSPARENT);      //属性设置为透明
		return (HBRUSH)::GetStockObject(NULL_BRUSH); //不返回画刷
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TitleText)//可以用CTLCOLOR_STATIC表示静态控件
	{
		CFont m_font;   //声明变量
		m_font.CreatePointFont(300, "华文行楷"); //设置字体大小和类型
		pDC->SelectObject(&m_font);       //设置字体 
		pDC->SetTextColor(RGB(255, 255, 255)); //设置字体颜色
		pDC->SetBkMode(TRANSPARENT);      //属性设置为透明
		return (HBRUSH)::GetStockObject(NULL_BRUSH); //不返回画刷
	}
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_Window_Picshow || pWnd->GetDlgCtrlID() == IDC_STATIC || pWnd->GetDlgCtrlID() == IDC_STATIC_Text_Num)//可以用CTLCOLOR_STATIC表示静态控件
	{
		CFont m_font;   //声明变量
		m_font.CreatePointFont(100, "宋体"); //设置字体大小和类型
		pDC->SelectObject(&m_font);       //设置字体 
		pDC->SetTextColor(RGB(255, 255, 255)); //设置字体颜色
		pDC->SetBkMode(TRANSPARENT);      //属性设置为透明
		return (HBRUSH)::GetStockObject(NULL_BRUSH); //不返回画刷
	}
	// TODO:  在此更改 DC 的任何特性
	//if (nCtlColor == CTLCOLOR_STATIC){
	//	pDC->SetTextColor(RGB(255, 255, 255)); //设置字体为白色
	//	pDC->SetBkMode(TRANSPARENT);         //设置背景为透明
	//	return (HBRUSH)::GetStockObject(NULL_BRUSH);
	//}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void C基于深度学习的智能图像分类系统Dlg::ReadDatasetFromFolder()
{
	// TODO:  在此添加命令处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	TCHAR   szFolderPath[MAX_PATH] = { 0 };
	CString strFolderPath = TEXT("");

	BROWSEINFO sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;
	//显示文件夹选择对话框
	LPITEMIDLIST lpidBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidBrowse != NULL) {
		//取得文件夹名
		if (::SHGetPathFromIDList(lpidBrowse, szFolderPath)) {
			strFolderPath = szFolderPath;
			folder_read_path = strFolderPath;
		}
	}
	if (lpidBrowse != NULL) {
		::CoTaskMemFree(lpidBrowse);
	}
	//显示图片绝对路径信息到ListBox上。
	BasicFuncation basic;
	imagePath = basic.GetIndex(folder_read_path + "/");
	for (int i = 0; i < imagePath.size(); i++){
		lb_imgPath.AddString(imagePath.at(i).c_str());
	}
}


void C基于深度学习的智能图像分类系统Dlg::SelectOutputFolder()
{
	// TODO:  在此添加命令处理程序代码

	// TODO: 在此添加控件通知处理程序代码
	string path;
	TCHAR   szFolderPath[MAX_PATH] = { 0 };
	CString strFolderPath = TEXT("");

	BROWSEINFO sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;
	//显示文件夹选择对话框
	LPITEMIDLIST lpidBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidBrowse != NULL) {
		//取得文件夹名
		if (::SHGetPathFromIDList(lpidBrowse, szFolderPath)) {
			strFolderPath = szFolderPath;
			folder_write_path = strFolderPath;
		}
	}
	if (lpidBrowse != NULL) {
		::CoTaskMemFree(lpidBrowse);
	}
}


void C基于深度学习的智能图像分类系统Dlg::StartRecognize()
{
	pageMain = new PageMain();
	pageMain->Create(IDD_DIALOG_Main, this);
	pageMain->ShowWindow(SW_SHOWNORMAL);
	if (folder_read_path.size() > 0){
		BUTTUON_CONTRAL_CLUSTER = true;
		BasicFuncation basic;
		basic.getImagesPath(folder_read_path + "/");
		vector<Mat> images = basic.getImageMatList();
		pageMain->SetImgVec(images);
	}
}
void C基于深度学习的智能图像分类系统Dlg::StartCluster()
{
	pageCluster = new PageCluster();
	pageCluster->Create(IDD_DIALOG_Cluster, this);
	pageCluster->ShowWindow(SW_SHOWNORMAL);
	pageCluster->SetPath(folder_write_path);
}


void C基于深度学习的智能图像分类系统Dlg::StartDerepet()
{
	AllocConsole();
	freopen("CONOUT$", "w+t", stdout);
	freopen("CONIN$", "r+t", stdin);
	string fold_path = folder_write_path + "/folder_name.txt";
	fstream file;
	vector<string> folder_path;
	string str;
	file.open(fold_path, ios::in);
	while (getline(file, str)){
		cout << "正在对" << str << "类别的图像进行去重工作！" << endl;
		str = folder_write_path + "\\" + str;
		string cmd = "tools\\图片查重.exe " + str + "\\" + " 0.1";
		system((char*)cmd.data());
	}
}


void C基于深度学习的智能图像分类系统Dlg::GUI_Quit()
{
	// TODO:  在此添加控件通知处理程序代码
	if (MessageBox("确认退出", "", MB_YESNO | MB_ICONQUESTION) == IDYES){
		this->SendMessage(WM_CLOSE);
	}
}

void C基于深度学习的智能图像分类系统Dlg::OnLbnSelchangeList1()
{
	int nIndex = lb_imgPath.GetCurSel();
	selectedImgIndex = nIndex;
	if (nIndex >= 0) {
		CString cs;
		lb_imgPath.GetText(nIndex, cs);
		string str = imagePath.at(nIndex);
		// 在这里操作
		Mat image = imread((string)cs);
		
		imshow("window", GetImgMask(image, Size(270, 270)));
		waitKey(10);
		//AfxMessageBox(cs);
	}
}


void C基于深度学习的智能图像分类系统Dlg::OnBnClickedButtonLast()
{
	selectedImgIndex--;
	string str = imagePath.at(selectedImgIndex);
	// 在这里操作
	Mat image = imread(str);
	imshow("window", GetImgMask(image, Size(270, 270)));
	//判断当前的图片位置
	if (selectedImgIndex > 0)
	{
		imshow("window_temp", GetImgTemp(selectedImgIndex));
	}
	waitKey(10);
}
void C基于深度学习的智能图像分类系统Dlg::OnBnClickedButtonNext()
{
	selectedImgIndex++;
	string str = imagePath.at(selectedImgIndex);
	// 在这里操作
	Mat image = imread(str);
	imshow("window", GetImgMask(image, Size(270, 270)));
	if (selectedImgIndex > 0 && selectedImgIndex<(imagePath.size() - 8))
	{
		imshow("window_temp", GetImgTemp(selectedImgIndex));
	}
	else if (selectedImgIndex>(imagePath.size() - 8)){
		imshow("window_temp", GetImgTemp(imagePath.size() - 8));
	}
	waitKey(10);
}
Mat C基于深度学习的智能图像分类系统Dlg::GetImgMask(Mat image, Size size){
	int s;
	if (image.rows > image.cols) {
		s = image.rows;
	}
	else {
		s = image.cols;
	}
	Mat image_temp_ep(s, s, CV_8UC3, Scalar(255, 255, 255));
	Mat image_temp_ep_roi = image_temp_ep(Rect((s - image.cols) / 2, (s - image.rows) / 2, image.cols, image.rows));
	Mat dstNormImg;
	addWeighted(image_temp_ep_roi, 0., image, 1.0, 0., image_temp_ep_roi);
	resize(image_temp_ep, dstNormImg, size, 0, 0, 1);    //大小归一化
	return dstNormImg;
}
Mat C基于深度学习的智能图像分类系统Dlg::GetImgTemp(int index){
	Mat image_temp_ep (55, 475,CV_8UC3, Scalar(255, 255, 255));
	Mat result;

	for (int i = 0; i < 8; i++){
		string str = imagePath.at(index+i);
		Mat image = imread(str);
		Mat img;
		image=GetImgMask(image, Size(270, 270));
		resize(image, img, Size(55,55), 0, 0, 1);    //大小归一化

		Mat image_temp_ep_roi = image_temp_ep(Rect(i* 60,0, 55, 55));
		addWeighted(image_temp_ep_roi, 0., img, 1.0, 0., image_temp_ep_roi);

	}
	return image_temp_ep;
}