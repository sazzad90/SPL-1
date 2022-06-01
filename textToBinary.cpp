#include "header.h"
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

int textToBinary(const char *textPath, int* binary, int binaryLength)
{
    string message,space;
    string input;
    ifstream file(textPath);

    if(!file){
        cout<<endl;
         cout<<"Text file not found in the directory."<<endl;
		 cout<<"Data hiding cannot be done."<<endl;
         cout<<endl;
         return 0;
    }
    while(file)
    {
    getline(file, input);
    if(file)
    {
        message +='\n';
        message+=input;
    }
    }
    cout<<endl;
    cout<<"Text message: "<<endl;
    cout<<message<<endl;
    cout<<endl;
    cout<<endl;
    

    file.close();

    int i=0, j=0, length=0;
    int number;
    int mini[50]={0};
    
    for(int i=0;i<message.length();i++)
    {
        number=message[i];
        j=0;                    //initializer index for mini
        while(number>0)
        {
        mini[j] = number%2;
        number = number/2;
        j++;
        }
        int temp=j-1; //end index for mini
        if(j<8)
        {
            while(j < 8){
                binary[length++] = 0;
                j++;
            }
        }
        while(temp>=0)
        {
        if(temp==1){
          //  mini[temp] = encryptText(mini[temp]); //encrypting message altering 0 and 1 at every 7th place
        }
        binary[length]=mini[temp];
        temp--;
        length++;
        }
}

binaryLength = length;
/*
    for(int i= 0;i<binaryLength;i++){
        cout<<binary[i];
    }
    cout<<endl;
    */

    //length of binary array

  
    char inputMessage[binaryLength]={};
    int x;
    for(x = 0;x<binaryLength;x++){
          inputMessage[x] =(char) binary[x] + '0';
          
    }
    inputMessage[x] = '\0';


    
int inputMessage_size = sizeof(inputMessage) / sizeof(char);
string inputMessageString="";

for(i = 0; i < inputMessage_size; i++)  
   {  
    /** retrieving and merging the value of character array on position 'i'*/    
        inputMessageString += inputMessage[i];  
    }  

    //encryption
   cout<<"Before Encrytion : "<<inputMessageString<<endl;
    cout<<endl;
   string cipherText = des(inputMessageString,true);
   
   cout<<"After Encryption : "<<endl;
   cout<<"Cipher Text : "<<cipherText<<endl;

    for(int i = 0;i<cipherText.length();i++){   /////
         binary[i] = (int)cipherText[i] - '0' ;
    }

    binaryLength = cipherText.length();
    
    
      for(int i = 0;i<15; i++){
        binary[binaryLength++] = 1;
       
    }
    
    binaryLength = binaryLength - 1;  //length of binary array after adding delimiter

    return binaryLength;
}
