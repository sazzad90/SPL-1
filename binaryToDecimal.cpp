#include "header.h"
#include<fstream>
#include<math.h>

using namespace std;

void binaryToDecimal(int*** pixels, int width, int height)
{

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {

            int k = 0;
            while(k<=2){
            int index = 0;
            int temp = pixels[i][j][k];
            pixels[i][j][k] = 0;

            while(temp){
                int remainder = temp%10;
                pixels[i][j][k] += pow(2,index) * remainder;
                temp = temp/10;
                index++;

            }
            k++;
            }
        }
    }
}






