#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
#include <math.h>
#include <math.h>
#define M 500
#define max_times 200
/*刘天瑞*/

int flag = 0;
double XMax = 2.0;
double XMin = -2.0;
double YMax = 2.0;
double YMin = -2.0;
IplImage* workImg;
IplImage* imgshow;
CvRect ROI_rect;
CvScalar sca;
int judge(double a,double b);
void on_mouse(int event, int x,int y,int flags,void* param);
int main()
{
    workImg = cvCreateImage (cvSize(M,M),8,3);
    imgshow = cvCreateImage (cvSize(M,M),8,3);
    cvNamedWindow ("Mandelbrot",1);
    cvMoveWindow("Mandelbrot",0,0);
    draw(M/2,M/2);
    printf("Mandelbrot的简单操作说明(有进行适当改进）：\n1、左键用于放大\n2、滚轮用于平移\n3、右键用于恢复");
    cvNamedWindow("Mandelbrot",CV_WINDOW_AUTOSIZE);
    cvSetMouseCallback("Mandelbrot",on_mouse,NULL);
    cvWaitKey(0);
    cvDestroyWindow("Mandelbrot");
    cvReleaseImage(&workImg);
    cvReleaseImage(&imgshow);
    return 0;
}
int judge(double re,double im)
{
    double x = 0,y = 0,X,Y;
    int i = 0;
    for(i = 0;x*x + y*y <= 4;i++)
    {
        X = x*x-y*y + re;
        Y = x*y*2 + im;
        x = X;
        y = Y;
        if(i == max_times)
            break;
    }
        return i;
}
void on_mouse(int event, int x,int y,int flags,void* param)
{
    int thickness = 2;
    float real,imaginary;
    int left,right,up,down;
    int a,b,c;
    int d,e,f;
    double DX = XMax - XMin;
    double DY = YMax - YMin;
    double offX = DX/M;
    double offY = DY/M;
    CvPoint p1,p2;
    if(event == CV_EVENT_MBUTTONDOWN)
        draw(x,y);
    if(event == CV_EVENT_RBUTTONUP)
    {
        draw(M/2,M/2);
        XMax = 2.0;
        XMin = -2.0;
        YMax = 2.0;
        YMin = -2.0;
        DX = XMax-XMin;
        DY = YMax-YMin;
        offX = DX/M;
        offY = DY/M;
    }
    if(event == CV_EVENT_LBUTTONDOWN)
    {
        ROI_rect.x = x;
        ROI_rect.y = y;
        flag = 1;
    }
    if(flag&&event == CV_EVENT_MOUSEMOVE)
    {
        cvCopy(workImg,imgshow,NULL);
        p1 = cvPoint(ROI_rect.x,ROI_rect.y);
        p2 = cvPoint(x,x-ROI_rect.x+ROI_rect.y);
        cvRectangle(imgshow,p1,p2,CV_RGB(0,500,150),thickness,CV_AA,0);
        cvShowImage("Mandelbrot",imgshow);
    }
    if(flag&&event == CV_EVENT_LBUTTONUP)
    {
        flag = 0;
        p2.x = x;
        p2.y = x-ROI_rect.x + ROI_rect.y;
        p1.x = ROI_rect.x;
        p1.y = ROI_rect.y;
        left = min(p1.x,p2.x);
        right = max(p1.x,p2.x);
        up = min(p1.y,p2.y);
        down = max(p1.y,p2.y);
        cvShowImage("Mandelbrot",workImg);
        cvWaitKey (1);
        XMax = offX*right + XMin;
        XMin = offX*left + XMin;
        YMax = offY*down + YMin;
        YMin = offY*up + YMin;
        drawmandelbrot();
        cvShowImage("Mandelbrot",workImg);
    }
    cvWaitKey(20);
}
void draw(int x,int y)
{
    double real,imaginary,i;
    int m,n;
    int a,b,c;
    int d,e,f;
     for(m = 0;m < M;m++)
        for(n = 0;n < M;n++)
        {
            real = (m - x)/100.0;
            imaginary = (n - y)/100.0;
            i = judge(real,imaginary);
            if((i - max_times) == 0)
            {


                a = m;
                b = n;
                c = m + n;
                sca.val[0] = a;
                sca.val[1] = b;
                sca.val[2] = c;
                cvSet2D(workImg,n,m,sca);
            }
            else
            {
                d = (sin(6*i))*60 + 0.5*abs(200 - m) + 70;
                e = (cos(5*i))*60 + 0.5*abs(200 - n) + 70;
                f = (sin(100*i))*60 + 0.5*abs(200 - n) + 70;
                sca.val[0] = d;
                sca.val[1] = e;
                sca.val[2] = f;
                cvSet2D(workImg,n,m,sca);
            }
        }
    cvShowImage("Mandelbrot",workImg);
}
void drawmandelbrot()
{
    int m,n;
    int a,b,c;
    int d,e,f;
    int i;
    double real,imaginary;
    double deltaX = (XMax - XMin)/M;
    double deltaY = (YMax - YMin)/M;
    for(m = 0;m < M;m++)
    {
        for(n = 0;n < M;n++)
        {
            i = judge(real,imaginary);
            real = XMin + m*deltaX;
            imaginary = YMin + n*deltaY;
            CvScalar sca;
            if(judge(real,imaginary) - 200 == 0)
            {
                a = m;
                b = n;
                c = n + m;
                sca.val[0] = a;
                sca.val[1] = b;
                sca.val[2] = c;
                cvSet2D(workImg,n,m,sca);
            }
            else
            {
                d = (sin(6*i))*60 + 0.5*abs(200 - m) + 70;
                e = (cos(5*i))*60 + 0.5*abs(200 - n) + 70;
                f = (sin(100*i))*60 + 0.5*abs(200 - n) + 70;
                sca.val[0] = d;
                sca.val[1] = e;
                sca.val[2] = f;
                cvSet2D(workImg,n,m,sca);
            }
        }
    }
}
