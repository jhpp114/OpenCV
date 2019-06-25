#include <iostream>
#include "opencv2/opencv.hpp"

void mask_setTo();
void mask_CopyTo();

int main(void) 
{
	mask_setTo();
	mask_CopyTo();
}

void mask_setTo() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_COLOR);
	cv::Mat mask = cv::imread("mask_smile.bmp", cv::IMREAD_GRAYSCALE);

	// check whether it is open or not
	if (!src.empty() || !mask.empty()) 
	{
		std::cerr << "Fail to open picture" << std::endl;
	}

	src.setTo(cv::Scalar(0, 255, 255), mask);

	cv::imshow("src", src);
	cv::imshow("mask", mask);
	cv::waitKey(0);
	cv::destroyAllWindows();

}
void mask_CopyTo()
{
	cv::Mat src = cv::imread("airplane.bmp", cv::IMREAD_COLOR);
	cv::Mat mask = cv::imread("mask_plane.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat dst = cv::imread("field.bmp", cv::IMREAD_COLOR);

	if (src.empty() || mask.empty() || dst.empty()) 
	{
		std::cerr << "Fail to Open" << std::endl;
		return;
	}
	// change to grayscale
	cv::Mat gray;
	gray = ~src;

	src.copyTo(dst, mask);
	cv::imshow("dst", dst);
	cv::imshow("gray", gray);
	cv::waitKey(0);
	cv::destroyAllWindows();
}