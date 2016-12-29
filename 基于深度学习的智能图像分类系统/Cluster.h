#pragma once
//实现对已识别的图片分组
#include"common.h"
#include <direct.h> 
#include<windows.h>
class Cluster
{
public:
	Cluster();
	typedef struct {
		string cluster_name;
		int number;
	}clust;
	void cluster(string outpath);
	vector<Cluster::clust> getClusterMessage();
	~Cluster();
private:
	typedef struct{
		string name;
		string label;
	}PIC;

	vector<PIC> images_list;
	vector<clust> image_cluster;
	//字符串分割
	vector<string> split(string str,string pattern);
	//读取图片文件路径 和 类别
	void readImagePathAndClassNameFile(string filepath);
	void sort();
};

