#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>

using namespace std;
using namespace cv;

int main(int argc, char*argv[])
{
    string videoName = "video.avi";
    if(argc>1)
	videoName = argv[1];
    cout << "going to open video:" << videoName << endl;
    
    cv::VideoCapture cap;
    cap.open(videoName);
    if(!cap.isOpened())
    {
	cout << "video could not be opened successfully\n";
	return -1;
    }
    
    cv::namedWindow("camera",CV_WINDOW_NORMAL);
//     char c = (char)waitKey(0);
    
    while(cap.isOpened())
    {
	cv::Mat frame;
	cap>>frame;
	if (frame.empty())
	{
	    cout << "frame is empty, video over\n";
	    break;
	}
	cv::imshow("camera",frame);
	if(cv::waitKey(10)=='\x1b') break;
    }
    cap.release();
    
    return 0;
}