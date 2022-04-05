#include <fstream>
#include <iomanip>
#include <cmath>
#include "header.h"
using namespace std;


void readImage(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader,bmpColorTable colorTable, const char* imageFile, int pixels[][1000][3])
{   
    
     ifstream inputFile;
    inputFile.open(imageFile, ios:: binary);
    if(inputFile.eof()) throw runtime_error("File not found");
    inputFile.seekg(0,ios::beg);
    inputFile.read((char*)&signature,sizeof(signature));
    inputFile.read((char*)&fileHeader,sizeof(fileHeader));
    inputFile.read((char*)&infoHeader,sizeof(infoHeader));
    inputFile.read((char*)&colorHeader,sizeof(colorHeader));
    inputFile.read((char*)&colorTable,sizeof(colorTable));
    
    int width=infoHeader.width;
    int height= infoHeader.height;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            inputFile.read(reinterpret_cast<char*>(color),3);
            pixels[i][j][0] = static_cast<float>(color[2]); //red
            pixels[i][j][1] = static_cast<float>(color[1]); //green
            pixels[i][j][2] = static_cast<float>(color[0]); //blue
        }
    }


   
    inputFile.close();
}


