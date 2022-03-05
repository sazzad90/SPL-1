#include "header.h"
#include<fstream>

using namespace std;

const int fileHeaderSize=14;
const int infoHeaderSize=40;

unsigned char fileHeader[fileHeaderSize];
unsigned char infoHeader[infoHeaderSize];

int pixels[10000000][3]={0};

void readImage(char* path)
{
    ifstream file;
    file.open(path , ios:: in | ios:: binary);

    if(!file.is_open())
   {
        cout<<"File cannot be read"<<endl;
        return;
    }

    file.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);   //this method only takes short pointer/char pointer
    file.read(reinterpret_cast<char*>(infoHeader),infoHeaderSize);   //this method only takes short pointer/char pointer

    int fileSize=fileHeader[2]+(fileHeader[3]<<8)+(fileHeader[4]<<16)+(fileHeader[5]<<24);
    int width=infoHeader[4]+(infoHeader[5]<<8)+(infoHeader[6]<<16)+(infoHeader[7]<<24);
    int height=infoHeader[8]+(infoHeader[9]<<8)+(infoHeader[10]<<16)+(infoHeader[11]<<24);

    const int paddingAmount=((4-(width*3)%4)%4);

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            file.read(reinterpret_cast<char*>(color),3);

            pixels[i*width+j][0] = static_cast<float>(color[2]);//   /255.0f;
            pixels[i*width+j][1] = static_cast<float>(color[1]);//   /255.0f;
            pixels[i*width+j][2] = static_cast<float>(color[0]);//   /255.0f;
        }

        file.ignore(paddingAmount);
    }

    decimalToBinary(pixels,width,height);


   for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
           cout<<pixels[i*width+j][0]<<" "<<pixels[i*width+j][1]<<" "<<pixels[i*width+j][2]<<"    ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Image width:: "<<width<<endl;
    cout<<"Image height:: "<<height<<endl;

    cout<<"Image file is read."<<endl;
    cout<<endl;

    file.close();
}

