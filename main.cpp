//#include <vector>

#include <opencv/cv.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "cvYadif.h"

int main(void)
{
	cv::VideoCapture cap;
	cap.open("test.avi");
	cv::Mat img;
	cv::Mat out;
	cv::Mat big_in;
	cv::Mat big_out;
		
	cap >> img;
	cv::Yadif yadif(img);

	do {
		cap >> img;
		if (!img.empty() && img.data != nullptr && img.rows > 0 && img.cols > 0)
		{
			yadif.deinterlace(img, out);
			cv::resize(img, big_in, cv::Size(1440, 960));
			cv::resize(out, big_out, cv::Size(1440, 960));

			cv::imshow("in", big_in);
			cv::imshow("out", big_out);
		}
	} while (cv::waitKey(0) != 27);
	return 0;
}