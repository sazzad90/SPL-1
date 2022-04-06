#include "header.h"
#include <graphics.h>
using namespace std;

void drawWindow(){
    /*int gd=DETECT ,gm;
    initgraph(&gd,&gm,(char*)"");
  //  circle(320,240,200);
    getch();
    closegraph();*/

    DWORD width = GetSystemMetrics(SM_CXSCREEN);
    DWORD height = GetSystemMetrics(SM_CYSCREEN);
    int click[2];
    int x,y;

    initwindow(800, 600, "");

    setcolor(LIGHTGRAY);
    rectangle(200,200,300,250);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(201,201, LIGHTGRAY);

    setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(3,4, 3);
    outtextxy(280, 240, "Encode");
    

    setcolor(LIGHTGRAY);
    rectangle(200,300,300,350);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(201,301, LIGHTGRAY);

     setcolor(BLACK);
    setbkcolor(LIGHTGRAY);
    settextstyle(3,4, 3);
    outtextxy(280, 340, "Decode");

    while(1){
      getMouseClick(click);
      x = click[1];
      y = click[0];
      if((x >=200 && x <= 300) && (y >= 200 && y <= 250)){
          hideData("x.bmp", "test.txt");
      }
      else if((x >=200 && x <= 300) && (y >= 300  && y <= 350)){
        extract("stego.bmp");
      }
    }
    
}
