#pragma once
#include <fstream>
#include <iomanip>
#include <cmath>
#include "header.h"
using namespace std;
string decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];
    string actualhexa="";
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
 
    // printing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        
        actualhexa+=hexaDeciNum[j];
    }
    return actualhexa;
}


void readHeaderAndPrint(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader)
{
    ifstream inputFile;
    inputFile.open("x.bmp",ios:: binary);
    if(inputFile.eof()) return;
    //accessing data
    inputFile.seekg(0,ios::beg);
    inputFile.read((char*)&signature,sizeof(signature)); // memory allocation problem if signature is in fileHeader.Char and int///////
    inputFile.read((char*)&fileHeader,sizeof(fileHeader));
    inputFile.read((char*)&infoHeader,sizeof(infoHeader));
    inputFile.read((char*)&colorHeader,sizeof(colorHeader));

    //colorTableSize = infoHeader.colorsInColorTable;

    bmpColorTable colorTable;
    inputFile.read((char*)&colorTable,sizeof(colorTable));

    inputFile.close();

    //bmp header info
    cout <<"BMP Header\n"<<endl;

    cout <<"BMP Signature       : "<<signature.signatureData[0]<<signature.signatureData[1]<<endl;
    cout <<"BMP file size       : "<<fileHeader.fileSize<<" bytes"<<endl;
    cout <<"BMP reserved1       : "<<fileHeader.reserved1<<endl;
    cout <<"BMP reserved2       : "<<fileHeader.reserved2<<endl;
    cout <<"BMP dataOffset      : "<<fileHeader.dataOffset<<" bytes"<<endl;
    //bmp info header info
    cout <<"\nInfo  Header\n"<<endl;

    cout <<"BMP file size             : "<<infoHeader.headerSize<<" bytes"<<endl;
    cout <<" BMP width                : "<<infoHeader.width<<" bytes"<<endl;
    cout <<" BMP height               : "<<infoHeader.height<<" bytes"<<endl;
    cout <<" BMP planes               : "<<infoHeader.planes<<" bytes"<<endl;
    cout <<" BMP bit per pixel        : "<<infoHeader.bpPixels<<" bytes"<<endl;
    cout <<" BMP compression          : "<<infoHeader.compression<<" bytes"<<endl;
    cout <<" BMP image size           : "<<infoHeader.imageSize<<" bytes"<<endl;
    cout <<" BMP important color Count: "<<infoHeader.importantcolorCount<<" bytes"<<endl;
   
    //bmp color header info
    //saving color info in hexadecimal
    unsigned int redC=colorHeader.red;
    int redChannel=(int) redC;
    string redh=decToHexa(redChannel);

    unsigned int greenC=colorHeader.green;
    int greenChannel=(int) greenC;
    string greenh=decToHexa(greenChannel);

    unsigned int blueC=colorHeader.blue;
    int blueChannel=(int) blueC;
    string blueh=decToHexa(blueChannel);

    unsigned int alphaC=colorHeader.alpha;
    int alphaChannel=(int) alphaC;
    string alphah=decToHexa(alphaChannel);

    unsigned int colorC=colorHeader.color;
    int colorChannel=(int) colorC;
    string colorh=decToHexa(colorChannel);

    cout<<"\nColor Header\n"<<endl;
    cout <<" BMP red channel bit mask   : "<<redh<<endl;
    cout <<" BMP green channel bit mask : "<<greenh<<endl;
    cout <<" BMP blue channel bit mask  : "<<blueh<<endl;
    cout <<" BMP alpha channel bit mask : "<<alphah<<endl;
    cout <<" BMP color space type       : "<<colorh<<endl;

}

