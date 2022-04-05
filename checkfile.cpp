#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include "header.h"
using namespace std;
void checkFile(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader)
{
    ifstream inputFile;
    inputFile.open("x.bmp",ios:: binary);
    if(inputFile.eof()) throw runtime_error("File not found");
    inputFile.seekg(0,ios::beg);
    inputFile.read((char*)&signature,sizeof(signature));
    inputFile.read((char*)&fileHeader,sizeof(fileHeader));
    inputFile.read((char*)&infoHeader,sizeof(infoHeader));
    inputFile.read((char*)&colorHeader,sizeof(colorHeader));
    inputFile.close();

      if(inputFile)
    {
         //check if file is bmp
        if(signature.signatureData[0]!='B' || signature.signatureData[1]!='M')
        {
            throw runtime_error("File is not a bmp file");
        } 
        //check if height and width are positive
        if(infoHeader.height<0 || infoHeader.width<0)
        {
            throw runtime_error("Height and width must be positive");
        }
        
    }
    else
    {
        cout<<"File not found"<<endl;
    }
}
