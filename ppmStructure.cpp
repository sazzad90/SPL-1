#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "header.h"



using namespace std;

//int pixels[1000][1000][3] = {0};

typedef struct {
	int R, G, B;
} pixel;


typedef struct {
	int row, col, colorDepth;
	pixel *body; /*array of pixels*/
} ppmFile;


ppmFile* readPPMImage(const char *imageFile, int*** pixels)
{
	//declaring variables 
	char imageFormat[4];
	FILE *fp; //file pointer for the inputFile 

	//allocating dynamic memory for Image File
	ppmFile* imagePtr = (ppmFile*)malloc(sizeof(ppmFile));
	if (!imagePtr) {
		printf("Error: Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

	//opening ppm file in read-binary mode
	fp = fopen(imageFile, "r");
	if(!fp){
		  cout<<endl;
        cout<<"Image file is not found in the directory."<<endl;
		 cout<<"Data hiding cannot be done."<<endl;
		   cout<<endl;
        return nullptr;
    }
	if (!fp) //if the file failed to opened  
	{
		printf("Error: File opening failed!\n");
		exit(EXIT_FAILURE);
	}

	//reading and checking the format of the image
	fgets(imageFormat, sizeof(imageFormat), fp);

	if (imageFormat[0] != 'P' || imageFormat[1] != '3') {
		printf("Error: Image format should be P3!\n");
		exit(EXIT_FAILURE);
	}

	//reading the size of the image and maximum color
	fscanf(fp, "   %d %d   ", &imagePtr->col, &imagePtr->row);
	fscanf(fp, "  %d  ", &imagePtr->colorDepth);
	
	//allocating dynamic memory for pixel data 
	imagePtr->body = (pixel*)malloc(imagePtr->row * imagePtr->col * sizeof(pixel));
	if (!imagePtr) {
		printf("Error: Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}

int x,y,z;
	//reading pixel body of the image
	int r = 0,c = 0;
	for (int i = 0; i < imagePtr->row; i++){
		for(int j = 0;j< imagePtr->col;j++){
		fscanf(fp, "    %d %d %d    ", &imagePtr->body[c].R,&imagePtr->body[c].G,&imagePtr->body[c].B);//&(imagePtr->body[c].R), &(imagePtr->body[c].G), &(imagePtr->body[c].B));
		
		pixels[i][j][0] =  imagePtr->body[c].R;
		pixels[i][j][1] =  imagePtr->body[c].G;
		pixels[i][j][2] =  imagePtr->body[c].B;
		c++;
		
		}
	}
	

	fclose(fp); 
	return imagePtr; 
}


void writeImage(const char *imageName, ppmFile *imageFile)
{
	FILE *fp; 

	fp = fopen(imageName, "w");
	if (!fp) //if file creation fails 
	{
		printf("Error: Could not create the file!\n");
		exit(EXIT_FAILURE);
	}

	//writing image header
	fprintf(fp, "P3"); /*Magic Number*/
	fprintf(fp, "   %d %d   ", imageFile->col, imageFile->row);  /*columns and rows*/
	fprintf(fp, "  %d  ", imageFile->colorDepth); /*Maximum color depth*/

												  //writing image body
	for (int i = 0; i < (imageFile->row * imageFile->col); i++)
		fprintf(fp, "    %d %d %d    ", imageFile->body[i].R, imageFile->body[i].G, imageFile->body[i].B);

	fclose(fp); /*closing the created file*/
}

