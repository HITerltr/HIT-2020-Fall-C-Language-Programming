 #include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <highgui.h>
#define IMAGE_SIZE 128
int main()
{
printf("opencv install test!\n");
IplImage *pImg = cvCreateImage (/*size*/cvSize (IMAGE_SIZE, IMAGE_SIZE),
/*depth*/ 8, /*n Channels*/3);
cvNamedWindow (/*name of the window*/"mandelbrot", 1);
cvShowImage ("mandbrot", pImg);
cvWaitKey (/*delay*/0);
cvDestroyWindow ("mandlbrot");
cvRelease(&pImg);
return 0;
}
