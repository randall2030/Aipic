#pragma once
#include "common.h"
#include<cstdlib>
#include<opencv2\dnn.hpp>
using namespace cv::dnn;
class Caffe
{
public:
	Caffe();
	//识别图片类别，给出图片内容关键词
	vector<string> recognize();
	string Recognize(Mat image);
	vector<String> Recognize(vector<Mat> image);
	//加载图片数据，位于文件夹内、传入参数
	int load(string folderpath);
	int load(Mat image);
	int load(vector<Mat> images);
	//获取识别后的图片内容标签
	void getKeyWorld();
	~Caffe();
private:
	bool Init();
	//网络
	dnn::Net net;

	//用于测试的图片列表
	vector<Mat> image_list;
	//图片识别后的内容标签
	vector<string> image_keyworld;

	/* Find best class for the blob (i. e. class with maximal probability) */
	void getMaxClass(dnn::Blob &probBlob, int *classId, double *classProb);
	//读取类别名称至 vector 内
	std::vector<string> readClassNames(const char *filename );

};

