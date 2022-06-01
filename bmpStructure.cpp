 #include <fstream>
#include <iomanip>
#include <cmath>
#include "header.h"
using namespace std;
//contains bmp signature
struct bmpSignature
{
    unsigned char signatureData[2]; //BM is .bmp file
};
 
//contains bmp file header information
struct bmpFileHeader
{
    unsigned int fileSize{0}; //filesize in byte
    unsigned short reserved1{0}; //reserved 
    unsigned short reserved2{0}; //reserved
    unsigned int dataOffset{0}; //start of pixel data
};
//contains bmp info header information
struct bmpInfoHeader
{
    unsigned int headerSize{0}; //headersize in byte
    unsigned int width{0}; //image width in px
    unsigned int height{0}; //image height in px
    unsigned short planes{1};  //number of planes 
    unsigned short bpPixels{0}; //number of bits per pixel
    unsigned int compression{0}; //compression type 0 is uncompressed
    unsigned int imageSize{0}; 
    unsigned int pixelPerMeterX{0}; //pixel per meter along x axis
    unsigned int pixelPerMeterY{0}; //pixel per meter along y axis
    unsigned int colorsInColorTable{0}; //number of colors in color table
    unsigned int importantcolorCount{0}; //number of colors used
};
//contains bmp color header information
struct bmpColorHeader{
    unsigned int red{0x00ff0000 }; //red channel bitmask
    unsigned int green{0x0000ff00 }; //green channel bitmask
    unsigned int blue{0x000000ff}; //blue channel bitmask
    unsigned int alpha{0xff000000}; //alpha channel bitmask
    unsigned int color{0x73524742};    //color space type usually sRGB default
};

//contains bmp color table information
struct bmpColorTable
{
    unsigned int colorDefinition[256];
};
