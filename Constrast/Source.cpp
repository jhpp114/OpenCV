#include "opencv2/opencv.hpp"
#include <iostream>

void constrast() 
{
	cv::Mat src = cv::imread("lenna.bmp", cv::IMREAD_GRAYSCALE);
	if (src.empty()) 
	{
		std::cerr << "Fail to Load Image" << std::endl;
		return;
	}

	float alpha = 1.0f;
	cv::Mat dst = src + (src - 128) * alpha;
	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey();
	cv::destroyAllWindows();

}
int main() 
{
	constrast();
}