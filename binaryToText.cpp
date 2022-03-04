#include "header.h"
#include<fstream>
#include<math.h>

using namespace std;

void binaryToText(int binaryLength,int binary[])
{
    int decimal[1000]={0};
    int index = 0, cnt = 7;

    for(int i=0; i<binaryLength; i++)
    {
        int binaryCnt = 0;
        while(binaryCnt <= 7){
                          //end of a binary code
            decimal[index] += pow(2,cnt) * binary[i];
           // cout<<decimal[index]<<" "<<pow(2,cnt)<<" "<<binary[endIndex]<<endl;
            cnt--;
            i++;
            binaryCnt++;

        }
        i--;
        cnt = 7;       //start of a binary code
        index++;
        }

    char text[1000];  //array to store converted message

    for(int i=0;i<index;i++)
    {
    text[i]=decimal[i];
    }

    cout<<"Text after conversion:: ";
    text[index]='\0';
    cout<<text<<endl;

}


