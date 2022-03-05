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
            if(binaryCnt==6)
            {
                binary[i] = decryptText(binary[i]);          //decrypting message again altering 0 and 1 at every 7th place
            }
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

    char text[10000];  //array to store converted message

    for(int i=0;i<index;i++)
    {
    text[i]=decimal[i];
    }

    text[index]='\0';

    cout<<"Decryption is done."<<endl;
    cout<<"Text after converting from binary:: ";
    cout<<text<<endl;

}


