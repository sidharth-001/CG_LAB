#include <iostream.h>
#include <conio.h>
#include <graphics.h>

int round(int a){
	return ((int)(a+0.5));
}

float xmin, ymin, xmax, ymax, arr[20], m; int k;
void left_clip(float x1, float y1, float x2, float y2){
	if (x2 - x1)
		m = (y2 - y1) / (x2 - x1);
	else
		m = 100000;
	if(x1 >= xmin && x2 >= xmin){
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if(x1 < xmin && x2 >= xmin){
		arr[k] = xmin;
		arr[k + 1] = y1 + m * (xmin - x1);
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if(x1 >= xmin && x2 < xmin){
		arr[k] = xmin;
		arr[k + 1] = y1 + m * (xmin - x1);
		k += 2;
	}
}

void top_clip(float x1, float y1, float x2, float y2){
	if (y2 - y1)
		m = (x2 - x1) / (y2 - y1);
	else
		m = 100000;
	if (y1 <= ymax && y2 <= ymax){
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if (y1 > ymax && y2 <= ymax){
		arr[k] = x1 + m * (ymax - y1);
		arr[k + 1] = ymax;
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if (y1 <= ymax && y2 > ymax){
		arr[k] = x1 + m * (ymax - y1);
		arr[k + 1] = ymax;
		k += 2;
	}
}

void right_clip(float x1, float y1, float x2, float y2){
	if(x2 - x1)
		m = (y2 - y1) / (x2 - x1);
	else
		m = 100000;
	if(x1 <= xmax && x2 <= xmax){
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if(x1 > xmax && x2 <= xmax){
		arr[k] = xmax;
		arr[k + 1] = y1 + m * (xmax - x1);
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if(x1 <= xmax && x2 > xmax){
		arr[k] = xmax;
		arr[k + 1] = y1 + m * (xmax - x1);
		k += 2;
	}
}

void bottom_clip(float x1, float y1, float x2, float y2){
	if(y2 - y1)
		m = (x2 - x1) / (y2 - y1);
	else
		m = 100000;
	if(y1 >= ymin && y2 >= ymin){
		arr[k] = x2;
		arr[k + 1] = y2;
		k += 2;
	}
	if(y1 < ymin && y2 >= ymin){
		arr[k] = x1 + m * (ymin - y1);
		arr[k + 1] = ymin;
		arr[k + 2] = x2;
		arr[k + 3] = y2;
		k += 4;
	}
	if(y1 >= ymin && y2 < ymin){
		arr[k] = x1 + m * (ymin - y1);
		arr[k + 1] = ymin;
		k += 2;
	}
}

void main(){

	int g_driver = DETECT, g_mode;
	initgraph(&g_driver, &g_mode, "C:\\TURBOC3\\BGI");

	float xi, yi, xf, yf, polyy[20];
	int n, poly[20];
	//clrscr();
	cout<<"Coordinates of clipping region:";
	cin>>xmin>>xmax;
	cin>>ymin>>ymax;
	cout<<"\nNumber of sides polygon (to be clipped):";
	cin>>n;
	cout<<"Enter the coordinates: ";
	for(int i = 0; i < 2 * n; i++)
		cin>>polyy[i];
	polyy[i] = polyy[0];
	polyy[i + 1] = polyy[1];
	for (i = 0; i < 2 * n + 2; i++)
		poly[i] = round(polyy[i]);
	setcolor(GREEN);
	rectangle(xmin, ymax, xmax, ymin);
	cout<<"\t\tUNCLIPPED POLYGON";
	setcolor(WHITE);
	fillpoly(n, poly);
	getch();
	cleardevice();
	k = 0;
	for(i=0; i<2*n; i+=2)
		left_clip(polyy[i], polyy[i+ 1], polyy[i + 2], polyy[i + 3]);
	n = k / 2;
	for(i=0; i<k; i++)
		polyy[i] = arr[i];
	polyy[i] = polyy[0];
	polyy[i+1] = polyy[1];
	k=0;
	for(i=0; i<2*n; i+=2)
		top_clip(polyy[i], polyy[i+1], polyy[i+2], polyy[i+3]);
	n=k/2;
	for(i=0; i<k; i++)
		polyy[i] = arr[i];
	polyy[i] = polyy[0];
	polyy[i+1] = polyy[1];
	k=0;
	for(i=0;i<2*n;i+=2)
		right_clip(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
	n=k/2;
	for(i=0;i<k;i++)
		polyy[i]=arr[i];
	polyy[i]=polyy[0];
	polyy[i+1]=polyy[1];
	k = 0;
	for(i=0; i<2*n; i+=2)
		bottom_clip(polyy[i], polyy[i+1], polyy[i+2], polyy[i+3]);
	for(i=0; i<k; i++)
		poly[i]=round(arr[i]);
	if(k)
		fillpoly(k/2,poly);
	setcolor(GREEN);
	rectangle(xmin, ymax, xmax, ymin);
	cout<<"CLIPPED POLYGON";
	getch();
	closegraph();
}