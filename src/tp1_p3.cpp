#include <opencv.hpp>
#include <highgui.hpp>
#include <stdio.h>
using namespace cv;

int main( int argc, char** argv )
{
  Mat image,zoomed_in_image,zoomed_out_image;
  image = imread( "images/test.jpg" );


  if( argc != 2 || !image.data )
    {
      printf( "No image data \n" );
      return -1;
    }

  // Showing original Image
  imshow( "Normal Image", image );



  // Zooming In Image
  pyrUp( image, zoomed_in_image, Size( image.cols*2, image.rows*2 ));

  // Showing Zoomed-in Image
  imshow( "Zoomed-in Image", zoomed_in_image );

  // Zooming Out Image
  pyrDown( image, zoomed_out_image, Size( image.cols/2, image.rows/2 ));

  // Showing Zoomed-out Image
    imshow( "Zoomed-out Image", zoomed_out_image );

  // Saving modified images
  imwrite("images/zoomed_in_image.jpg",zoomed_in_image);
  imwrite("images/zoomed_out_image.jpg",zoomed_out_image);


  waitKey(0);

  return 0;
}
