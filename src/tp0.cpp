#include <opencv.hpp>
#include <highgui.hpp>
#include <stdio.h>
using namespace cv;

int main( int argc, char** argv )
{
  Mat image;
  image = imread( "images/test.jpg" );

  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  namedWindow( "Display Image", CV_WINDOW_AUTOSIZE );
  imshow( "Display Image", image );

  waitKey(0);

  return 0;
}
