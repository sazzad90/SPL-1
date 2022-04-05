#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "header.h"
using namespace std;

void copyImageFile()
{
    char input;
    ifstream inputFile;
    
    ofstream outputFile;


    inputFile.open("x.bmp", ios:: binary);
    
    outputFile.open("xcopy.bmp", ios :: binary);

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
        cout <<"\ncopy no work"<<endl;
    }
}