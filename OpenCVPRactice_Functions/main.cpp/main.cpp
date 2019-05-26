#include <iostream>
#include "opencv2/opencv.hpp"


void MatOp1();
void MatOp2();
void MatOp3();
void MatOp4();

int main(void) {
	MatOp1();
	MatOp2();
	MatOp3();
	MatOp4();
	return 0;
}

void MatOp1() {
	// empty matrix
	cv::Mat img1;
	// unsigned char, 1-channel
	// sero 480 pixel, garo 640
	cv::Mat img2(480, 640, CV_8UC1);
	cv::Mat img3(480, 640, CV_8UC3);
	// use size(garo,sero)
	cv::Mat img4(cv::Size(640, 480), CV_8UC3);

	// guessing to grayscale
	cv::Mat img5(480, 640, CV_8UC1, cv::Scalar(128));
	// scalar = bgr order therefore red
	cv::Mat img6(480, 640, CV_8UC3, cv::Scalar(0, 0, 255));

	// 0's matrix
	cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_32SC1);
	// 1's matrix
	cv::Mat mat2 = cv::Mat::ones(3, 3, CV_32FC1);
	// identity matrix
	cv::Mat mat3 = cv::Mat::eye(3, 3, CV_32FC1);

	float data[] = { 1,2,3,4,5 };
	cv::Mat mat4(2, 3, CV_32FC1, data);
	
	cv::Mat mat5 = (cv::Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
	cv::Mat mat6 = cv::Mat_<uchar>({ 2,3 }, { 1,2,3,4,5,6 });

	// channel 3
	mat4.create(256, 256, CV_8UC3);
	// channel 1
	mat5.create(4, 4, CV_32FC1);

	mat4 = cv::Scalar(255, 0, 0);
	mat5.setTo(1.f);
}

void MatOp2() {
	// original image
	cv::Mat img1 = cv::imread("dog.bmp");

	// shallow copy
	cv::Mat img2 = img1;
	cv::Mat img3;
	// shallow copy
	img3 = img1;

	// deep copy
	cv::Mat img4 = img1.clone();
	cv::Mat img5;
	img1.copyTo(img5);

	// set 1 to yellow
	img1.setTo(cv::Scalar(0, 255, 255));

	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);
	cv::imshow("img4", img4);
	cv::imshow("img5", img5);

	cv::waitKey();
	cv::destroyAllWindows();
}

void MatOp3() {
	cv::Mat img1 = cv::imread("cat.bmp");

	if (img1.empty()) {
		std::cerr << "Image Fail to Load" << std::endl;
		return;
	}
	// point from 220, 120, size of 340, 240 rect
	// shallow copy
	cv::Mat img2 = img1(cv::Rect(220, 120, 340, 240));

	// deep copy
	cv::Mat img3 = img1(cv::Rect(220, 120, 340, 240)).clone();

	// change opposite
	// this will make img1 change too but 3
	img2 = ~img2;
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);

	cv::waitKey();
	cv::destroyAllWindows();
}

void MatOp4() {
	// col, row sero, garo
	cv::Mat mat1 = cv::Mat::zeros(3, 4, CV_8UC1);
	// row ,col, garo sero
	cv::Mat mat2 = cv::Mat::zeros(cv::Size(3, 4), CV_8UC1);
	// increase 1 in all elements
	// all contains template!
	// use mat.at();
	for (int i = 0; i < mat1.rows; i++) {
		for (int j = 0; j < mat1.cols; j++) {
			mat1.at<uchar>(i, j)++;
		}
	}
	
	// use mat.ptr();
	for (int i = 0; i < mat1.rows; i++) {
		uchar * p = mat1.ptr<uchar>(i);
		for (int j = 0; j < mat1.cols; j++) {
			p[j]++;
		}
	}
	// use MatIterator
	for (cv::MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++) {
		(*it)++;
	}

	std::cout << "mat1:\n" << mat1 << std::endl;
	std::cout << "mat2:\n" << mat2 << std::endl;
}