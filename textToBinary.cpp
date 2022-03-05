#include "header.h"
#include<fstream>

using namespace std;

int textToBinary(char *textPath, int binary[], int binaryLength)
{
    string message,space;
    string input;
    ifstream file(textPath);

    while(file)
    {
    getline(file, input);
    if(file)
    {
        message +='\n';
        message+=input;
    }
    }


    cout<<"Text before converting to binary:: ";
    cout<<message<<endl;
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
            mini[temp] = encryptText(mini[temp]);         //encrypting message altering 0 and 1 at every 7th place
        }
        binary[length]=mini[temp];
        temp--;
        length++;
        }
       // binary[length++]=11111111;  //delimiter
}
       binaryLength=length-1;        //length of binary array


    cout<<"Encryption is done."<<endl;

    cout<<"Binary format for text::"<<endl;
    for(int i=0;i<length;i++)
    {
    cout<<binary[i];
    }
    cout<<endl;
    return binaryLength;

}

