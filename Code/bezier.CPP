#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

void main(){
    int x[4], y[4], i;
    double put_x, put_y, t;

    int gr = DETECT, gm;
    initgraph(&gr, &gm, "C:\\TURBOC3\\BGI");
    printf("\nBezier Curve");
    printf("\nEnter x and y coordinates of control points:\n");
    for (i = 0; i < 4; i++){
        printf("%d point: ", i+1);
        scanf("%d%d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3);
    }

    for(t=0.0; t<=1.0; t += 0.001){
        put_x = pow(1-t, 3)*x[0] + 3*t*pow(1-t,2)*x[1] + 3*t*t*(1-t)*x[2] + pow(t,3)*x[3];
        put_y = pow(1-t,3)*y[0] + 3*t*pow(1-t,2)*y[1] + 3*t*t*(1-t)*y[2] + pow(t,3)*y[3];
        putpixel(put_x, put_y, GREEN);
    }
    getch();
    closegraph();
}