#include <opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	cv::Mat scrMat = imread("C:\\Users\\Lenovo\\Pictures\\±ÚÖ½\\1.JPG");
	imshow("scr", scrMat);
	uchar threshold = 100;
	int height = scrMat.rows;
	int width = scrMat.cols;
	
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (scrMat.at<Vec3b>(j, i)[0] + scrMat.at<Vec3b>(j, i)[1] + scrMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
			     average = 255;
			else  
				average = 0;
			scrMat.at<Vec3b>(j, i)[0] = average;
			scrMat.at<Vec3b>(j, i)[1] = average;
			scrMat.at<Vec3b>(j, i)[2] = average;
		}
	}




	imshow("scr1", scrMat);
	waitKey(0);
	return 0;
}