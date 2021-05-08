#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y){
    putpixel(xCenter + x, yCenter + y, WHITE);
    putpixel(xCenter - x, yCenter + y, WHITE);
    putpixel(xCenter + x, yCenter - y, WHITE);
    putpixel(xCenter - x, yCenter - y, WHITE);
}

void midPointEllipse(int xCenter, int yCenter, int Rx, int Ry){
    int Rx2 = Rx * Rx;
    int Ry2 = Ry * Ry;
    int twoRx2 = 2 * Rx2;
    int twoRy2 = 2 * Ry2;
    int p, x = 0, y = Ry, px = 0;
    int py = twoRx2 * y;
    ellipsePlotPoints(xCenter, yCenter, x, y);
    p = Ry2 - (Rx2 * Ry) + (0.25 * Rx2);
    while(px < py){
        x++;
        px += twoRy2;
        if (p < 0)
            p += Ry2 + px;
        else{
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
    p = Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2;
    while(y > 0){
        y--;
        py -= twoRx2;
        if(p > 0)
            p += Rx2 - py;
        else{
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }
        ellipsePlotPoints(xCenter, yCenter, x, y);
    }
}

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
    while(x < y){
        x++;
        if(p < 0){
            p += 2 * x + 1;
        }else{
            y--;
            p += 2 * (x - y) + 1;
        }
        setpixel(xc, yc, x, y);
    }
}

int main(){

    int g_mode, g_driver = DETECT;
    initgraph(&g_driver, &g_mode, "C:\\TURBOC3\\BGI");

    //body
    midptcircle(300, 290, 90);

    //face
    midptcircle(300, 150, 50);

    //legs
    midPointEllipse(250, 390, 30, 18);
    midPointEllipse(350, 390, 30, 18);

    //hands
    midptcircle(205, 230, 26);
    midptcircle(395, 230, 26);

    //ears
    midPointEllipse(250, 100, 20, 26);
    midPointEllipse(250, 100, 15, 21);

    midPointEllipse(350, 100, 20, 26);
    midPointEllipse(350, 100, 15, 21);

    //eyes
    midptcircle(280, 135, 4);
    midptcircle(320, 135, 4);
    midPointEllipse(280, 135, 15, 8);
    midPointEllipse(320, 135, 15, 8);

    //mouth
    midPointEllipse(300, 158, 8, 5);
    midPointEllipse(300, 178, 16, 8);
    midPointEllipse(300, 172, 26, 20);

    getch();
    closegraph();
    return 0;
}