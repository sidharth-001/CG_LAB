#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>

void fill_right(int x, int y);
void fill_left(int x, int y);

int main(){
    int n, i, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    line(50, 50, 200, 50);
    line(200, 50, 200, 300);
    line(200, 300, 50, 300);
    line(50, 300, 50, 50);

    x = 100;
    y = 100;
    fill_right(x, y);
    fill_left(x - 1, y);
    getch();
    return 0;
}

void fill_right(int x, int y){
    if((getpixel(x, y) != WHITE) && (getpixel(x, y) != RED)){
        putpixel(x, y, RED);
        fill_right(++x, y);
        x = x - 1;
            fill_right(x, y - 1);
            fill_right(x, y + 1);
    }
    delay(0);
}

void fill_left(int x, int y){
    if((getpixel(x, y) != WHITE) && (getpixel(x, y) != RED)){
        putpixel(x, y, RED);
        fill_left(--x, y);
        x = x + 1;
            fill_left(x, y - 1);
            fill_left(x, y + 1);
    }
    delay(0);
}