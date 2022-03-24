#include <fstream>
#include "header.h"
using namespace std;

void writeImage(int pixels[][3], int width, int height, ofstream &outputFile){

        for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            //inputfile.read(reinterpret_cast<char*>(color),3);

            color[0] = static_cast<unsigned char>(pixels[i*width+j][2]);
            color[1] = static_cast<unsigned char>(pixels[i*width+j][1]);
            color[2] = static_cast<unsigned char>(pixels[i*width+j][0]);
            outputFile.write(reinterpret_cast<char*>(color),3);

      //      pixels[i*width+j][0] = static_cast<float>(color[2]);//   /255.0f;
      //      pixels[i*width+j][1] = static_cast<float>(color[1]);//   /255.0f;
       //     pixels[i*width+j][2] = static_cast<float>(color[0]);//   /255.0f;
        }

      //  inputfile.ignore(paddingAmount);
    }

    outputFile.close();

}














/*
void copyImageFile()
{
    char input;
    ifstream inputFile;
    ofstream outputFile;


    inputFile.open("demo1.bmp", ios:: binary);
    outputFile.open("copy1.bmp", ios :: binary);

    if(inputFile.is_open() && outputFile.is_open())
    {
        while(!inputFile.eof())
        {
            inputFile.get(input);
            outputFile<<input;
        }

        inputFile.close();
        outputFile.close();

        cout <<"\nfile copy successful!"<<endl;
    }
    else
    {
        cout <<"\nfile copy unsuccessful!"<<endl;
    }
}
*/
