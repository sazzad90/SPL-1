#include "header.h"

using namespace std;

int delimiter = 1111111111;

void hideData(int pixels[][3],int widthOfImage,int heightOfImage,int binary[],int binaryLength){
     int index = 0;
     int i = 0, j = 0;

     while(index <= binaryLength){
        if(j==3){
        j = 0;
        i++;
        }
       // cout<<i<<" "<<j<<endl;

        int temp = pixels[i][j];
        int divisor = 10000000;
        for(int k = 0; k < 7; k++){
            temp = temp%divisor;
            divisor = divisor/10;
        }
        cout<<binary[index]<<" "<<temp<<endl;

        if(temp == binary[index]){

        }

        else{
            if(temp == 1){
                pixels[i][j] = pixels[i][j] - 1;
            }
            else{
                pixels[i][j] = pixels[i][j] + 1;
            }
        }

        cout<<pixels[i][j]<<endl;

        j++;
        index++;
     }


 /*  for(int i=0;i<widthOfImage;i++)
    {
        for(int j=0; j<heightOfImage; j++)
        {
           cout<<pixels[i*widthOfImage+j][0]<<" "<<pixels[i*widthOfImage+j][1]<<" "<<pixels[i*widthOfImage+j][2]<<"    ";
        }
        cout<<endl;
    }
    */




}
