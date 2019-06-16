#include <iostream>
#include "opencv2/opencv.hpp"


cv::Mat img;
cv::Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);

int main(void) {
	img = cv::imread("lenna.bmp");
	if (img.empty()) {
		std::cerr << "Image load fail" << std::endl;
		return -1;
	}
	cv::namedWindow("img");
	cv::setMouseCallback("img", on_mouse);

	cv::imshow("img", img);
	cv::waitKey(0);

	return 0;
}

void on_mouse(int event, int x, int y, int flags, void*) {
	switch (event) {
		case cv::EVENT_LBUTTONDOWN:
			std::cout << "Event LButtonDown: " << x << ", " << y << std::endl;
			break;
		case cv::EVENT_LBUTTONUP:
			std::cout << "Event LBUttonUp: " << x << ", " << y << std::endl;
			break;
		case cv::EVENT_MOUSEMOVE:
			if (flags & cv::EVENT_FLAG_LBUTTON) {
				cv::line(img, ptOld, cv::Point(x, y), cv::Scalar(0, 255, 255), 2);
				cv::imshow("img", img);
				ptOld = cv::Point(x, y);
			}
			break;
		default:
			break;
	}

}
	

