#include "header.h"

using namespace std;

int main()
{
    int binaryLength=0;
    int binary[100000]={};

    extern int pixels[10000000][3];
    extern int width;
    extern int height;

    readImage("demo1.bmp");
    binaryLength = textToBinary("Test1.txt", binary, binaryLength);
    hideData(pixels,width,height,binary,binaryLength);
    binaryToText(binaryLength-15,binary);
   // copyImageFile();

    return 0;
}
