#include "header.h"
using namespace std;
void decimalToBinary(int pixels[][3],int widthOfImage,int heightOfImage)
{
    int number;
    int  binary[1000]={0};
    int j=0,k;
    int length=0;            //track for binary array
    int index=0;             //bytes of pixels
    int mini[20]={0};        //array to reverse lsb

    for(int i=0;i<heightOfImage*widthOfImage;i++)
    {
       while(index<=2){
       number=pixels[i][index];
       j=0;                    //initializer index for mini
       while(number>0)
       {
        mini[j] = number%2;
        number = number/2;
        j++;
       }
    int temp=j-1;            //end index for mini

    while(temp>=0)
    {
        binary[length]=mini[temp];
        temp--;
        length++;
    }
    length=0;

    int divisor=10000000;
    pixels[i][index]=0;

    for(int k=0;k<8;k++){
        pixels[i][index]=pixels[i][index]+(divisor*binary[k]);
        divisor=divisor/10;
    }

    index++;
    }
    index=0;
    }

}
