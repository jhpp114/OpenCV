#include <iostream>
#include "opencv2/opencv.hpp"
#include <string.h>

cv::String filename = "mydata.json";

void writeData() {
	cv::String name = "Jane";
	int age = 10;
	cv::Point pt(100, 200);
	std::vector<int> score = { 80, 90, 50 };
	cv::Mat mat1 = (cv::Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

	cv::FileStorage fs(filename, cv::FileStorage::WRITE);

	if (!fs.isOpened()) {
		std::cerr << "File Open Fail" << std::endl;
		return;
	}
	fs << "Name" << name;
	fs << "Age" << age;
	fs << "Point" << pt;
	fs << "Score" << score;
	fs << "Data" << mat1;

	fs.release();
}

void readData() {
	cv::String name;
	int age;
	cv::Point pt1;
	std::vector<int> score;

	cv::FileStorage fn(filename, cv::FileStorage::READ);
	
	if (!fn.isOpened()) {
		std::cerr << "File is not Open" << std::endl;
		return;
	}

	fn["Name"] >> name;
	fn["Age"] >> age;
	fn["Point"] >> pt1;
	fn["Score"] >> score;

	fn.release();

	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Point: " << pt1 << std::endl;

	for (int i = 0; i < score.size(); i++) {
		std::cout << "Score: " << score[i] << std::endl;
	}
	//std::cout << "Score: " << cv::Mat(score).t() << std::endl;
}
int main(void) {
	writeData();
	readData();
	return 0;
}