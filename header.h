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

#include "bmpStructure.cpp"
#include "ppmStructure.cpp"  
#include "textToBinary.cpp"
#include "binaryToText.cpp"
#include "decimalToBinary.cpp"
#include "binaryToDecimal.cpp"
#include "hideData.cpp"
#include "extract.cpp"


using namespace std;


void readImage(bmpSignature signature,bmpFileHeader fileHeader,bmpInfoHeader infoHeader, bmpColorHeader colorHeader, bmpColorTable colorTable, const char* imageFile, int pixels[][1000][3]);
//void copyImageFile();
ppmFile* readPPMImage(const char *imageFile, int*** pixels);  
//void writeImage(const char *imageName, ppmFile *imageFile);  
int textToBinary(const char *textPath, int* binary, int binaryLength);
void binaryToText(int binaryLength,int* binary);
void binaryToDecimal(int*** pixels, int width, int height);
void decimalToBinary(int*** pixels,int widthOfImage,int heightOfImage);
int hideData(const char *imageFile, const char *textFile);
void extract(const char *stegoImage, int imageFormat);
void getMouseClick(int click[]);
void drawWindow();


