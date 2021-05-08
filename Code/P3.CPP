#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void setpixel(int xc, int yc, int x, int y){
    putpixel(xc + x, yc + y, 15);
    putpixel(xc + x, yc - y, 15);
    putpixel(xc - x, yc + y, 15);
    putpixel(xc - x, yc - y, 15);
    putpixel(xc + y, yc + x, 15);
    putpixel(xc + y, yc - x, 15);
    putpixel(xc - y, yc + x, 15);
    putpixel(xc - y, yc - x, 15);
}

void midptcircle(int xc, int yc, int r){
    
    int p = 1 - r;
    int x = 0, y = r;
    setpixel(xc, yc, x, y);
    while(x<y){
        x++;
        if(p<0){
            p += 2 * x + 1;
        }else{
            y--; p += 2 * (x - y) + 1;
        }
        setpixel(xc, yc, x, y);
    }
}

int main(){
    
    int g_mode,g_driver=DETECT;
    initgraph(&g_driver,&g_mode,"C:\\TURBOC3\\BGI");

    //body
    midptcircle(300, 290, 90);
    
    //face
    midptcircle(300, 150, 50);
    
    //legs
    midptcircle(250, 380, 28);
    midptcircle(350, 380, 28);
    
    //hands
    midptcircle(210, 230, 30);
    midptcircle(390, 230, 30);
    
    //ears
    midptcircle(250, 100, 20);
    midptcircle(250, 100, 15);
    midptcircle(350, 100, 20);
    midptcircle(350, 100, 15);
    
    //eyes
    midptcircle(280, 140, 6);
    midptcircle(280, 140, 3);
    midptcircle(320, 140, 6);
    midptcircle(320, 140, 3);
    
    //mouth
    midptcircle(300, 172, 20);
    midptcircle(300, 156, 4);
    midptcircle(300, 177, 10);
    
    getch();
    closegraph();
    return 0;
}