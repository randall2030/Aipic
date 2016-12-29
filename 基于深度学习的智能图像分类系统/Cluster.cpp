#include "stdafx.h"
#include "Cluster.h"


Cluster::Cluster()
{

}
void Cluster::cluster(string outpath) {
	readImagePathAndClassNameFile("resultForCluster.txt");
	fstream file_out;
	fstream file_out_1;
	file_out.open("cluster.txt", ios::out);
	file_out_1.open("cluster_label.txt", ios::out);

	vector<PIC> pic_cluster;
	vector<string> pic_class_name;

	/*for (int i = 0; i < images_list.size(); i++)*/
	//每一次识别的是一个类别
	//每次创建一个文件夹，存放对应类别的图片
	//string folder = "cluster_result\\";
	while (!images_list.empty()) {
		PIC picture = images_list.at(0);
		//每一类图片的信息
		clust cl;
		cl.cluster_name = picture.label;
		cl.number = 0;

		vector<PIC>::iterator iter;
		system((char*)("mkdir "+ outpath+"\\" + picture.label).data());
		//查找picture.label写入文件
		//for (int i = 0; i < picture.label.size(); i++){
		//	if (picture.label.at(i) == '\t') {
		//		picture.label.at(i)='\0';
		//	}
		//}
		pic_class_name.push_back(picture.label);
		for (int i = 0; i < images_list.size(); i++) {
			if (images_list.at(i).label == picture.label) {
				file_out << images_list.at(i).name << " " << images_list.at(i).label << endl;
				pic_cluster.push_back(images_list.at(i) );
				Mat image = imread(images_list.at(i).name);
				vector<string> image_path = split(images_list.at(i).name, "/");
				//imshow(image_path.at(image_path.size()-1), image);
				string path = outpath+"/" + picture.label + "/" + image_path.at(image_path.size() - 1);
				imwrite(path, image);
				//waitKey(50);
				cl.number++;
			}
		}
		image_cluster.push_back(cl);
		//查找picture.label删除元素
		for (iter = images_list.begin(); iter != images_list.end(); ) {
			if ((*iter).label == picture.label) {
				images_list.erase(iter);
			}
			else {
				++iter;
			}
		}
	}
	
}
vector<Cluster::clust> Cluster::getClusterMessage() {
	return image_cluster;
}
vector<string> Cluster::split(string str, string pattern) {
	string::size_type pos;
	vector<string> result;
	str += pattern;
	int size = str.size();

	for (int i = 0; i < size; i ++ ) {
		pos = str.find(pattern,i);
		if (pos < size) {
			string s = str.substr(i,pos-i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

void Cluster::readImagePathAndClassNameFile(string filepath) {
	fstream file_in;
	file_in.open(filepath,ios::in);
	string line;
	PIC picture;
	while (getline(file_in, line)) {
		vector<string> sp=split(line," ");
		picture.name = sp.at(0);
		picture.label = sp.at(1);
		images_list.push_back(picture);
	}
	//sort(images_list.begin(), images_list.end());
	//sort();
	file_in.close();
}
void Cluster::sort() {
	PIC pic_temp;
	for (int i = 0; i < images_list.size(); i++) {
		for (int j = 0; j < images_list.size() - i; j++) {
			if (images_list.at(j).label>images_list.at(j + 1).label) {
				pic_temp = images_list.at(j);
				images_list.at(j) = images_list.at(j + 1);
				images_list.at(j + 1) = pic_temp;
			}
		}
	}
}
Cluster::~Cluster()
{
}
