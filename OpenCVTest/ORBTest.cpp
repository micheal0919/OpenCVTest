#include <string>
#include <vector>

#include <glog/logging.h>
#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>

TEST(ORBTest, OneImg)
{
	std::string img_path = "../data/images/000000.jpg";
	cv::Mat img = cv::imread(img_path);
	//cv::namedWindow("TestWin", cv::WINDOW_AUTOSIZE);
	//cv::imshow("TestWin", img);
	//cv::waitKey();

	cv::Ptr<cv::ORB> orb_detector = cv::ORB::create(1000);
	std::vector<cv::KeyPoint> kpts;
	cv::Mat desc;
	orb_detector->detectAndCompute(img, cv::noArray(), kpts, desc);

	cv::Mat img_kpts;
	cv::drawKeypoints(img, kpts, img_kpts, cv::Scalar::all(-1), cv::DrawMatchesFlags::DEFAULT);
	cv::namedWindow("TestWin", cv::WINDOW_AUTOSIZE);
	cv::imshow("TestWin", img_kpts);
	cv::waitKey();

	EXPECT_TRUE(true);
}