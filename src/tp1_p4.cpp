#include <opencv.hpp>
#include <core.hpp>
#include <highgui.hpp>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	// Create a VideoCapture object to load our video file.
	  // I'm using this method because it's the proper way to do it in C++ (uses OOP logic).
	VideoCapture cap("videos/test.mp4");

	// Create a Mat object to store a frame coming from our VideoCapture object.
	Mat frame;

	// Make sure the file is loaded.
	if (!cap.isOpened()) {
		cout << "Error can't find the file" << endl;
	}

	// Create a loop that will read and show every frame coming from the our capture stream.
	while(cap.read(frame)){

		cv::imshow("window", frame);

		// Configure the speed of which the frames will show and hide (the test video has a speed of 8fps).
		waitKey(1000/8);
	}

	// The stream will be automatically liberated once the program stops.
	return 0;
}
