#include "header.h"
#include <bits/stdc++.h>
using namespace std;


void extract(const char *stegoImage){
    
    int*** pixels2 = new int** [3000];
    for(int i = 0;i<3000;i++){
        pixels2[i] = new int* [3000]; 
        for(int j = 0;j<3000;j++){
            pixels2[i][j] = new int[3];
        }
    }
 /*   
    bmpSignature signature;
    bmpFileHeader fileHeader;
    bmpInfoHeader infoHeader;
    bmpColorHeader colorHeader;
    bmpColorTable colorTable;

     ifstream inputFile;
     

    inputFile.open(stegoImage, ios:: binary);

    if(inputFile.eof()) throw runtime_error("File not found");
    inputFile.seekg(0,ios::beg);

    inputFile.read((char*)&signature,sizeof(signature));
    inputFile.read((char*)&fileHeader,sizeof(fileHeader));
    inputFile.read((char*)&infoHeader,sizeof(infoHeader));
    inputFile.read((char*)&colorHeader,sizeof(colorHeader));

    int width=infoHeader.width;
    int height= infoHeader.height;


        for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            inputFile.read(reinterpret_cast<char*>(color),3);
            pixels2[i][j][0] = static_cast<float>(color[2]); //red
            pixels2[i][j][1] = static_cast<float>(color[1]); //green
            pixels2[i][j][2] = static_cast<float>(color[0]); //blue
     
        }

    }
    

    decimalToBinary(pixels2,width,height);

//************reading the encoded text from pixels**********/
/*
int binary[100000]={};
int final_flag = 1;
int i=0,j=0,k=0;
int index = 0,cnt = 0;

while(final_flag != 0){
    int temp = pixels2[i][j][k];

    if(temp < 10){
        binary[index++] = temp;
        
    }
    else if(temp == 10){
        binary[index++] = 0;
       
    }
    else{
        binary[index++] = temp % 10;
        
    }


    if(binary[index-1] == 1){
        cnt++;
    }
    else{
        cnt = 0;
    }
    if(cnt == 15){
        final_flag = 0;
    }


    k++;
    if(k ==3){
        k = 0;
        j++;
        if(j == width){
        j = 0;
        i++;
    }
    }
    
}

//***********converting binary into text**************/
/*
cout<<"After extraction :: ";
binaryToText(index-15,binary);
*/
    
  //  ppmFile* input;
     
    ppmFile* inputFile = readPPMImage(stegoImage,pixels2);

cout<<"after second read: "<<endl;
    for(int i = 0;i<4;i++){
cout<<pixels2[0][i][0]<< " "<<pixels2[0][i][1]<<" "<<pixels2[0][i][2]<<"   ";
	}
	cout<<endl;
    decimalToBinary(pixels2,inputFile->col,inputFile->row);
    
        //**********  hiding text into image  **********// 

    for(int j = 0;j<20;j++){
            cout<<pixels2[0][j][0]<<" "<<pixels2[0][j][1]<<" "<<pixels2[0][j][2]<<"   ";
        }
    cout<<endl;

//************reading the encoded text from pixels**********//

int binary[100000]={};
int final_flag = 1;
int i=0,j=0,k=0;
int index = 0,cnt = 0;

while(final_flag != 0){
    int temp = pixels2[i][j][k];

    if(temp < 10){
        binary[index++] = temp;
        
    }
    else if(temp == 10){
        binary[index++] = 0;
       
    }
    else{
        binary[index++] = temp % 10;
        
    }


    if(binary[index-1] == 1){
        cnt++;
    }
    else{
        cnt = 0;
    }
    if(cnt == 15){
        final_flag = 0;
    }


    k++;
    if(k ==3){
        k = 0;
        j++;
        if(j == inputFile->col){
        j = 0;
        i++;
    }
    }
    
}

//***********converting binary into text**************//
for(int i = 0;i<40;i++){
    cout<<binary[i]<<" ";
}
cout<<"After extraction :: ";
binaryToText(index-15,binary);

     
}

