#pragma once
#include<opencv2/opencv.hpp>
#include<vector>
#include<string>
#include "wininet.h"
#include <direct.h>
#include<fstream>
#include <list>
#pragma comment(lib,"Wininet.lib")

using namespace std;
using namespace cv;
class BasicFuncation
{
public:
	BasicFuncation();
	vector<string> getImagesPath(string folder_path);

	vector<string> GetIndex(string folder_path);

	vector<Mat> getImageMatList();
	string BasicFuncation::getString(float src);

	~BasicFuncation();
private:
	struct PathElem{
		TCHAR   SrcImgPath[MAX_PATH * 2];
		TCHAR   RstImgPath[MAX_PATH * 2];
	};
	vector<Mat> image_list;
	int FindImgs(char * pSrcImgPath, char * pRstImgPath, std::list<PathElem> &ImgList);
};

