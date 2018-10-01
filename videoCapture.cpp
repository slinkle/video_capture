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
    cout << "save video as " << videoName << endl;
    
    cv::VideoCapture cap(1);
    if(!cap.isOpened())
    {
	cout << "Camera could not be opened successfully\n";
	return -1;
    }
    
    int fps = cap.get(CV_CAP_PROP_FPS);
    if (fps <= 0) fps = 25;
    cout << "the cam fps is " << fps << endl;
    
    cv::Size s = cv::Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH), (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));
//     vw.open(videoName, cv::VideoWriter::fourcc);
    cv::VideoWriter vw(videoName,CV_FOURCC('M','P','E','G'),fps,s);
    if(!vw.isOpened())
    {
	cout << "File could not be created for writing . Check permissions\n";
	return -1;
    }
    
    cv::namedWindow("camera",CV_WINDOW_NORMAL);
    char c = (char)waitKey(0);
    
    while(c!='\x1b' && cap.isOpened())
    {
	cv::Mat frame;
	cap>>frame;
	if (frame.empty())
	{
	    cout << "video over\n";
	    break;
	}
	cv::imshow("camera",frame);
	vw<<frame;
    }
    cout << "Saved video to " << videoName << endl;
    
    return 0;
}