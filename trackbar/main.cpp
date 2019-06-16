#include <iostream>
#include "opencv2/opencv.hpp"

void on_level_change(int pos, void* userdata);

int main(void) {
	cv::Mat img = cv::Mat::zeros(400, 400, CV_8UC1);
	cv::namedWindow("image");
	cv::createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

	cv::imshow("image", img);
	cv::waitKey(0);

	return 0;
}

void on_level_change(int pos, void* userdata) {
	cv::Mat img = *(cv::Mat*)userdata;
	img.setTo(pos * 16);
	cv::imshow("image", img);
}