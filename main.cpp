#include "header.h"

using namespace std;

int main()
{
    int binaryLength=0;
    int binary[100000]={};

    readImage("demo3.bmp");
    binaryLength= textToBinary("Test1.txt", binary, binaryLength);
    binaryToText(binaryLength,binary);

    return 0;
}
