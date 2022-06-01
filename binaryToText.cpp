#include "header.h"
#include<fstream>
#include<math.h>

using namespace std;

void binaryToText(int binaryLength,int* binary)
{

    char inputMessage[binaryLength]={};
    for(int i = 0;i<binaryLength;i++){
          inputMessage[i] =(char) binary[i] + '0';
      
          
    }
//int inputMessage_size = sizeof(inputMessage) / sizeof(char);
string inputMessageString="";

for(int i = 0; i < binaryLength; i++)  
   {  
    /** retrieving and merging the value of character array on position 'i'*/    
        inputMessageString += inputMessage[i];  
    }  

    //encryption
    
    string decodedText = des(inputMessageString,false);
    
    cout<<"After Decryption : "<<endl;
    cout<<"Decoded text : "<<decodedText<<endl;

    for(int i = 0;i<decodedText.length()-1;i++){
         binary[i] = (int)decodedText[i] - '0' ;
        
    }
    cout<<endl;
   // int* decimal = new int[1000000];
  
    string output = "";
   int decimal[100000]={0};
    int index = 0, cnt = 7;
   
    binaryLength = decodedText.length() - 1;//
    


        for(int i=0; i<binaryLength; i++)      //binaryLength
    {
        int binaryCnt = 0;
        while(binaryCnt <= 7){
  //
            decimal[index] += pow(2,cnt) * binary[i];
            cnt--;
            i++;
            binaryCnt++;
        }
      //  cout<<(char)decimal[index]<<endl;
        //cout<<(char)decimal[index] + '0'<<endl;
        output += (char)decimal[index] ;
        i--;
        cnt = 7;       //start of a binary code
        index++;
        
        }
        
        cout<<"Plain text : "<<output<<endl;
        cout<<endl;
      //  string text;
    char* text = new char[10000000];  
    for(int i=0;i<index;i++)
    {
    
    //text[i]=decimal[i];
    }
    text[index]='\0';


}




