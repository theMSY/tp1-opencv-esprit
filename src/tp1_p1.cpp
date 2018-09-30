#include <opencv.hpp>
#include <highgui.hpp>
#include <stdio.h>
using namespace cv;

int main( int argc, char** argv )
{
  Mat image,gray_image,hsv_image;
  image = imread( "images/test.jpg" );


  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  // Showing original Image
  imshow( "Normal Image", image );

  // Converting to Grayscale
  cvtColor(image,gray_image,CV_BGR2GRAY);

  // Showing Grayscale Image
  imshow( "Gray Image", gray_image );

  // Saving the grayscale image to our "images" folder.
  imwrite("images/test_grayscale.jpg",gray_image);

  // Converting image to HSV
  cvtColor(image,hsv_image,CV_BGR2HSV);

  // Showing our HSV image
  imshow( "HSV Image", hsv_image );

  // Saving our HSV image to our "images" folder.
  imwrite("images/test_hsv.jpg",hsv_image);

  waitKey(0);

  return 0;
}
