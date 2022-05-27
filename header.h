#pragma once
#include <fstream>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <graphics.h>
#include <windows.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "headerstructure.cpp"
#include "ppmStructure.cpp"  
#include "ShowInfo.cpp"
#include "checkfile.cpp"
#include "PixelData.cpp"
#include "writeimage.cpp"
#include "textToBinary.cpp"
#include "binaryToText.cpp"
#include "decimalToBinary.cpp"
#include "binaryToDecimal.cpp"
#include "hideData.cpp"
#include "extract.cpp"
#include "getMouseClick.cpp"
#include "window.cpp"

using namespace std;



//void readHeaderAndPrint(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader);
//void checkFile(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader);
void readImage(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader, bmpColorTable colorTable, const char* imageFile, int pixels[][1000][3]);
void copyImageFile();
ppmFile* readPPMImage(const char *imageFile, int pixels[][1000][3]);  //
void writeImage(const char *imageName, ppmFile *imageFile);  //
int textToBinary(const char *textPath, int binary[], int binaryLength);
void binaryToText(int binaryLength,int binary[]);
void binaryToDecimal(int pixels[][1000][3], int width, int height);
void decimalToBinary(int pixels[][1000][3],int widthOfImage,int heightOfImage);
void hideData(const char *imageFile, const char *textFile);
void extract(const char *stegoImage);
void getMouseClick(int click[]);
void drawWindow();


