/*
Challenge solution for Strider intern spot

references:

http://stackoverflow.com/questions/9018906/detect-rgb-color-interval-with-opencv-and-c
http://docs.opencv.org/2.4/doc/user_guide/ug_mat.html

*/

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

Mat redFilter(const Mat& src)
{
	assert(src.type() == CV_8UC3);

	Mat redOnly;
	inRange(src, Scalar(0, 0, 0), Scalar(0, 0, 255), redOnly);

	return redOnly;
}

bool checkDot(Mat img, int x, int y)
{
	Scalar intensity = img.at<uchar>(x, y);
	if (intensity.val[0] == 255)
		return true;

	return false;
}

int main(int argc, char** argv)
{
	Mat input = imread("data/challenge_strider.png");
	int number = 0;
	int cols, rows;

	imshow("input", input);
	waitKey();

	Mat redOnly = redFilter(input);

	cols = redOnly.cols;
	rows = redOnly.rows;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (checkDot(redOnly, i, j))
			{
				number++;
				std::cout << "is red in (" << i << "," << j << ")" << std::endl;
			}
		}
	}
	imshow("redOnly", redOnly);
	std::cout << number << std::endl;
	waitKey();
	// detect squares after filtering...

	return 0;
}