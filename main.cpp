#include "header.h"

using namespace std;

int main ()
{

    //drawWindow();
    int imageFormat;
    imageFormat = hideData("BMP3.ppm", "test.txt");
    
    if(imageFormat == 0){
          extract("stegoBMP.bmp", imageFormat);
          } 
    else if(imageFormat == 1){
          extract("stegoPPM.ppm", imageFormat);
          }
    else{
          cout<<"Message is too large for hiding."<<endl;
          }
   
   return 0;
} 