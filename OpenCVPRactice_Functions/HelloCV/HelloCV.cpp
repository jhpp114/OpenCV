#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	std::cout << "Hello OpenCV" << CV_VERSION << std::endl;
	// use Mat class to make img var
	cv::Mat img;
	// use imread() function to store image to img var
	img = cv::imread("lenna.bmp");

	if (img.empty()) {
		std::cerr << "Image Load Failed" << std::endl;
		return -1;
	}
	// nameWindow() function is do create another window and that 
	// extra window assign name "image"
	cv::namedWindow("image");
	// imshow() function is to use name "image" window and display
	// img data
	cv::imshow("image", img);
	// waitKey() function is wait user to type something through
	// keyboard.
	cv::waitKey();
	return 0;
}