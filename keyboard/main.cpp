#include <iostream>
#include "opencv2/opencv.hpp"


int main(void) {
	cv::Mat img = cv::imread("lenna.bmp");

	if (img.empty()) {
		std::cerr << "Image read Fail" << std::endl;
		return -1;
	}
	cv::namedWindow("img");
	cv::imshow("img", img);
	
	while (true) {
		int userKey = cv::waitKey();
		if (userKey == 'i' || userKey == 'I') {
			img = ~img;
			cv::imshow("img", img);
		}
		else if (userKey == 27 || userKey == 'q' || userKey == 'Q') {
			break;
		}
	}
	cv::destroyAllWindows();
	return 0;
}