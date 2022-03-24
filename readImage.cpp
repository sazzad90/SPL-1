#include "header.h"
#include<fstream>

using namespace std;

const int signatureSize = 2;
const int fileHeaderSize = 14;
const int infoHeaderSize = 40;


unsigned char signatureHeader[signatureSize];
unsigned char fileHeader[fileHeaderSize];
unsigned char infoHeader[infoHeaderSize];

int pixels[10000000][3]={0};
int width, height;
ofstream outputFile;

void readImage(char* path)
{
    ifstream inputfile;

    inputfile.open(path , ios:: in | ios:: binary);
    outputFile.open("stego.bmp", ios :: binary);

    inputfile.seekg(0,ios::beg);
    outputFile.seekp(0,ios::beg);

    inputfile.read((char*)&signatureHeader,sizeof(signatureHeader));

       if(signatureHeader[0] != 'B' || signatureHeader[1] != 'M'){
        cout<<"This is not a BMP image file!!"<<endl;
        return;
    }

    inputfile.read((char*)&fileHeader,sizeof(fileHeader));
    inputfile.read((char*)&infoHeader,sizeof(infoHeader));

//    inputFile.read((char*)&colorHeader,sizeof(colorHeader));

    outputFile.write((char*)&signatureHeader,sizeof(signatureHeader));
    outputFile.write((char*)&fileHeader,sizeof(fileHeader));
    outputFile.write((char*)&infoHeader,sizeof(infoHeader));

//    outputFile.write((char*)&colorHeader,sizeof(colorHeader));

    if(!inputfile.is_open())
   {
        cout<<"File cannot be read"<<endl;
        return;
    }

//    inputfile.read(reinterpret_cast<char*>(signatureHeader),signatureSize);

 //   inputfile.read(reinterpret_cast<char*>(fileHeader),fileHeaderSize);   //this method only takes short pointer/char pointer
 //   inputfile.read(reinterpret_cast<char*>(infoHeader),infoHeaderSize);   //this method only takes short pointer/char pointer

    int fileSize=fileHeader[2]+(fileHeader[3]<<8)+(fileHeader[4]<<16)+(fileHeader[5]<<24);
    width=infoHeader[4]+(infoHeader[5]<<8)+(infoHeader[6]<<16)+(infoHeader[7]<<24);
    height=infoHeader[8]+(infoHeader[9]<<8)+(infoHeader[10]<<16)+(infoHeader[11]<<24);

    const int paddingAmount=((4-(width*3)%4)%4);

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            inputfile.read(reinterpret_cast<char*>(color),3);

            pixels[i*width+j][0] = static_cast<float>(color[2]);//   /255.0f;
            pixels[i*width+j][1] = static_cast<float>(color[1]);//   /255.0f;
            pixels[i*width+j][2] = static_cast<float>(color[0]);//   /255.0f;
        }

        inputfile.ignore(paddingAmount);
    }

    decimalToBinary(pixels,width,height);       //converting decimal pixels into binary


//   for(int i=0;i<width;i++)
//    {
//        for(int j=0;j<height;j++)
//        {
//           cout<<pixels[i*width+j][0]<<" "<<pixels[i*width+j][1]<<" "<<pixels[i*width+j][2]<<"    ";
//        }
//        cout<<endl;
//    }




    cout<<"Image width:: "<<width<<endl;
    cout<<"Image height:: "<<height<<endl;

    cout<<"Image file is read."<<endl;
    cout<<endl;

    inputfile.close();
}

