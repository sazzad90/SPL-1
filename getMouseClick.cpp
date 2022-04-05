#include "header.h"
#include <graphics.h>
void getMouseClick(int click[]){
    click[0] = {-1};
    click[1] = {-1};

    POINT cursor;

    while(1){
        if(GetAsyncKeyState(VK_LBUTTON)){
            GetCursorPos(&cursor);
            if(cursor.y != click[0] && cursor.x != click[1]){
                click[0] = cursor.y;
                click[1] = cursor.x;
                break;
            }
        }
    }
 }