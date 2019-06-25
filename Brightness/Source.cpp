#include "opencv2/opencv.hpp"
#include <iostream>

void brightness1() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);

	if (src.empty()) 
	{
		std::cerr << "Image Load Fail" << std::endl;
		return;
	}
	// brightness
	cv::Mat dst = src + 100;

	// display image
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey();
	cv::destroyAllWindows();
}

void brightness2() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
	if (src.empty()) 
	{
		std::cerr << "Fail to load Image" << std::endl;
		return;
	}
	cv::Mat dst = cv::Mat(src.rows, src.cols, src.type());
	for (int i = 0; i < src.rows; i++) 
	{
		for (int j = 0; j < src.cols; j++) 
		{
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 100;
		}
	}
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey();
	cv::destroyAllWindows();

	for (int i = 0; i < src.rows / 2; i++) 
	{
		for (int j = 0; j < src.cols / 2; j++) 
		{
			dst.at<uchar>(i, j) = src.at<uchar>(i, j) + 100;
		}
	}
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey();
	cv::destroyAllWindows();
}
void brightness3() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
	if (src.empty()) 
	{
		std::cerr << "Fail to Read Image" << std::endl;
		return;
	}
	cv::Mat dst = cv::Mat(src.rows, src.cols, src.type());
	for (int i = 0; i < src.rows; i++) 
	{
		for (int j = 0; j < src.cols; j++) 
		{
			dst.at<uchar>(i, j) = cv::saturate_cast<uchar>(src.at<uchar>(i, j) + 100);
		}
	}
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey();
	cv::destroyAllWindows();
}

void on_brightness(int position, void* userdata);

void brightness4() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
	if (src.empty()) 
	{
		std::cerr << "Fail to Load Image" << std::endl;
		return;
	}
	cv::namedWindow("dst");
	cv::createTrackbar("brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);
	cv::waitKey();
	cv::destroyAllWindows();
}
void on_brightness(int position, void*userdata) 
{
	cv::Mat src = *(cv::Mat*)userdata;
	cv::Mat dst = src + position;
	cv::imshow("dst", dst);
}
int main() 
{
	brightness1();
	brightness2();
	brightness3();
	brightness4();
}