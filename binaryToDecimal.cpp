#include "header.h"
#include<fstream>
#include<math.h>

using namespace std;

void binaryToDecimal(int pixels[][3], int width, int height)
{


    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {

            int k = 0;
            while(k<=2){
            int index = 0;
            int temp = pixels[i*width+j][k];
            pixels[i*width+j][k] = 0;

            while(temp){
                int remainder = temp%10;
                pixels[i*width+j][k] += pow(2,index) * remainder;
                temp = temp/10;
                index++;

            }
            k++;
            }
        }
    }


//       for(int i=0;i<width;i++)
//    {
//        for(int j=0;j<height;j++)
//        {
//           cout<<pixels[i*width+j][0]<<" "<<pixels[i*width+j][1]<<" "<<pixels[i*width+j][2]<<"    ";
//        }
//        cout<<endl;
//    }

}





