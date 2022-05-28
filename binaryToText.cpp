#include "header.h"
#include<fstream>
#include<math.h>

using namespace std;

void binaryToText(int binaryLength,int* binary)
{
    int* decimal = new int[1000000];
  //  int decimal[1000]={0};
    int index = 0, cnt = 7;
   
  
    for(int i=0; i<binaryLength; i++)
    {
        int binaryCnt = 0;
        while(binaryCnt <= 7){
            if(binaryCnt==6)
            {
              
            }
            decimal[index] += pow(2,cnt) * binary[i];
            cnt--;
            i++;
            binaryCnt++;
        }
        cout<<(char)decimal[index];
        i--;
        cnt = 7;       //start of a binary code
        index++;
        }
      //  string text;
    char* text = new char[10000000];  
    for(int i=0;i<index;i++)
    {
    
    //text[i]=decimal[i];
    }
    
    text[index]='\0';

   //cout<<text<<endl;
  //  cout<<"Text size: "<<text.length()<<endl;

}




