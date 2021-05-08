#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int abs(int n){
    return ((n>0) ? n : ( n *(-1)));
}

void DDA(int X0, int Y0, int X1, int Y1){
    
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
    
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
    
    float x_inc = dx / (float) steps; 
    float y_inc = dy / (float) steps; 
    
    float X = X0; 
    float Y = Y0; 
    for(int i = 0; i <= steps; i++){
	    putpixel (X,Y,WHITE);
        X += x_inc;
        Y += y_inc;
    } 
} 

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

        DDA(150,300,250,300);
        DDA(150,180,250,180);
        DDA(150,300,150,180);
        DDA(250,300,250,180);

        DDA(180,300,220,300);
        DDA(180,250,220,250);
        DDA(180,300,180,250);
        DDA(220,300,220,250);

        DDA(160,230,190,230);
        DDA(160,200,190,200);
        DDA(160,230,160,200);
        DDA(190,230,190,200);

        DDA(210,230,240,230);
        DDA(210,200,240,200);
        DDA(210,230,210,200);
        DDA(240,230,240,200);

        DDA(200,100,150,180);
        DDA(200,100,250,180);

    getch();
    closegraph();
    return 0;
}