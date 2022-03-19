#include <bits/stdc++.h>
using namespace std;

void readImage(char* path);
void decimalToBinary(int pixels[][3],int widthOfImage,int heightOfImage);
int textToBinary(char *textPath, int binary[], int binaryLength);
void binaryToText(int binaryLength,int binary[]);
int encryptText(int key);
int decryptText(int key);
void copyImageFile();
void hideData(int pixels[][3],int widthOfImage,int heightOfImage,int binary[],int binaryLength);
