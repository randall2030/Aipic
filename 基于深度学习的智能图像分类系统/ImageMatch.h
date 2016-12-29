#pragma once
#include"common.h"
#include<opencv2\xfeatures2d.hpp>
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/cudafeatures2d.hpp"
#include "opencv2/xfeatures2d/cuda.hpp"
using namespace cv::xfeatures2d;
using namespace cv::cuda;
class ImageMatch
{
public:
	enum Method{ SURF, SIFT, ORB, HIST, FLANN, TEMPLATE ,SURF_CUDA};
	ImageMatch();
	void match(Mat srcImage, Mat dstImage, int METHOD);
	void matchWithCapture(int METHOD);
	~ImageMatch();
private:
	//SURF²ÎÊý
	const int LOOP_NUM = 10;
	const int GOOD_PTS_MAX = 50;
	const float GOOD_PORTION = 0.15f;


	typedef struct SURFDetector
	{
		Ptr<Feature2D> surf;
		SURFDetector(double hessian = 800.0)
		{
			surf = SURF::create(hessian);
		}
		template<class T>
		void operator()(const T& in, const T& mask, std::vector<cv::KeyPoint>& pts, T& descriptors, bool useProvided = false)
		{
			surf->detectAndCompute(in, mask, pts, descriptors, useProvided);
		}
	}SURFDetector;
	template<class KPMatcher>
	struct SURFMatcher
	{
		KPMatcher matcher;
		template<class T>
		void match(const T& in1, const T& in2, std::vector<cv::DMatch>& matches)
		{
			matcher.match(in1, in2, matches);
		}
	};

	void matchUseTemplate(Mat srcImage, Mat dstImage);
	void matchUseSURF(Mat srcImage, Mat dstImage);
	void matchUseSURF_CUDA(Mat leftImage, Mat rightImage);
	Mat drawGoodMatches(
		const Mat& img1,
		const Mat& img2,
		const std::vector<KeyPoint>& keypoints1,
		const std::vector<KeyPoint>& keypoints2,
		std::vector<DMatch>& matches,
		std::vector<Point2f>& scene_corners_
		);
	
};

