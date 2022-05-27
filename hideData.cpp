#include "header.h"
#include <bits/stdc++.h>

using namespace std;

//int pixels[1000][1000][3]={0};

void hideData(const char *imageFile, const char *textFile){
int*** pixels = new int** [3000];
    for(int i = 0;i<3000;i++){
        pixels[i] = new int* [3000]; 
        for(int j = 0;j<3000;j++){
            pixels[i][j] = new int[3];
        }
    }

//**********  reading text file into binary  **********// 
    int binaryLength=0;
    int binary[100000]={};
    binaryLength = textToBinary(textFile, binary, binaryLength);

    for(int i = 0;i<binaryLength;i++){
        cout<<binary[i]<<" ";
    }
    cout<<endl;
    string fileName = imageFile;
    std :: cout<<fileName<<endl;
    int pos = fileName.find(".");
    string subName = fileName.substr(pos+1);
    std :: cout<<subName;



    if(!subName.compare("bmp")){

//**********  reading image file into binary  **********// 

    bmpSignature signature;
    bmpFileHeader fileHeader;
    bmpInfoHeader infoHeader;
    bmpColorHeader colorHeader;
    bmpColorTable colorTable;

     ifstream inputFile;
     ofstream outputFile;

    inputFile.open(imageFile, ios:: binary);
    outputFile.open("stego.bmp", ios :: binary);

    if(inputFile.eof()) throw runtime_error("File not found");
    inputFile.seekg(0,ios::beg);
    outputFile.seekp(0,ios::beg);

    inputFile.read((char*)&signature,sizeof(signature));
    inputFile.read((char*)&fileHeader,sizeof(fileHeader));
    inputFile.read((char*)&infoHeader,sizeof(infoHeader));
    inputFile.read((char*)&colorHeader,sizeof(colorHeader));

    outputFile.write((char*)&signature,sizeof(signature));
    outputFile.write((char*)&fileHeader,sizeof(fileHeader));
    outputFile.write((char*)&infoHeader,sizeof(infoHeader));
    outputFile.write((char*)&colorHeader,sizeof(colorHeader));

    int width=infoHeader.width;
    int height= infoHeader.height;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            inputFile.read(reinterpret_cast<char*>(color),3);
            pixels[i][j][0] = static_cast<float>(color[2]); //red
            pixels[i][j][1] = static_cast<float>(color[1]); //green
            pixels[i][j][2] = static_cast<float>(color[0]); //blue
        }
    }

//**********  converting decimal pixels into binary  **********// 
    decimalToBinary(pixels,width,height);
   
//**********  hiding text into image  **********// 
     int index = 0;
     int i = 0, j = 0, c = 0;

     while(index <= binaryLength){
        if(c==3){
        c = 0;
        j++;
        if(j == infoHeader.width){
            j = 0;
            i++;
        }
        }

        int temp = pixels[i][j][c];
        int divisor = 10000000;
      /*  for(int k = 0; k < 7; k++){
            temp = temp%divisor;
            divisor = divisor/10;
        }
        */
       temp = temp % 10;

     //   cout<<binary[index]<<" "<<temp<<endl;     modifying data

        if(temp == binary[index]){

        }

        else{
            if(temp == 1){
                pixels[i][j][c] = pixels[i][j][c] - 1;
            }
            else{
                pixels[i][j][c] = pixels[i][j][c] + 1;
            }
        }

    //    cout<<pixels[i][j][c]<<endl;         modified pixel
        c++;
        index++;
     }
    
    //**********  converting binary pixels into decimal  **********// 
     binaryToDecimal(pixels, infoHeader.width, infoHeader.height);

    //**********  writing image  **********// 

        for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            unsigned char color[3];
            color[0] = static_cast<unsigned char>(pixels[i][j][2]); 
            color[1] = static_cast<unsigned char>(pixels[i][j][1]);
            color[2] = static_cast<unsigned char>(pixels[i][j][0]);
            outputFile.write(reinterpret_cast<char*>(color),3);
        }
        //inputFile.ignore(paddingAmount);
    }    

    inputFile.read((char*)&colorTable,sizeof(colorTable));
    outputFile.write((char*)&colorTable,sizeof(colorTable));

    inputFile.close();
    outputFile.close();

    std :: cout<<"Stego image is created."<<endl;
    std :: cout<<endl;
    }

    else if(!subName.compare("ppm")){
      
    ppmFile* inputFile;
    inputFile = readPPMImage(imageFile, pixels);


    decimalToBinary(pixels,inputFile->col,inputFile->row);

  
        //**********  hiding text into image  **********// 
     int index = 0;
     int i = 0, j = 0, c = 0;

     while(index <= binaryLength){
        if(c==3){
        c = 0;
        j++;
        if(j == inputFile->col){
            j = 0;
            i++;
        }
        }

        int temp = pixels[i][j][c];
        int divisor = 10000000;
      /*  for(int k = 0; k < 7; k++){
            temp = temp%divisor;
            divisor = divisor/10;
        }
        */
       temp = temp % 10;

     //   cout<<binary[index]<<" "<<temp<<endl;     modifying data

        if(temp == binary[index]){

        }

        else{
            if(temp == 1){
                pixels[i][j][c] = pixels[i][j][c] - 1;
            }
            else{
                pixels[i][j][c] = pixels[i][j][c] + 1;
            }
        }
       // cout<<pixels[i][j][c]<<endl;
        c++;
        index++;
     }

    cout<<"before writing: "<<endl;
        for(int j = 0;j<20;j++){
            cout<<pixels[0][j][0]<<" "<<pixels[0][j][1]<<" "<<pixels[0][j][2]<<"   ";
        }
    cout<<endl;
    
    
    //**********  converting binary pixels into decimal  **********// 
     binaryToDecimal(pixels, inputFile->col, inputFile->row);
    
    for(int i = 0;i<4;i++){
cout<<pixels[0][i][0]<< " "<<pixels[0][i][1]<<" "<<pixels[0][i][2]<<"   ";
	}
	cout<<endl;


    FILE *outputFile;    

	outputFile = fopen("stego.ppm", "w");
	if (!outputFile) //if file creation fails 
	{
		printf("Error: Could not create the file!\n");
		exit(EXIT_FAILURE);
	}

	//writing image header
	fprintf(outputFile, "P3"); /*Magic Number*/
	fprintf(outputFile, "   %d %d   ", inputFile->col, inputFile->row);  /*columns and rows*/
	fprintf(outputFile, "  %d  ", inputFile->colorDepth); /*Maximum color depth*/

//
int rkb =0;

//
												  //writing image body

    for (int i = 0; i < inputFile->row; i++){
		for(int j = 0;j< inputFile->col;j++){
            fprintf(outputFile, "    %d %d %d    ", pixels[i][j][0], pixels[i][j][1], pixels[i][j][2]);
        }}

        /*

	for (int i = 0; i < (inputFile->row * inputFile->col); i++){
        if(rkb<20)
        {
         		cout<<inputFile->body[i].R<< " "<<inputFile->body[i].G<<" "<< inputFile->body[i].B;
rkb++;
        }
		fprintf(outputFile, "    %d %d %d    ", inputFile->body[i].R, inputFile->body[i].G, inputFile->body[i].B);
    }
    */
    
     	fclose(outputFile); /*closing the created file*/
    }



    else{
        std :: cout<<"Image file format is not recognized..."<<endl;  
    }


}

