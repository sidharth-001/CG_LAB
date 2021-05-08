#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main(){
    int gm, gd = DETECT;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    int x1, x2, x3, y1, y2, y3;
    printf("2D Transformation operation\nRotation\nEnter the points of triangle\n");
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);

    printf("Enter the angle of rotation:\n");
    int rq;
    scanf("%d", &rq);

    rq = 3.14 * rq / 180;
    int nx1, nx2, nx3, ny1, ny2, ny3;
    nx1 = abs(x1 * cos(rq) + y1 * sin(rq));
    ny1 = abs(x1 * sin(rq) + y1 * cos(rq));
    nx3 = abs(x3 * cos(rq) + y3 * sin(rq));
    ny2 = abs(x2 * sin(rq) + y2 * cos(rq));
    nx2 = abs(x2 * cos(rq) + y2 * sin(rq));
    ny3 = abs(x3 * sin(rq) + y3 * cos(rq));

    line(nx1, ny1, nx2, ny2);
    line(nx2, ny2, nx3, ny3);
    line(nx3, ny3, nx1, ny1);

    getch();
    closegraph();
    return 0;
}