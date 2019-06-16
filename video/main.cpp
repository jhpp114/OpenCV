#include "opencv2/opencv.hpp"
#include <iostream>

void camera_in();
void video_in();
void camera_in_video_out();

int main(void) {
	camera_in();
	video_in();
	camera_in_video_out();
}

void camera_in() {
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cerr << "Camera Failed to Open" << std::endl;
		return;
	}
	std::cout << "Frame Width: " << cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;
	std::cout << "Frame Height: " << cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;

	cv::Mat frame, inversed;

	while (true) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		inversed = ~frame;
		
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// esc
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
	cv::destroyAllWindows();
}

void video_in() {
	cv::VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		std::cerr << "Video Failed to Open" << std::endl;
		return;
	}
	std::cout << "Frame Height: " << cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT)) << std::endl;
	std::cout << "Frame Width: " << cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH)) << std::endl;
	std::cout << "Frame Count: " << cvRound(cap.get(cv::CAP_PROP_FRAME_COUNT)) << std::endl;

	double fps = cap.get(cv::CAP_PROP_FPS);
	std::cout << "FPS" << fps << std::endl;

	int delay = cvRound(1000 / fps);

	cv::Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		inversed = ~frame;
		
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		// waitkey delay ms and esc terminate
		if (cv::waitKey(delay) == 27) {
			break;
		}
	}
	cv::destroyAllWindows();
}

void camera_in_video_out() {
	cv::VideoCapture cap(0);

	if (!cap.isOpened()) {
		std::cerr << "Camera Open Fail" << std::endl;
		return;
	}
	int w = cvRound(cap.get(cv::CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(cv::CAP_PROP_FPS);

	int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = (1000 / fps);

	cv::VideoWriter outputVideo("output.avi", fourcc, fps, cv::Size(w, h));

	if (!outputVideo.isOpened()) {
		std::cout << "File open failed" << std::endl;
		return;
	}
	cv::Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			break;
		}
		inversed = ~frame;
		// gray-scale save video
		outputVideo << inversed;
		cv::imshow("frame", frame);
		cv::imshow("inversed", inversed);

		if (cv::waitKey(delay) == 27) {
			break;
		}
	}
	cv::destroyAllWindows();
}