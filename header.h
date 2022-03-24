#include <bits/stdc++.h>
using namespace std;

void readImage(char* path);
void decimalToBinary(int pixels[][3],int widthOfImage,int heightOfImage);
int textToBinary(char *textPath, int binary[], int binaryLength);
void binaryToText(int binaryLength,int binary[]);
int encryptText(int key);
int decryptText(int key);
void writeImage(int pixels[][3], int width, int height, ofstream &outputFile);
void hideData(int pixels[][3],int widthOfImage,int heightOfImage,int binary[],int binaryLength);
void binaryToDecimal(int pixels[][3], int width, int height);
