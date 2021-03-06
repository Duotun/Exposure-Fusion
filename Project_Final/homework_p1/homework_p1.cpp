// homework_p1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include<stdio.h>
#include<math.h>
#include<time.h>
using namespace cv;
using namespace std;
typedef unsigned char byte;
const double α = 1e-25;
int n;
int im_x, im_y;
void gradientx(Mat &image, Mat &tpb, Mat &tpg, Mat &tpr)
{
	Mat channel[3];
	split(image, channel);
	/*
	for (int row = 0; row < image.rows; row++)
	{
		//ix_1.at<int>(row, 0) = pow((image_1.at<byte>(row, 1) - image_1.at<byte>(row, 0))* 2,2);
		//printf("%d\n", tp.at<Vec3b>(row, 0)[0]);
		//printf("%d\n", (image.at<Vec3b>(row, 1)[0] - image.at<Vec3b>(row, 0)[0]) * 4 * (image.at<Vec3b>(row, 1)[0] - image.at<Vec3b>(row, 0)[0]));
		tpb.at<int>(row, 0) = (image.at<Vec3b>(row, 1)[0] - image.at<Vec3b>(row, 0)[0]) * 4 * (image.at<Vec3b>(row, 1)[0] - image.at<Vec3b>(row, 0)[0]);
		tpg.at<int>(row, 0) = (image.at<Vec3b>(row, 1)[1] - image.at<Vec3b>(row, 0)[1]) * 4 * (image.at<Vec3b>(row, 1)[1] - image.at<Vec3b>(row, 0)[1]);
		tpr.at<int>(row, 0) = (image.at<Vec3b>(row, 1)[2] - image.at<Vec3b>(row, 0)[2]) * 4 * (image.at<Vec3b>(row, 1)[2] - image.at<Vec3b>(row, 0)[2]);
		for (int col = 1; col < image.cols - 1; col++)
		{
			tpb.at<int>(row, col) = (image.at<Vec3b>(row, col + 1)[0] - image.at<Vec3b>(row, col - 1)[0]) * (image.at<Vec3b>(row, col + 1)[0] - image.at<Vec3b>(row, col - 1)[0]);
			tpg.at<int>(row, col) = (image.at<Vec3b>(row, col + 1)[1] - image.at<Vec3b>(row, col - 1)[1]) * (image.at<Vec3b>(row, col + 1)[1] - image.at<Vec3b>(row, col - 1)[1]);
			tpr.at<int>(row, col) = (image.at<Vec3b>(row, col + 1)[2] - image.at<Vec3b>(row, col - 1)[2]) * (image.at<Vec3b>(row, col + 1)[2] - image.at<Vec3b>(row, col - 1)[2]);

		}
		tpb.at<int>(row, image.cols - 1) = (image.at<Vec3b>(row, image.cols - 1)[0] - image.at<Vec3b>(row, image.cols - 2)[0]) * 4 * (image.at<Vec3b>(row, image.cols - 1)[0] - image.at<Vec3b>(row, image.cols - 2)[0]);
		tpg.at<int>(row, image.cols - 1) = (image.at<Vec3b>(row, image.cols - 1)[1] - image.at<Vec3b>(row, image.cols - 2)[1]) * 4 * (image.at<Vec3b>(row, image.cols - 1)[1] - image.at<Vec3b>(row, image.cols - 2)[1]);
		tpr.at<int>(row, image.cols - 1) = (image.at<Vec3b>(row, image.cols - 1)[2] - image.at<Vec3b>(row, image.cols - 2)[2]) * 4 * (image.at<Vec3b>(row, image.cols - 1)[2] - image.at<Vec3b>(row, image.cols - 2)[2]);
	}
	
	*/
	int ddepth = CV_32S;
	Sobel(channel[0], tpb, channel[0].depth(), 1, 0,3,5, BORDER_DEFAULT);
	Sobel(channel[1], tpg, channel[0].depth(), 1, 0,3,5, BORDER_DEFAULT);
	Sobel(channel[2], tpr, channel[0].depth(), 1, 0,3,5, BORDER_DEFAULT);
	
}

void gradienty(Mat &image, Mat &tpb, Mat &tpg, Mat &tpr)
{
	/*for (int x = 0; x < image.cols; x++)
	{
		//ix_1.at<int>(row, 0) = pow((image_1.at<byte>(row, 1) - image_1.at<byte>(row, 0))* 2,2);
		tpb.at<int>(0, x) = (image.at<Vec3b>(1, x)[0] - image.at<Vec3b>(0, x)[0]) * 4 * (image.at<Vec3b>(1, x)[0] - image.at<Vec3b>(0, x)[0]);
		tpg.at<int>(0, x) = (image.at<Vec3b>(1, x)[1] - image.at<Vec3b>(0, x)[1]) * 4 * (image.at<Vec3b>(1, x)[1] - image.at<Vec3b>(0, x)[1]);
		tpr.at<int>(0, x) = (image.at<Vec3b>(1, x)[2] - image.at<Vec3b>(0, x)[2]) * 4 * (image.at<Vec3b>(1, x)[2] - image.at<Vec3b>(0, x)[2]);
		for (int y = 1; y < image.rows - 1; y++)
		{
			tpb.at<int>(y, x) = (image.at<Vec3b>(y + 1, x)[0] - image.at<Vec3b>(y - 1, x)[0]) * (image.at<Vec3b>(y + 1, x)[0] - image.at<Vec3b>(y - 1, x)[0]);
			tpg.at<int>(y, x) = (image.at<Vec3b>(y + 1, x)[1] - image.at<Vec3b>(y - 1, x)[1]) * (image.at<Vec3b>(y + 1, x)[1] - image.at<Vec3b>(y - 1, x)[1]);
			tpr.at<int>(y, x) = (image.at<Vec3b>(y + 1, x)[2] - image.at<Vec3b>(y - 1, x)[2]) * (image.at<Vec3b>(y + 1, x)[2] - image.at<Vec3b>(y - 1, x)[2]);
		}
		tpb.at<int>(image.rows - 1, x) = (image.at<Vec3b>(image.rows - 1, x)[0] - image.at<Vec3b>(image.rows - 2, x)[0]) * 4 * (image.at<Vec3b>(image.rows - 1, x)[0] - image.at<Vec3b>(image.rows - 2, x)[0]);
		tpg.at<int>(image.rows - 1, x) = (image.at<Vec3b>(image.rows - 1, x)[1] - image.at<Vec3b>(image.rows - 2, x)[1]) * 4 * (image.at<Vec3b>(image.rows - 1, x)[1] - image.at<Vec3b>(image.rows - 2, x)[1]);
		tpr.at<int>(image.rows - 1, x) = (image.at<Vec3b>(image.rows - 1, x)[2] - image.at<Vec3b>(image.rows - 2, x)[2]) * 4 * (image.at<Vec3b>(image.rows - 1, x)[2] - image.at<Vec3b>(image.rows - 2, x)[2]);
	}
	*/
	Mat channel[3];
	split(image, channel);
	int ddepth = CV_32S;
	Sobel(channel[0], tpb,channel[0].depth(),0,1,3,3,0, BORDER_DEFAULT);
	Sobel(channel[1], tpg, channel[0].depth(), 0, 1, 3, 3, 0, BORDER_DEFAULT);
	Sobel(channel[2], tpr, channel[0].depth(), 0, 1, 3, 3, 0, BORDER_DEFAULT);
	/*imshow("tpb", tpb);
	imshow("tpg", tpg);
	imshow("tpr", tpr);
	*/
}
void calcum(Mat &image, Mat &tpxb, Mat &tpxg, Mat &tpxr, Mat &tpyb, Mat &tpyg, Mat &tpyr, Mat &mpb, Mat &mpg, Mat &mpr, Mat &mpsumb, Mat &mpsumg, Mat &mpsumr)
{
	for (int x = 0; x < image.rows; x++)
	{
		for (int y = 0; y < image.cols; y++)
		{
			//printf("%d\n",iy_1.at<int>(x, y));
			//printf("%d\n", ix_1.at<int>(x, y));
			//printf("%lf\n", sqrt(ix_1.at<int>(x, y)));
			//printf("%lf\n", min(sqrt(ix_1.at<int>(x, y) + iy_1.at<int>(x, y)), 255.0));
			/*mpb.at<double>(x, y) = sqrt(tpxb.at<byte>(x, y)*tpxb.at<byte>(x, y) + tpyb.at<byte>(x, y)*tpyb.at<byte>(x, y)) + α;
			mpsumb.at<double>(x, y) += mpb.at<double>(x, y);
			mpg.at<double>(x, y) = sqrt(tpxg.at<byte>(x, y)*tpxg.at<byte>(x, y) + tpyg.at<byte>(x, y)*tpyg.at<byte>(x, y)) + α;
			mpsumg.at<double>(x, y) += mpg.at<double>(x, y);
			mpr.at<double>(x, y) = sqrt(tpxr.at<byte>(x, y)*tpxr.at<byte>(x, y) + tpyr.at<byte>(x, y)*tpyr.at<byte>(x, y)) + α;
			mpsumr.at<double>(x, y) += mpr.at<double>(x, y);
			*/
			mpb.at<double>(x, y) = sqrt((double)tpxb.at<byte>(x, y)*tpxb.at<byte>(x, y) + (double)tpyb.at<byte>(x, y)*tpyb.at<byte>(x, y))/2 + α;
			mpsumb.at<double>(x, y) += mpb.at<double>(x, y);
			mpg.at<double>(x, y) = sqrt((double)tpxg.at<byte>(x, y)*tpxg.at<byte>(x, y) + (double)tpyg.at<byte>(x, y)*tpyg.at<byte>(x, y))/2 + α;
			mpsumg.at<double>(x, y) += mpg.at<double>(x, y);
			mpr.at<double>(x, y) = sqrt((double)tpxr.at<byte>(x, y)*tpxr.at<byte>(x, y) + (double)tpyr.at<byte>(x, y)*tpyr.at<byte>(x, y))/2 + α;
			mpsumr.at<double>(x, y) += mpr.at<double>(x, y);
			/*
			mpb.at<double>(x, y) = sqrt(tpxb.at<int>(x, y) + tpyb.at<int>(x, y))+ α;
			mpsumb.at<double>(x, y) += mpb.at<double>(x, y);
			mpg.at<double>(x, y) = sqrt(tpxg.at<int>(x, y) + tpyg.at<int>(x, y))+ α;
			mpsumg.at<double>(x, y) += mpg.at<double>(x, y);
			mpr.at<double>(x, y) = sqrt(tpxr.at<int>(x, y) + tpyr.at<int>(x, y))+ α;
			mpsumr.at<double>(x, y) += mpr.at<double>(x, y);
			*/
		}
	}
}
void calcuw(Mat &wpb, Mat &wpg, Mat &wpr, Mat &mpb, Mat &mpg, Mat &mpr, Mat &msumb, Mat &msumg, Mat &msumr)
{
	for (int x = 0; x < wpb.rows; x++)
	{
		for (int y = 0; y < wpb.cols; y++)
		{
			wpb.at<double>(x, y) = mpb.at<double>(x, y) / (msumb.at<double>(x, y));
			wpg.at<double>(x, y) = mpg.at<double>(x, y) / (msumg.at<double>(x, y));
			wpr.at<double>(x, y) = mpr.at<double>(x, y) / (msumr.at<double>(x, y));
			/*if (wpb.at<double>(x, y) - 1 <= 0.0f)
			{
			wpb = 0.3333f;
			}
			else if (wpg.at<double>(x, y) - 1 <= 0.0f)
			{
			wpg = 0.3333f;
			}
			else if (wpr.at<double>(x, y) - 1 <= 0.0f)
			{
			wpr = 0.3333f;
			}
			*/
		}
	}
	//imshow("wwb", wpb);
	//imshow("wwg", wpg);
	//imshow("wwr",wpr);
}
void gaussianblurforweight(Mat &wpb, Mat &wpg, Mat &wpr)
{
	GaussianBlur(wpb, wpb, Size(31, 31), 30,30);
	GaussianBlur(wpg, wpg, Size(31, 31), 30,30);
	GaussianBlur(wpr, wpr, Size(31, 31), 30,30);
     
}
void merge(Mat &hp, Mat &image, Mat &wpb, Mat &wpg, Mat &wpr, int flag)
{
	if (flag == 0) {
		for (int x = 0; x < image.rows; x++)
		{
			for (int y = 0; y < image.cols; y++)
			{
				//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
				hp.at<Vec3b>(x, y)[0] = (wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0]);
				hp.at<Vec3b>(x, y)[1] = (wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1]);
				hp.at<Vec3b>(x, y)[2] = (wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2]);
			}
		}
	}
	else
	{
		for (int x = 0; x < image.rows; x++)
		{
			for (int y = 0; y < image.cols; y++)
			{
				//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
				hp.at<Vec3b>(x, y)[0] += (wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0]);
				hp.at<Vec3b>(x, y)[1] += (wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1]);
				hp.at<Vec3b>(x, y)[2] += (wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2]);

				/*hp.at<Vec3b>(x, y)[0] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				hp.at<Vec3b>(x, y)[1] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				hp.at<Vec3b>(x, y)[2] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				*/
			}
		}
	}

	/*for (int x = 0; x < image.rows; x++)
	{
	for (int y = 0; y < image.cols; y++)
	{
	//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
	hp[0].at<double>(x, y) += wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0];
	hp[1].at<double>(x, y) += wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1];
	hp[2].at<double>(x, y) += wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2];
	}
	}
	*/
}
void mergedynamic(Mat &hp, Mat &image, Mat &wpb, Mat &wpg, Mat &wpr, int flag)
{
	if (flag == 0) {
		for (int x = 0; x < image.rows; x++)
		{
			for (int y = 0; y < image.cols; y++)
			{
				//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
				hp.at<Vec3b>(x, y)[0] = (wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0]);
				hp.at<Vec3b>(x, y)[1] = (wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1]);
				hp.at<Vec3b>(x, y)[2] = (wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2]);
			}
		}
	}
	else
	{
		for (int x = 0; x < image.rows; x++)
		{
			for (int y = 0; y < image.cols; y++)
			{
				//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
				hp.at<Vec3b>(x, y)[0] += (wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0]);
				hp.at<Vec3b>(x, y)[1] += (wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1]);
				hp.at<Vec3b>(x, y)[2] += (wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2]);

				/*hp.at<Vec3b>(x, y)[0] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				hp.at<Vec3b>(x, y)[1] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				hp.at<Vec3b>(x, y)[2] = min(hp.at<Vec3b>(x, y)[0], (uchar)255);
				*/
			}
		}
	}

	/*for (int x = 0; x < image.rows; x++)
	{
	for (int y = 0; y < image.cols; y++)
	{
	//H.at<byte>(x, y) +=(byte)(w3.at<double>(x, y)*image_3.at<byte>(x, y));
	hp[0].at<double>(x, y) += wpb.at<double>(x, y) * image.at<Vec3b>(x, y)[0];
	hp[1].at<double>(x, y) += wpg.at<double>(x, y) * image.at<Vec3b>(x, y)[1];
	hp[2].at<double>(x, y) += wpr.at<double>(x, y) * image.at<Vec3b>(x, y)[2];
	}
	}
	*/
}
void compose(Mat *hp, IplImage *res)
{
	IplImage *finalred, *finalgreen, *finalblue;

	finalred = cvCreateImage(cvGetSize(res), IPL_DEPTH_8U, 1);//R通道

	finalgreen = cvCreateImage(cvGetSize(res), IPL_DEPTH_8U, 1);//G通道

	finalblue = cvCreateImage(cvGetSize(res), IPL_DEPTH_8U, 1);//B通道

	Mat *Hdata = new Mat[3];

	for (int i = 0; i<3; i++)

	{

		Hdata[i] = Mat::zeros(res->height, res->width, CV_8UC1);

		for (int j = 0; j<res->height; j++)

			for (int k = 0; k<res->width; k++)

				Hdata[i].at<uchar>(j, k) = (uchar)hp[i].at<double>(j, k);

	}
	*finalred = Hdata[2];

	*finalgreen = Hdata[1];

	*finalblue = Hdata[0];

	cvMerge(finalblue, finalgreen, finalred, 0, res);//合成

	cvShowImage("Result", res);

	delete[] Hdata;

}
double **GetGuassionArray(int size, double sigma) {
	double sum = 0.0f;
	int center = size / 2;     // the center point is defined by the size
	double **array = new double*[size];//build array with size*size
	for (int i = 0; i < size; i++)
		array[i] = new double[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			array[i][j] = exp(-((i - center)*(i - center) + (j - center)*(j - center)) / (sigma*sigma * 2));
			sum += array[i][j];
		}
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			array[i][j] /= sum;
		}
	return array;
}
void myGaussianfilter(const Mat srcimg, Mat &dstimg) {
	if (!srcimg.data) return;
	double **array;
	Mat tmpimg(srcimg.size(), srcimg.type());
	for (int i = 0; i < srcimg.rows; i++)
		for (int j = 0; j < srcimg.cols; j++) {//do not process edge
			if ((i - 1) > 0 && (i + 1) < srcimg.rows && (j - 1) > 0 && (j + 1) < srcimg.cols) {
				array = GetGuassionArray(31, 30);//get kernel, size and sigma
				tmpimg.at<Vec3b>(i, j)[0] = 0; //color RGB, calculate respectively
				tmpimg.at<Vec3b>(i, j)[1] = 0;
				tmpimg.at<Vec3b>(i, j)[2] = 0;
				for (int x = 0; x < 31; x++) { //size allignment 
					for (int y = 0; y < 31; y++) {
						tmpimg.at<Vec3b>(i, j)[0] += array[x][y] * srcimg.at<Vec3b>(i + 1 - x, j + 1 - y)[0];
						tmpimg.at<Vec3b>(i, j)[1] += array[x][y] * srcimg.at<Vec3b>(i + 1 - x, j + 1 - y)[1];
						tmpimg.at<Vec3b>(i, j)[2] += array[x][y] * srcimg.at<Vec3b>(i + 1 - x, j + 1 - y)[2];
					}
				}
			}
		}
	for(int i=0;i<tmpimg.rows;i++)   // delete outrange value
		for (int j = 0; j < tmpimg.rows; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (tmpimg.at<Vec3b>(i, j)[k] < 0)
					tmpimg.at<Vec3b>(i, j)[k] = 0;
				else if (tmpimg.at<Vec3b>(i, j)[k] > 255)
					tmpimg.at<Vec3b>(i, j)[k] = 255;
			}
		}
	tmpimg.copyTo(dstimg);
}
double absolutedir(byte tpx1, byte tpx2, byte tpy1, byte tpy2)
{
	return sqrt((tpx1 - tpx2)*(tpx1 - tpx2) + (tpy1 - tpy2)*(tpy1 - tpy2));
}
void dircal(Mat &tpb, Mat &tpg, Mat &tpr, Mat &tpxb1, Mat &tpxg1, Mat &tpxr1,Mat &tpyb1,Mat &tpyg1, Mat &tpyr1, Mat &tpxb2, Mat &tpxg2, Mat &tpxr2, Mat &tpyb2, Mat &tpyg2, Mat &tpyr2,int flag)
{
	const int l = 9;
	const double division = 19.0 * 19.0;
	const int k = -9;
	if (flag == 0)
	{
		return;
	}
	else
	{
		//printf("%d\n", tpxb1.at<byte>(0, 0));
		//double a = absolutedir(tpxb1.at<byte>(0, 0), tpxb2.at<byte>(0, 0), tpyb1.at<byte>(0, 0), tpyb2.at<byte>(0, 0));
		//printf("%lf\n", absolutedir(tpxb1.at<byte>(0, 0), tpxb2.at<byte>(0, 0), tpyb1.at<byte>(0, 0), tpyb2.at<byte>(0, 0)));
		for (int i = 0; i < tpb.rows; i++)
		{
			for (int j = 0; j < tpb.cols; j++)
			{
				if ((i >= 9 && j >= 9) && (i <= tpb.rows - 10 && j <= tpb.cols - 10))
				{
					for (int p = k; p <= l; p++)    //edge needs to be processed
					{
						//printf("%lf\n", absolutedir(tpxb1.at<byte>(i + p, j + p), tpxb2.at<byte>(i + p, j + p), tpyb1.at<byte>(i + p, j + p), tpyb2.at<byte>(i + p, j + p)));
						tpb.at<double>(i, j) += absolutedir(tpxb1.at<byte>(i + p, j + p), tpxb2.at<byte>(i + p, j + p), tpyb1.at<byte>(i + p, j + p), tpyb2.at<byte>(i +p, j + p)) / division;
						tpg.at<double>(i, j) += absolutedir(tpxg1.at<byte>(i + p, j + p), tpxg2.at<byte>(i + p, j + p), tpyg1.at<byte>(i + p, j + p), tpyg2.at<byte>(i + p, j + p)) / division;
						tpr.at<double>(i, j) += absolutedir(tpxr1.at<byte>(i + p, j + p), tpxr2.at<byte>(i + p, j + p), tpyr1.at<byte>(i + p, j + p), tpyr2.at<byte>(i + p, j + p)) / division;
						//tpb.at<double>(i, j) += sqrt ((tpxb1.at<byte>(i + p, j + p) - tpxb2.at<byte>(i + p, j + p))*(tpxb1.at<byte>(i + p, j + p) - tpxb2.at<byte>(i + p, j + p)) + (tpyb1.at<byte>(i + p, j + p) - tpyb2.at<byte>(i + p, j + p))*(tpyb1.at<byte>(i + p, j + p) - tpyb2.at<byte>(i + p, j + p))) / division;
						//tpg.at<double>(i, j) += sqrt((tpxg1.at<byte>(i + p, j + p) - tpxg2.at<byte>(i + p, j + p))*(tpxg1.at<byte>(i + p, j + p) - tpxg2.at<byte>(i + p, j + p)) + (tpyg1.at<byte>(i + p, j + p) - tpyg2.at<byte>(i + p, j + p))*(tpyg1.at<byte>(i + p, j + p) - tpyg2.at<byte>(i + p, j + p))) / division;
						//tpr.at<double>(i, j) += sqrt((tpxr1.at<byte>(i + p, j + p) - tpxr2.at<byte>(i + p, j + p))*(tpxr1.at<byte>(i + p, j + p) - tpxr2.at<byte>(i + p, j + p)) + (tpyr1.at<byte>(i + p, j + p) - tpyr2.at<byte>(i + p, j + p))*(tpyr1.at<byte>(i + p, j + p) - tpyr2.at<byte>(i + p, j + p))) / division;
					}
				}
			}
			
		}
	}
}

void calcus(Mat &dpb,Mat &dpg,Mat &dpr,Mat &spb,Mat &spg,Mat &spr)
{
	const double s = 0.04;
	double tmp;
	for (int i = 0; i < dpb.rows; i++)
	{
		for (int j = 0; j < dpb.cols; j++)
		{
			spb.at<double>(i, j) += exp(-1 * dpb.at<double>(i, j)*dpb.at<double>(i, j) / 2 / s);
			spg.at<double>(i, j) += exp(-1 * dpg.at<double>(i, j)*dpg.at<double>(i, j) / 2 / s);
			spr.at<double>(i, j) += exp(-1 * dpr.at<double>(i, j)*dpr.at<double>(i, j) / 2 / s);
		}
	}

}
void calcusumsa(Mat &spb, Mat &spg, Mat &spr, Mat &apb, Mat &apg, Mat &apr, Mat &sumpb, Mat &sumpg, Mat &sumpr)
{
	for (int i = 0; i < spb.rows; i++)
	{

		for (int j = 0; j < spb.cols; j++)
		{
			sumpb.at<double>(i, j) += (spb.at<double>(i, j)*apb.at<int>(i, j) + α);
			sumpg.at<double>(i, j) += (spg.at<double>(i, j)*apg.at<int>(i, j) + α);
			sumpr.at<double>(i, j) += (spr.at<double>(i, j)*apr.at<int>(i, j) + α);
			 
		}
	}

}
// I think the α here is not worthy.
void calcuc(Mat &cpb, Mat &cpg, Mat &cpr, Mat &spb, Mat &spg, Mat &spr, Mat &apb,Mat &apg, Mat &apr,Mat &sumpb, Mat &sumpg, Mat &sumpr)
{
	for (int i = 0; i < cpb.rows; i++)
	{
		
		for (int j = 0; j < cpb.cols; j++)
		{
			cpb.at<double>(i, j) =(spb.at<double>(i, j)*apb.at<int>(i, j)+α) / sumpb.at<double>(i, j) ;
			cpg.at<double>(i, j) = (spg.at<double>(i, j)*apg.at<int>(i, j) + α) / sumpg.at<double>(i, j) ;
			cpr.at<double>(i, j) = (spr.at<double>(i, j)*apr.at<int>(i, j) + α) / sumpr.at<double>(i, j) ;
		}
	}

}
void calcua(Mat &relab, Mat &relag, Mat &relar,Mat &apb,Mat &apg,Mat &apr)
{
	const double rangemin = 0.1f;
	const double rangemax = 0.9f;
	for (int i = 0; i < relab.rows ; i++)
	{
		for (int j = 0; j < relab.cols; j++)
		{
			if (relab.at<double>(i, j) < rangemax&&relab.at<double>(i, j) > rangemin)
			{
				apb.at<int>(i, j) = 1;
			}
			else
			{
				apb.at<int>(i, j) = 0;
			}

			if (relag.at<double>(i, j) < rangemax&&relag.at<double>(i, j) > rangemin)
			{
				apg.at<int>(i, j) = 1;
			}
			else
			{
				apg.at<int>(i, j) = 0;
			}
			
			if (relar.at<double>(i, j) < rangemax&&relar.at<double>(i, j) > rangemin)
			{
				apr.at<int>(i, j) = 1;
			}
			else
			{
				apr.at<int>(i, j) = 0;
			}
		}
	}

}
void calcurela(Mat &image,Mat &relab, Mat &relag, Mat &relar)
{
	const double threshold = 255.0f;
	for (int x = 0; x < image.rows; x++)
	{
		for (int y = 0; y < image.cols; y++)
		{
			//printf("%d\n", image.at<Vec3b>(x, y)[0]);
			relab.at<double>(x,y) = image.at<Vec3b>(x,y)[0] / threshold;
			relag.at<double>(x,y) = image.at<Vec3b>(x,y)[1] / threshold;
			relar.at<double>(x,y) = image.at<Vec3b>(x,y)[2] / threshold;
		}
	}

}
//α may need to be edited according to the static scenes.
void calcudw(Mat &wpb,Mat &wpg, Mat &wpr,Mat &mpb, Mat &mpg, Mat &mpr, Mat &cpb, Mat &cpg, Mat &cpr, Mat &sumpb, Mat &sumpg, Mat &sumpr)
{
	for (int i = 0; i < mpb.rows; i++)
	{

		for (int j = 0; j < mpb.cols; j++)
		{
			wpb.at<double>(i, j) = mpb.at<double>(i, j)*cpb.at<double>(i, j) / sumpb.at<double>(i, j);
			wpg.at<double>(i, j) = mpg.at<double>(i, j)*cpg.at<double>(i, j) / sumpg.at<double>(i, j);
			wpr.at<double>(i, j) = mpr.at<double>(i, j)*cpr.at<double>(i, j) / sumpr.at<double>(i, j) ;
		}
	}
}
void calcusummc(Mat &mpb,Mat &mpg,Mat &mpr,Mat &cpb, Mat &cpg, Mat &cpr,Mat &sumpb,Mat &sumpg, Mat &sumpr)
{
	for (int i = 0; i < mpb.rows; i++)
	{

		for (int j = 0; j < mpb.cols; j++)
		{
			sumpb.at<double>(i, j) += mpb.at<double>(i, j)*cpb.at<double>(i, j);
			sumpg.at<double>(i, j) += mpg.at<double>(i, j)*cpg.at<double>(i, j);
			sumpr.at<double>(i, j) += mpr.at<double>(i, j)*cpr.at<double>(i, j);

		}
	}
}
int main(int argc, char** argv)
{
	clock_t Start, End;
	Start = clock();
	//initial test part
	/*	if (argc != 2)
	{
	cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
	return -1;
	}

	Mat image;
	//image = imread(argv[1], IMREAD_COLOR); // Read the file
	image = imread("E:\\th.jpg");
	if (image.empty()) // Check for invalid input
	{
	cout << "Could not open or find the image" << std::endl;
	return -1;
	}
	namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	imshow("Display window", image); // Show our image inside it.
	*/
	/*Mat image_1;
	Mat image_2;
	Mat image_3;
	image_1 = imread("E:/大三上各种数据/图像处理技术-imageprocess/p1/data/bridge/image-c-1b.jpg");
	image_2 = imread("E:/大三上各种数据/图像处理技术-imageprocess/p1/data/bridge/image-c-2b.jpg");
	image_3 = imread("E:/大三上各种数据/图像处理技术-imageprocess/p1/data/bridge/image-c-3b.jpg");
	char =" "
	" "
	*/
	IplImage *ColorImage;
	Mat image[10];
	cout << "Please input the numbers of pitures: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char path[200] = { 0 };
		cout << "Please input the path of Num." << i + 1 << endl; //输入第i+1张图片的路径，精确到xxxxx.jpg
		cin >> path;
		cout << path << endl;
		image[i] = imread(path, 1);
		if (i == 0)
		{
			ColorImage = cvLoadImage(path, 1);
		}
		//imagerela[i] = image[i].clone();
		//if (!image[i].empty())
		//	imshow("1", image[i]);
		//else
		//printf("fuck\n");
	}
	Mat imagerelab[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat imagerelag[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat imagerelar[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	for (int i = 0; i < n; i++)
	{
		calcurela(image[i],imagerelab[i],imagerelag[i],imagerelar[i]);
		
	}
	
	Mat ixb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };

	Mat iyb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	Mat ixg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	Mat iyg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		, Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		, Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	Mat ixr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S),Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	Mat iyr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S), Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		, Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S)
		, Mat::zeros(image[0].rows, image[0].cols, CV_32S) , Mat::zeros(image[0].rows, image[0].cols, CV_32S) };

	Mat mb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat mg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat mr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat wb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat wg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F),Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat wr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F), Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		, Mat::zeros(image[0].rows, image[0].cols, CV_64F) , Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat m_sumb = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat m_sumg = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat m_sumr = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat sa_sumb = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat sa_sumg = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat sa_sumr = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat vc_sumb = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat vc_sumg = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat vc_sumr = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
	Mat db[10][10];
	Mat dg[10][10];
	Mat dr[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			db[i][j]= Mat::zeros(image[0].rows, image[0].cols, CV_64F);
			dg[i][j] = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
			dr[i][j] = Mat::zeros(image[0].rows, image[0].cols, CV_64F);
		}
	}
	Mat dwb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) 
	,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) 
	,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat dwg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat dwr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat sb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) 
	,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat cb[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat ab[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };	
	//imshow("msum_b", m_sumb);
	Mat sg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat cg[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat ag[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	Mat sr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F)
		,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat cr[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,Mat::zeros(image[0].rows, image[0].cols, CV_64F) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_64F) };
	Mat ar[10] = { Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,
		Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) ,Mat::zeros(image[0].rows, image[0].cols, CV_32S) };
	
	Mat H(image[0].rows, image[0].cols, CV_32S);
	//	printf("%d\n%d\n%d\n", H.at<Vec3b>(0, 0)[0], H.at<Vec3b>(0, 0)[1], H.at<Vec3b>(0, 0)[2]);
	//	printf("%d\n%d\n%d\n", ix[0].at<Vec3b>(0, 0)[0], ix[0].at<Vec3b>(0, 0)[1], ix[0].at<Vec3b>(0, 0)[2]);
	H = image[0].clone();
	printf("%d\n%d\n", ixb[1].rows, ixb[1].cols);
	for (int i = 0; i < n; i++)
	{
		calcua(imagerelab[i], imagerelag[i], imagerelar[i],ab[i],ag[i],ar[i]);
		gradientx(image[i], ixb[i], ixg[i], ixr[i]);
		//imshow("ixb", iyb[i]);
		//imshow("ixg", iyg[i]);
		//imshow("ixr", iyr[i]);
		gradienty(image[i], iyb[i], iyg[i], iyr[i]);
		calcum(image[i], ixb[i], ixg[i], ixr[i], iyb[i], iyg[i], iyr[i], mb[i], mg[i], mr[i], m_sumb, m_sumg, m_sumr);
		//calcuw(wb[i],wg[i],wr[i], mb[i],mg[i],mr[i], m_sumb,m_sumg,m_sumr);
		//merge(H, image[i],wb[i],wg[i],wr[i],i);
		//imshow("original", image[i]);
	}
	//imshow("m1", m_sumb);
	//imshow("m2", m_sumg);
	imshow("h", H);
	for (int i = 0; i < n; i++)
	{
		calcuw(wb[i], wg[i], wr[i], mb[i], mg[i], mr[i], m_sumb, m_sumg, m_sumr);
		char n1[10], n2[10], n3[10];
		/*sprintf(n1, "wb%d", i);
		sprintf(n2, "wg%d", i);
		sprintf(n3, "wr%d", i);
		imshow(n1, wb[i]);
		imshow(n2, wg[i]);
		imshow(n3, wr[i]);
		*/
	}
	Mat after;
	for (int i = 0; i < n; i++)
	{
		gaussianblurforweight(wb[i], wg[i], wr[i]);
		char n1[10], n2[10], n3[10];
		/*sprintf(n1, "awb%d", i);
		sprintf(n2, "awg%d", i);
		sprintf(n3, "awr%d", i);
		imshow(n1, wb[i]);
		imshow(n2, wg[i]);
		imshow(n3, wg[i]);
		*/
	}

	//GaussianBlur(H,after,Size(3, 3), 1);
	IplImage *res;
	Mat *Hdata = new Mat[3];
	res = cvCreateImage(cvGetSize(ColorImage), IPL_DEPTH_8U, 3);
	for (int i = 0; i < 3; i++)
	{

		Hdata[i] = Mat::zeros(image[0].rows, image[0].cols, CV_64FC1);
	}
	for (int i = 0; i < n; i++)
	{
		merge(H, image[i], wb[i], wg[i], wr[i], i);

	}
	//cvSetZero(res);
	//compose(Hdata, res);
	//imshow("after", after);
	//cv::namedWindow("final", CV_WINDOW_NORMAL);   //window automatically fits for the image
	imshow("static_results", H);
	delete[]Hdata;
	
	     //d(x,y) should be a two-dimensional vector, then abs
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{     
			int flag = 1;
			if (i == j)
			  flag = 0;
			dircal(db[i][j], dg[i][j], dr[i][j], ixb[i], ixg[i], ixr[i], iyb[i], iyg[i], iyr[i], ixb[j], ixg[j], ixr[j], iyb[j], iyg[j], iyr[j], flag);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			calcus(db[i][j],dg[i][j],dr[i][j],sb[i],sg[i],sr[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		calcusumsa(sb[i], sg[i], sr[i], ab[i], ag[i], ar[i], sa_sumb, sa_sumg, sa_sumr);
		char n1[10], n2[10], n3[10];
		/*sprintf(n1, "sb%d", i);
		sprintf(n2, "sg%d", i);
		sprintf(n3, "sr%d", i);
		imshow(n1, cb[i]);
		imshow(n2, cg[i]);
		imshow(n3, cg[i]);
		*/
	}
	for (int i = 0; i < n; i++)
	{
		calcuc(cb[i], cg[i], cr[i], sb[i], sg[i], sr[i], ab[i], ag[i], ar[i], sa_sumb, sa_sumg, sa_sumr);
	}
	for (int i = 0; i < n; i++)
	{
		calcusummc(mb[i], mg[i], mr[i], cb[i], cg[i], cr[i], vc_sumb, vc_sumg, vc_sumr);
		char n1[10], n2[10], n3[10];
		/*sprintf(n1, "cb%d", i);
		sprintf(n2, "cg%d", i);
		sprintf(n3, "cr%d", i);
		imshow(n1, cb[i]);
		imshow(n2, cg[i]);
		imshow(n3, cg[i]);
		*/
	}
	/*for (int i = 0; i < n; i++)
	{
	gaussianblurforweight(cb[i], cg[i], cr[i]);
	char n1[10], n2[10], n3[10];
	sprintf(n1, "acb%d", i);
	sprintf(n2, "acg%d", i);
	sprintf(n3, "acr%d", i);
	imshow(n1, cb[i]);
	imshow(n2, cg[i]);
	imshow(n3, cr[i]);
	}
	*/
	for (int i = 0; i < n; i++)
	{
		calcudw(dwb[i], dwg[i], dwr[i], mb[i], mg[i], mr[i], cb[i], cg[i], cr[i], vc_sumb, vc_sumg, vc_sumr);
		char n1[10], n2[10], n3[10];
		/*sprintf(n1, "dwb%d", i);
		sprintf(n2, "dwg%d", i);
		sprintf(n3, "dwr%d", i);
		imshow(n1, dwb[i]);
		imshow(n2, dwg[i]);
		imshow(n3, dwg[i]);
		*/
	}
	H = H.clone();
	for (int i = 0; i < n; i++)
	{
		gaussianblurforweight(dwb[i], dwg[i], dwr[i]);
		/*char n1[10], n2[10], n3[10];
		sprintf(n1, "adwb%d", i);
		sprintf(n2, "adwg%d", i);
		sprintf(n3, "adwr%d", i);
		imshow(n1, dwb[i]);
		imshow(n2, dwg[i]);
		imshow(n3, dwr[i]);
		*/
	}
	
	for (int i = 0; i < n; i++)
	{
		mergedynamic(H,image[i],dwb[i],dwg[i],dwr[i],i);
	}
	imshow("dynamic_results", H);


	End = clock();
	double Duration = (double)(End - Start) / CLOCKS_PER_SEC;     //计算运算时间
	cout << "用时: " << Duration << "s" << endl;
	waitKey(0); // Wait for a keystroke in the window

	return 0;
}
