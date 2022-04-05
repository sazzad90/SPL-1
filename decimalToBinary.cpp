#include "header.h"
#include<cmath>
using namespace std;
void decimalToBinary(int pixels[][1000][3],int widthOfImage,int heightOfImage)
{
    int number;
    int  binary[20]={0};
    int l=0;
    int length=0;            //track for binary array
    int index=0;             //bytes of pixels
    int mini[20]={0};        //array to reverse 

    for(int i=0;i<heightOfImage;i++)
    {
        for(int j = 0; j<widthOfImage; j++){
       while(index<=2){
       number = pixels[i][j][index];
       l=0;                  //initializer index for mini

       if(number == 0) pixels[i][j][index++] = 00000000;

       else{
       while(number>0)
       {
        mini[l] = number%2;
        number = number/2;
        l++;
       }
    int temp=l-1;            //end index for mini


    length=0;
    while(temp>=0)
    {
        binary[length]=mini[temp];
        temp--;
        length++;
    }
    double flag = length-1;

    double divisor = pow(10,flag);
    
    pixels[i][j][index]=0;

    for(int k=0;k<=length-1;k++){          //
        pixels[i][j][index]=pixels[i][j][index]+(divisor*binary[k]);
        divisor = divisor/10;
    }
    
    index++;
       }
    }
    index=0;
    } 
    }
   
    
}