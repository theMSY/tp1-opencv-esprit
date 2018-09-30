#include <opencv.hpp>
#include <highgui.hpp>
#include <stdio.h>
using namespace cv;

int main( int argc, char** argv )
{
  Mat image,modified_image;
  image = imread( "images/test.jpg" );


  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  // Showing original Image
  imshow( "Normal Image", image );


  // Define our colored area
  int x = 100;
  int y = 100;
  int width = 50;
  int height = 10;
  Rect rect (x, y, width, height);



  // I'm using a different image with different resolution and ( X,Y ) coordinates
  // I'm using this method because it's the proper way to do it in C++ (uses OOP logic)
  // "cvSetXD and cvGetXD are old style C syntax."  Quote from this Stackoverflow entry : <link>https://stackoverflow.com/a/32922712</link>
  rectangle(image,rect,Scalar(255,255,255),CV_FILLED);

  // Showing the modified image
  imshow( "Modified Image", image );

  // Saving modified
  imwrite("images/colored_image.jpg",image);


  waitKey(0);

  return 0;
}
