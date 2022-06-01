#include "header.h"

using namespace std;

int main ()
{
    int imageFormat;
     
    cout<<endl;
    cout<<"IMAGE STEGANOGRAPHY"<<endl;
    string choice3;
    string choice1, choice2;
    //choice3[0] = '1';

while(1){
    
    cout<<"Our features::\n1.HIDE    2.EXTRACT"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice1;
    char  imageFileName[20];
   char textFileName[20];

    if(choice1.length() == 1){
    if(choice1[0] == '1'){
           
          cout<<"Provide text file name: ";
          cin>>textFileName;
          cout<<"Provide image file name: ";
          cin>>imageFileName;
    imageFormat = hideData(imageFileName, textFileName);
    cout<<imageFormat;//

    if(imageFormat != 4){
    cout<<"Data hiding is done"<<endl;
    cout<<endl;
    cout<<"Do you want to extract data now?\nIf yes,press 1...If no,press 2:: ";
    cin>>choice2;
    cout<<endl;
    }
    }

   else if(choice1[0] == '2'){
          cout << "Provide image file name: ";
          cin>>imageFileName;
      
         int length = strlen(imageFileName);
          char subName[3];
          for(int i = 3;i>=0;i--){
                subName[i] = imageFileName[length--];
          }
          
    if(!strcmp(subName, "bmp")){
          imageFormat = 0;
          extract(imageFileName, imageFormat );
          } 
    else if(!strcmp(subName, "ppm")){
          imageFormat = 1;
          extract(imageFileName, imageFormat);
          }
    else{
          cout<<"Stego image isn't supported for extraction."<<endl;
          }
    }
    }

    else{
          cout<<"Invalid input"<<endl;
    }



    if(choice2.length() == 1){

    if(choice2[0] == '1'){
          //
          
         cout<<"Provide image file name: ";
          cin>>imageFileName;
           if(imageFormat == 0){
          extract(imageFileName, imageFormat);
          cout<<"Data extraction is done."<<endl;
          } 
          else if(imageFormat == 1){
          extract(imageFileName, imageFormat);
          cout<<"Data extraction is done."<<endl;
          }
          else{
          cout<<"Message is too large for hiding."<<endl;
          }
    }

   else if(choice2[0] == '2'){
         cout<<"Program is closed."<<endl;
   }

   else{
         cout<<"Wrong keyword"<<endl;
   }

 /*  cout<<"Enter 1 to continue again...Enter any other key to terminate the program: ";
   cin>>choice3;
   cout<<endl;
   cout<<endl;
*/
   
}


       cout<<"Enter 1 to continue again...Enter any other key to terminate the program: ";
       cin>>choice3;
       cout<<endl;
       if(choice3[0] != '1'){
             break; 
       }
}

cout<<"THANK YOU"<<endl;
   return 0;
} 