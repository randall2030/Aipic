#include"stdafx.h"
#include "ImageMatch.h"


ImageMatch::ImageMatch()
{
}
void ImageMatch::match(Mat srcImage, Mat dstImage, int METHOD){
	switch (METHOD){
	case SURF:
		matchUseSURF(srcImage, dstImage);
		break;
	case SIFT:
		break;
	case SURF_CUDA:
		matchUseSURF_CUDA(srcImage,dstImage);
		break;
	case TEMPLATE:
		matchUseTemplate(srcImage, dstImage);
		break;
	}
}
Mat ImageMatch::drawGoodMatches(
	const Mat& img1,
	const Mat& img2,
	const std::vector<KeyPoint>& keypoints1,
	const std::vector<KeyPoint>& keypoints2,
	std::vector<DMatch>& matches,
	std::vector<Point2f>& scene_corners_
	)
{
	//-- Sort matches and preserve top 10% matches
	std::sort(matches.begin(), matches.end());
	std::vector< DMatch > good_matches;
	double minDist = matches.front().distance;
	double maxDist = matches.back().distance;

	const int ptsPairs = std::min(GOOD_PTS_MAX, (int)(matches.size() * GOOD_PORTION));
	for (int i = 0; i < ptsPairs; i++)
	{
		good_matches.push_back(matches[i]);
	}
	std::cout << "\nMax distance: " << maxDist << std::endl;
	std::cout << "Min distance: " << minDist << std::endl;

	std::cout << "Calculating homography using " << ptsPairs << " point pairs." << std::endl;

	// drawing the results
	Mat img_matches;

	drawMatches(img1, keypoints1, img2, keypoints2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	//-- Localize the object
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;

	for (size_t i = 0; i < good_matches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		obj.push_back(keypoints1[good_matches[i].queryIdx].pt);
		scene.push_back(keypoints2[good_matches[i].trainIdx].pt);
	}
	//-- Get the corners from the image_1 ( the object to be "detected" )
	std::vector<Point2f> obj_corners(4);
	obj_corners[0] = Point(0, 0);
	obj_corners[1] = Point(img1.cols, 0);
	obj_corners[2] = Point(img1.cols, img1.rows);
	obj_corners[3] = Point(0, img1.rows);
	std::vector<Point2f> scene_corners(4);

	Mat H = findHomography(obj, scene, RANSAC);
	perspectiveTransform(obj_corners, scene_corners, H);

	scene_corners_ = scene_corners;

	//-- Draw lines between the corners (the mapped object in the scene - image_2 )
	line(img_matches,
		scene_corners[0] + Point2f((float)img1.cols, 0), scene_corners[1] + Point2f((float)img1.cols, 0),
		Scalar(0, 255, 0), 2, LINE_AA);
	line(img_matches,
		scene_corners[1] + Point2f((float)img1.cols, 0), scene_corners[2] + Point2f((float)img1.cols, 0),
		Scalar(0, 255, 0), 2, LINE_AA);
	line(img_matches,
		scene_corners[2] + Point2f((float)img1.cols, 0), scene_corners[3] + Point2f((float)img1.cols, 0),
		Scalar(0, 255, 0), 2, LINE_AA);
	line(img_matches,
		scene_corners[3] + Point2f((float)img1.cols, 0), scene_corners[0] + Point2f((float)img1.cols, 0),
		Scalar(0, 255, 0), 2, LINE_AA);
	return img_matches;
}
void ImageMatch::matchUseSURF_CUDA(Mat leftImage, Mat rightImage){
	GpuMat img1(leftImage);
	GpuMat img2(rightImage);
	cv::cuda::printShortCudaDeviceInfo(cv::cuda::getDevice());
	cuda::SURF_CUDA surf;
	// detecting keypoints & computing descriptors
	GpuMat keypoints1GPU, keypoints2GPU;
	GpuMat descriptors1GPU, descriptors2GPU;
	surf(img1, GpuMat(), keypoints1GPU, descriptors1GPU);
	surf(img2, GpuMat(), keypoints2GPU, descriptors2GPU);

	cout << "FOUND " << keypoints1GPU.cols << " keypoints on first image" << endl;
	cout << "FOUND " << keypoints2GPU.cols << " keypoints on second image" << endl;
	// matching descriptors
	Ptr<cv::cuda::DescriptorMatcher> matcher = cv::cuda::DescriptorMatcher::createBFMatcher(surf.defaultNorm());
	vector<DMatch> matches;
	matcher->match(descriptors1GPU, descriptors2GPU, matches);
	// downloading results
	vector<KeyPoint> keypoints1, keypoints2;
	vector<float> descriptors1, descriptors2;
	surf.downloadKeypoints(keypoints1GPU, keypoints1);
	surf.downloadKeypoints(keypoints2GPU, keypoints2);
	surf.downloadDescriptors(descriptors1GPU, descriptors1);
	surf.downloadDescriptors(descriptors2GPU, descriptors2);

	// drawing the results
	Mat img_matches;
	drawMatches(Mat(img1), keypoints1, Mat(img2), keypoints2, matches, img_matches);

	namedWindow("matches", 0);
	imshow("matches", img_matches);
	waitKey(0);
}
void ImageMatch::matchUseSURF(Mat srcImage, Mat dstImage){
	Mat image1, image2;
	int64 work_begin = 0;
	int64 work_end = 0;
	//cvtColor(srcImage,image1,CV_RGB2GRAY);
	//cvtColor(dstImage, image2, CV_RGB2GRAY);
	UMat img1,img2;
	srcImage.copyTo(img1);
	dstImage.copyTo(img2);
	double surf_time = 0.;
	//declare input/output
	std::vector<KeyPoint> keypoints1, keypoints2;
	std::vector<DMatch> matches;

	UMat _descriptors1, _descriptors2;
	Mat descriptors1 = _descriptors1.getMat(ACCESS_RW),
		descriptors2 = _descriptors2.getMat(ACCESS_RW);
	//instantiate detectors/matchers
	SURFDetector surf;
	//KPMatcher matcher;
	//SURFMatcher<BFMatcher> matcher;
	//-- start of timing section
	FlannBasedMatcher matcher;
	for (int i = 0; i <= LOOP_NUM; i++)
	{
		if (i == 1) {
			work_begin = getTickCount();
		}
		surf(img1.getMat(ACCESS_READ), Mat(), keypoints1, descriptors1);
		surf(img2.getMat(ACCESS_READ), Mat(), keypoints2, descriptors2);
		matcher.match(descriptors1, descriptors2, matches);
	}
	work_end = getTickCount() - work_begin;
	std::cout << "FOUND " << keypoints1.size() << " keypoints on first image" << std::endl;
	std::cout << "FOUND " << keypoints2.size() << " keypoints on second image" << std::endl;

	surf_time = work_end / ((double)getTickFrequency())* 1000.;
	std::cout << "SURF run time: " << surf_time / LOOP_NUM << " ms" << std::endl << "\n";


	std::vector<Point2f> corner;
	Mat img_matches = drawGoodMatches(img1.getMat(ACCESS_READ), img2.getMat(ACCESS_READ), keypoints1, keypoints2, matches, corner);

	//-- Show detected matches

	namedWindow("surf matches", 0);
	imshow("surf matches", img_matches);
	imwrite("SURF.jpg", img_matches);

	//waitKey(10);
}
void ImageMatch::matchUseTemplate(Mat srcImage, Mat dstImage){

	#define WINDOW_NAME1 "【原始图片】"        //为窗口标题定义的宏 
	#define WINDOW_NAME2 "【匹配窗口】"        //为窗口标题定义的宏 

	int g_nMaxTrackbarNum = 5;
	int g_nMatchMethod=1;
	Mat templateImage = dstImage;
	Mat result;

	//【2】创建窗口
	namedWindow(WINDOW_NAME1, WINDOW_AUTOSIZE);
	namedWindow(WINDOW_NAME2, WINDOW_AUTOSIZE);

	//【2】初始化用于结果输出的矩阵
	int resultImage_cols = srcImage.cols - templateImage.cols + 1;
	int resultImage_rows = srcImage.rows - templateImage.rows + 1;
	result.create(resultImage_cols, resultImage_rows, CV_32FC1);
	//【3】进行匹配和标准化
	matchTemplate(srcImage, templateImage, result, g_nMatchMethod);
	normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
	//【4】通过函数 minMaxLoc 定位最匹配的位置
	double minValue; double maxValue; Point minLocation; Point maxLocation;
	Point matchLocation;
	minMaxLoc(result, &minValue, &maxValue, &minLocation, &maxLocation, Mat());

	//【5】对于方法 SQDIFF 和 SQDIFF_NORMED, 越小的数值有着更高的匹配结果. 而其余的方法, 数值越大匹配效果越好
	//此句代码的OpenCV2版为：
	//if( g_nMatchMethod  == CV_TM_SQDIFF || g_nMatchMethod == CV_TM_SQDIFF_NORMED )
	//此句代码的OpenCV3版为：
	if (g_nMatchMethod == TM_SQDIFF || g_nMatchMethod == TM_SQDIFF_NORMED)
	{
		matchLocation = minLocation;
	}
	else
	{
		matchLocation = maxLocation;
	}
	//【6】绘制出矩形，并显示最终结果
	rectangle(srcImage, matchLocation, Point(matchLocation.x + templateImage.cols, matchLocation.y + templateImage.rows), Scalar(0, 0, 255), 2, 8, 0);
	rectangle(result, matchLocation, Point(matchLocation.x + templateImage.cols, matchLocation.y + templateImage.rows), Scalar(0, 0, 255), 2, 8, 0);

	imshow(WINDOW_NAME1, srcImage);
	imshow(WINDOW_NAME2, result);
}
void ImageMatch::matchWithCapture(int METHOD){
	VideoCapture cap0(0);
	VideoCapture cap1(1);
	Mat img1;
	Mat img2;
	Mat img2_g;
	char key = waitKey(10);
	while ('s' != key){
		cap0 >> img1;
		cap1 >> img2;
		//imshow("imgSrc",img1);
		imshow("imgTem",img2);
		//resize(img2,img2,Size(img2.rows/2,img2.cols/2));
		img2_g = img2(Rect(img2.rows / 3, img2.cols / 3, min(img2.rows / 3, img2.cols / 3), min(img2.rows / 3, img2.cols / 3)));
		switch (METHOD)
		{
		case TEMPLATE:
			matchUseTemplate(img1, img2_g);
			break;
		case SURF:
			//matchUseSURF(img1, img2_g);
			matchUseSURF(img2_g, img1);
			break;
		default:
			break;
		}
		key = waitKey(10);
	}
}
ImageMatch::~ImageMatch()
{
}
