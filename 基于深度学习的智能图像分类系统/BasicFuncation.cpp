#include "stdafx.h"
#include "BasicFuncation.h"


BasicFuncation::BasicFuncation()
{
}
vector<string> BasicFuncation::GetIndex(string folder_path){
	std::list<PathElem> ImgList;
	std::list<PathElem>::iterator pImgListTemp;
	char* srcpath = (char*)folder_path.data();
	vector<string> list;
	ImgList.clear();
	FindImgs(srcpath, srcpath, ImgList);
	pImgListTemp = ImgList.begin();
	for (int iik = 1; iik <= ImgList.size(); iik++)
	{
		list.push_back(pImgListTemp->RstImgPath);
		pImgListTemp++;
	}
	return list;
}
vector<string> BasicFuncation::getImagesPath(string folder_path){
	std::list<PathElem> ImgList;
	std::list<PathElem>::iterator pImgListTemp;
	char* srcpath = (char*)folder_path.data();
	fstream file_out;
	file_out.open("images_path.txt",ios::out);
	vector<string> list;
	ImgList.clear();
	FindImgs(srcpath, srcpath, ImgList);
	pImgListTemp = ImgList.begin();

	for (int iik = 1; iik <= ImgList.size(); iik++)
	{
		Mat image = imread(pImgListTemp->RstImgPath);
		if (!image.empty()){
			image_list.push_back(image);
			file_out.write(pImgListTemp->RstImgPath, strlen(pImgListTemp->RstImgPath));
			file_out.write("\n", 1);
		}
		list.push_back(pImgListTemp->RstImgPath);
		pImgListTemp++;
	}
	file_out.close();
	return list;
}
vector<Mat> BasicFuncation::getImageMatList(){
	return image_list;
}
int BasicFuncation::FindImgs(char * pSrcImgPath, char * pRstImgPath, std::list<PathElem> &ImgList){
	//源图片存在的目录
	TCHAR   szFileT1[MAX_PATH * 2];
	lstrcpy(szFileT1, TEXT(pSrcImgPath));
	lstrcat(szFileT1, TEXT("*.*"));

	//结果图片存放的目录
	TCHAR   RstAddr[MAX_PATH * 2];
	lstrcpy(RstAddr, TEXT(pRstImgPath));
	//_mkdir(RstAddr);   //创建文件夹

	WIN32_FIND_DATA   wfd;
	HANDLE   hFind = FindFirstFile(szFileT1, &wfd);

	PathElem stPathElemTemp;
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (wfd.cFileName[0] == TEXT('.'))
				continue;
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY || strcmp("Thumbs.db", TEXT(wfd.cFileName)) == 0)
			{
				;
			}
			else
			{

				TCHAR   SrcImgPath[MAX_PATH * 2];
				lstrcpy(SrcImgPath, pSrcImgPath);
				lstrcat(SrcImgPath, TEXT(wfd.cFileName));

				lstrcpy(stPathElemTemp.SrcImgPath, SrcImgPath);

				TCHAR   AdressTemp[MAX_PATH * 2];
				lstrcpy(AdressTemp, pRstImgPath);

				//lstrcat(AdressTemp, TEXT("/"));  
				lstrcat(AdressTemp, TEXT(wfd.cFileName));
				lstrcpy(stPathElemTemp.RstImgPath, AdressTemp);

				ImgList.push_back(stPathElemTemp);

			}
		} while (FindNextFile(hFind, &wfd));
	}
	else
	{
		return -1;
	}
	return 0;
}
BasicFuncation::~BasicFuncation()
{
}
string BasicFuncation::getString(float src) {
	char buffer[20];
	//string 类型
	string dst;
	string str;
	sprintf_s(buffer, "%f", src);
	str = buffer;
	dst = str.substr(0, 3);
	return dst;
}
