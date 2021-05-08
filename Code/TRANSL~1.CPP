#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(){
    int gm, gd = DETECT;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    int x1, x2, x3, y1, y2, y3;
    printf("2D Transformation operation\nTranslation\nEnter the points of triangle\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    printf("Enter translation factor\n");
    int tx, ty;
    scanf("%d %d", &tx, &ty);

    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);

    int nx1, nx2, nx3, ny1, ny2, ny3;
    nx1 = x1 + tx;
    nx2 = x2 + tx;
    nx3 = x3 + tx;
    ny1 = y1 + ty;
    ny2 = y2 + ty;
    ny3 = y3 + ty;
    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    getch();
    closegraph();
    return 0;
}