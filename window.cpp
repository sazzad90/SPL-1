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

    initwindow(width, height, "");

    setcolor(LIGHTGRAY);
    rectangle(200,200,300,250);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(201,201, LIGHTGRAY);

    setcolor(LIGHTGRAY);
    rectangle(300,200,400,250);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(301,201, LIGHTGRAY);

    while(1){
      getMouseClick(click);
      x = click[1];
      y = click[0];
      if((x >=200 && x <= 300) && (y >= 200 && y <= 250)){
          hideData("x.bmp", "test.txt");
      }
      else if((x >=300 && x <= 400) && (y >= 200 && y <= 250)){
        extract("stego.bmp");
      }
      getch();
    }
}
