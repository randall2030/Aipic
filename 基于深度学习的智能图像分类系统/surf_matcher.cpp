#include "stdafx.h"
#include"surf_matcher.h"
int matchUseSURF(vector<Mat> image_list) {
	//【0】改变console字体颜色
	BasicFuncation basic_funcation;
	for (int tcount = 0; tcount < image_list.size(); tcount++) {
		for (int count = 0; count < image_list.size(); count++) {
			//【1】载入素材图
			// int count = 0;
			Mat srcImage1 = image_list.at(tcount);
			Mat srcImage2 = image_list.at(count);
			if (!srcImage1.data || !srcImage2.data)
			{
				printf("读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"); return false;
			}

			//【2】使用SURF算子检测关键点
			int minHessian = 500;//SURF算法中的hessian阈值
			SURFDetector detector;//定义一个SurfFeatureDetector（SURF） 特征检测类对象 
			SURFDetector surf;

			SURFMatcher<BFMatcher> matcher;

			vector<KeyPoint> keyPoint1, keyPoints2;//vector模板类，存放任意类型的动态数组

												   //【3】调用detect函数检测出SURF特征关键点，保存在vector容器中
			//detector.detect(srcImage1, keyPoint1);
			//detector.detect(srcImage2, keyPoints2);

			//【4】计算描述符（特征向量）
			//SurfDescriptorExtractor extractor;
			Mat descriptors1, descriptors2;
			//extractor.compute(srcImage1, keyPoint1, descriptors1);
			//extractor.compute(srcImage2, keyPoints2, descriptors2);
			vector< DMatch > matches;
			vector<DMatch> matches_1;

			surf(srcImage1,Mat(), keyPoint1, descriptors1);
			surf(srcImage2, Mat(), keyPoints2, descriptors2);

			//【5】使用BruteForce进行匹配
			// 实例化一个匹配器
			//BruteForceMatcher< L1<float> > matcher;

			//匹配两幅图中的描述子（descriptors）
			if (keyPoint1.size() == 0 || keyPoints2.size() == 0) {
				cout << "图片未检索到特征点：" << count << endl;
			}
			else {

				matcher.match(descriptors1, descriptors2, matches);
				matcher.match(descriptors2, descriptors1, matches_1);

				//matcher.match(descriptors1, descriptors2, matches);
				//matcher.match(descriptors2, descriptors1, matches_1);
				/*matches = matchSimolify(matches, matches_1);
				for (int i = 0; i < matches.size(); i++){

				cout << matches.at(i).queryIdx << "," << matches.at(i).trainIdx << "        ++distance:" << matches.at(i).distance << endl;
				}*/
				//【6】绘制从两个图像中匹配出的关键点
				Mat imgMatches;
				Mat imgMatches_1;
				double distance = 0.0;
				for (int i = 0; i < matches.size(); i++) {
					distance += matches.at(i).distance;
					cout << matches.at(i).queryIdx << "," << matches.at(i).trainIdx << "        distance:" << matches.at(i).distance << endl;
				}
				cout << matches.at(0).imgIdx << "        distance:" << distance << endl;
				for (int i = 0; i < matches_1.size(); i++) {
					cout << matches_1.at(i).queryIdx << "," << matches_1.at(i).trainIdx << "        distance:" << matches_1.at(i).distance << endl;
				}
				//cout << "--->" << tcount << "+" << count <<"-->"<< matches.size() << endl;
				drawMatches(srcImage1, keyPoint1, srcImage2, keyPoints2, matches, imgMatches);//进行绘制
				drawMatches(srcImage2, keyPoints2, srcImage1, keyPoint1, matches_1, imgMatches_1);//进行绘制
				string windowname = basic_funcation.getString(tcount) + "-" + basic_funcation.getString(count);
				string windowname_1 = windowname + "_1";
				//【7】显示效果图
				namedWindow(windowname, WINDOW_NORMAL);
				namedWindow(windowname_1, WINDOW_NORMAL);

				imshow(windowname, imgMatches);
				imshow(windowname_1, imgMatches_1);

			}



		}
	}
	waitKey(100);
	return 0;
}
int m_SURF(Mat leftimages,Mat rightimages) {
		vector<KeyPoint> key_points_left;
		vector<KeyPoint> key_points_right;

		Mat descriptor_left;
		Mat descriptor_right;

		vector<DMatch> matches;

		//Ptr<Feature2D> surf = xfeatures2d::SURF::create();
		Ptr<Feature2D> sift=SIFT::create(800);
		
		sift->detect(leftimages,key_points_left);
		//surf->detectAndCompute(leftimages, noArray(), key_points_left, descriptor_left);
		//surf->detectAndCompute(rightimages, noArray(), key_points_right, descriptor_right);

		//matches.clear();
		//match_features_FLANN
		//match_features(descriptor, descriptor,matches);
		//match_features_FLANN(descriptor_left, descriptor_right, matches);
		//Mat result;
		//drawMatches(leftimages, key_points_left, rightimages, key_points_right, matches, result);
		//imshow("result",result);
		//surf.release();
		//matches.clear();
		//key_points_left.clear();
		//key_points_right.clear();
		//waitKey(0);
	return 1;
}
//int SIFT() {
//
//	Mat srcImage = imread("mofang1.jpg");
//	imshow("【原图】", srcImage);
//
//	//对BGR空间的图像直接进行计算很费时间，所以，需要转换为灰度图
//	Mat srcGrayImage;
//	cvtColor(srcImage, srcGrayImage, CV_BGR2GRAY);
//
//	//首先对两幅图像进行特征点的检测和描述子的计算
//	vector<KeyPoint> keyPoint1;
//	//这里用SURF会更加快
//	SURF surf(2000);
//	surf.detect(srcGrayImage, keyPoint1);
//	Mat descriImage1;
//	surf.compute(srcGrayImage, keyPoint1, descriImage1);
//
//	//先对原图的描述子进行保留
//	BFMatcher FLMatcher;
//	//因为FlannBasedMatcher类的成员函数add()的参数是一个vector<Mat>的容器，所以先定义一个这样的变量，并将原图的描述子放入容器中
//	vector<Mat> g_vdescriImage1(1, descriImage1);
//	/*g_vdescriImage1.push_back(descriImage1);*/
//	//调用FlannBasedMatcher类的成员函数add，将原图的描述子放在FlannBasedMatcher的对象FLMatcher中
//	FLMatcher.add(g_vdescriImage1);
//	//...........................................................
//	FLMatcher.train();
//
//	VideoCapture capture;
//	capture.open(0);
//
//	Mat frameImage, frameGrayImage;
//	while (waitKey(1) != 27)
//	{
//		capture >> frameImage;
//
//		//为了提高计算效率，将图像转换为灰度图像
//		cvtColor(frameImage, frameGrayImage, CV_BGR2GRAY);
//
//		//计算特征点和描述子
//		vector<KeyPoint> keyPoints2;
//		surf.detect(frameGrayImage, keyPoints2);
//		Mat descriImage2;
//		surf.compute(frameGrayImage, keyPoints2, descriImage2);
//
//		//将之前得到的原图的描述子和现在得到的描述子进行匹配
//		//成员函数knnMatch的参数是二维的DMatch向量，所以首先定义一个该容器的向量
//		vector<vector<DMatch>> knnDMatches;
//		//用之前已经存放原图描述子的对象来计算
//		FLMatcher.knnMatch(descriImage2, knnDMatches, 2);
//
//		//采集优秀的匹配点
//		vector<DMatch> goodMatches;
//		for (size_t i = 0; i < knnDMatches.size(); i++)
//		{
//			//........................................................................
//			if (knnDMatches[i][0].distance < 0.6 * knnDMatches[i][1].distance)
//			{
//				goodMatches.push_back(knnDMatches[i][0]);
//			}
//		}
//
//		Mat dstImage;
//		drawMatches(frameImage, keyPoints2, srcImage, keyPoint1, goodMatches, dstImage);
//
//		imshow("【结果图】", dstImage);
//	}
//
//}
void match_features_knn(Mat& query, Mat& train, vector<DMatch>& matches)
{
	flann::Index flannIndex(query, flann::LshIndexParams(12, 20, 2), cvflann::FLANN_DIST_HAMMING);
	Mat matchindex(train.rows, 2, CV_32SC1);
	Mat matchdistance(train.rows, 2, CV_32FC1);
	flannIndex.knnSearch(train, matchindex, matchdistance, 2, flann::SearchParams());
	//根据劳氏算法
	for (int i = 0; i < matchdistance.rows; i++)
	{
		if (matchdistance.at<float>(i, 0) < 0.6*matchdistance.at<float>(i, 1))
		{
			DMatch dmatches(matchindex.at<int>(i, 0), i, matchdistance.at<float>(i, 0));
			matches.push_back(dmatches);
		}
	}
}

void match_features_FLANN(Mat& query, Mat& train, vector<DMatch>& matches)
{
	FlannBasedMatcher matcher;

	/*vector<DMatch> match;
	matcher.match(query, train, match);
	double max_dist = 0;
	double min_dist = 100;
	for (int i = 0; i < match.size(); i++)
	{
	double dist = match[i].distance;
	if (dist < min_dist) min_dist = dist;
	if (dist > max_dist) max_dist = dist;
	}
	for (int i = 0; i < match.size(); i++)
	{
	if (match[i].distance < 2 * min_dist) matches.push_back(match[i]);
	}*/

	vector<vector<DMatch>> knn_matches;
	matcher.knnMatch(query, train, knn_matches, 2);

	//获取满足Ratio Test的最小匹配的距离
	float min_dist = FLT_MAX;
	for (int r = 0; r < knn_matches.size(); ++r)
	{
		//Ratio Test
		if (knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance)
			continue;

		float dist = knn_matches[r][0].distance;
		if (dist < min_dist) min_dist = dist;
	}

	matches.clear();
	for (size_t r = 0; r < knn_matches.size(); ++r)
	{
		//排除不满足Ratio Test的点和匹配距离过大的点
		if (
			knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance ||
			knn_matches[r][0].distance > 5 * max(min_dist, 10.0f)
			)
			continue;

		//保存匹配点
		matches.push_back(knn_matches[r][0]);
	}

}
void match_features(Mat& query, Mat& train, vector<DMatch>& matches)
{
	vector<vector<DMatch>> knn_matches;
	BFMatcher matcher(NORM_L2);

	//matcher.knnMatch(query, train, knn_matches, 2);
	matcher.knnMatch(query,knn_matches,2);
	//获取满足Ratio Test的最小匹配的距离
	float min_dist = FLT_MAX;
	for (int r = 0; r < knn_matches.size(); ++r)
	{
		//Ratio Test
		if (knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance)
			continue;

		float dist = knn_matches[r][0].distance;
		if (dist < min_dist) min_dist = dist;
	}

	matches.clear();
	for (size_t r = 0; r < knn_matches.size(); ++r)
	{
		//排除不满足Ratio Test的点和匹配距离过大的点
		if (
			knn_matches[r][0].distance > 0.6*knn_matches[r][1].distance ||
			knn_matches[r][0].distance > 5 * max(min_dist, 10.0f)
			)
			continue;

		//保存匹配点
		matches.push_back(knn_matches[r][0]);
	}
}
bool refineMatchesWithHomography(const std::vector<cv::KeyPoint>& queryKeypoints, const std::vector<cv::KeyPoint>& trainKeypoints,
	float reprojectionThreshold, std::vector<cv::DMatch>& matches, cv::Mat& homography)
{
	const int minNumberMatchesAllowed = 8;
	if (matches.size() < minNumberMatchesAllowed)
		return false;
	// Prepare data for cv::findHomography  
	std::vector<cv::Point2f> srcPoints(matches.size());
	std::vector<cv::Point2f> dstPoints(matches.size());
	for (size_t i = 0; i < matches.size(); i++)
	{
		srcPoints[i] = trainKeypoints[matches[i].trainIdx].pt;
		dstPoints[i] = queryKeypoints[matches[i].queryIdx].pt;
		//srcPoints[i] = trainKeypoints[i].pt;
		//dstPoints[i] = queryKeypoints[i].pt;
	}
	// Find homography matrix and get inliers mask  
	std::vector<unsigned char> inliersMask(srcPoints.size());
	homography = cv::findHomography(srcPoints, dstPoints, CV_FM_RANSAC, reprojectionThreshold, inliersMask);
	std::vector<cv::DMatch> inliers;
	for (size_t i = 0; i<inliersMask.size(); i++)
	{
		if (inliersMask[i])
			inliers.push_back(matches[i]);
	}
	matches.swap(inliers);
	return matches.size() > minNumberMatchesAllowed;
}
