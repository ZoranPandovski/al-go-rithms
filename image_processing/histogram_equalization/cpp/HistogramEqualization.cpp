#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;
using namespace cv;

Mat readImage(const string& image_path)
{
	Mat img = imread(image_path, CV_BGR2GRAY);
	if(!img.data)
	{
		cout<<"Image not found!"<<endl;
	}
	else
	{
		cout<<"Loading the image..."<<endl;
		imshow("Image", img);
		waitKey(0);
		cvDestroyAllWindows();
		return img;
	}
}

int getPixelCount(const Mat& img)
{
	cout<<endl<<"---------------------------------"<<endl
		<<"The total no. of pixels  = "<<img.total()
		<<endl<<"---------------------------------"<<endl;
	return img.total();
}

void showDistribution(const map<int, double>& distribution)
{
	map <int, double> :: const_iterator itr;
	cout<<"INTENSITY\tNO. OF PIXELS"<<endl;
	for(itr=distribution.begin(); itr!=distribution.end(); itr++)
		cout<<itr->first<<"\t\t    "<<itr->second<<endl;
}

void cummulate(map<int, double>& distribution)
{
	map<int, double>::iterator itr;
	auto cummulator = 0;
	for(itr=distribution.begin(); itr!=distribution.end(); itr++)
	{
		cummulator += itr->second;
		itr->second = cummulator;
	}
}

void calculateProbability(map<int, double>& distribution, const int& no_of_pixels)
{
	map<int, double>::iterator itr;
	for(itr=distribution.begin(); itr!=distribution.end(); itr++)
		itr->second = itr->second/no_of_pixels;
}

void createDistribution(map<int, double>& distribution, const Mat& img)
{
	map <int, double>::iterator accessor;
	for(int i=0; i<img.rows; i++)
	{
		for(int j=0; j<img.cols; j++)
		{
			auto x = distribution.find(img.at<int>(i, j));
			if(x!=distribution.end())
			{
				x->second++;
			}
			else
			{
				distribution.insert(pair <int, double> (img.at<int>(i, j), 1));
			}
		}
	}
}

void normalize(map<int, double>& distribution)
{
	map<int, double>::iterator itr;
	for(itr=distribution.begin(); itr!=distribution.end(); itr++)
		itr->second *= 255;
}

void reMap(const map<int, double>& distribution, Mat& img)
{
	for(int i=0; i<img.rows; i++)
		for(int j=0; j<img.cols; j++)
		{
			map<int, double>::const_iterator itr = distribution.find(img.at<int>(i, j));
			img.at<int>(i, j) = itr->second;
		}
}

void result(const Mat& img)
{
	string save_destination;
	imshow("Image after running histogram equalization...", img);
	waitKey(0);
	cvDestroyAllWindows();
	cout<<"Where do you want to save your result?(ENTER A VALID FULL PATH WITH THE FILE NAME) : ";
	cin>>save_destination;
	if(save_destination!="")
	{
		imwrite(save_destination, img);
		cout<<"Image saved successfully!"<<endl;
	}
}

void histogram(Mat& img)
{
	const int no_of_pixels = getPixelCount(img);

	map<int, double> distribution;

	createDistribution(distribution, img);
	cummulate(distribution);
	calculateProbability(distribution, no_of_pixels);
	normalize(distribution);
	showDistribution(distribution);
	reMap(distribution, img);
	result(img);
}

main(int argc, char const *argv[])
{
	if(argc<1)
	{
		cout<<argv[1]<<endl;
		cout<<"Please enter the image path!"<<endl;
	}
	else
	{
		Mat img = readImage(argv[1]);
		histogram(img);
	}
}
