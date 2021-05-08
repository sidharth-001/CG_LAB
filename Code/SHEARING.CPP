#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void mul(int mat[3][3],int points[10][3],int n);
void shear(int points[10][3],int n);
void init(int points[10][3],int n);

int main(){
    int i,x,y;
    int points[10][3],n;
    clrscr();
    cout<<"2D Transformation operation\nShearing\nEnter the no. of points : ";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>x>>y;
        points[i][0]=x;
        points[i][1]=y;
        points[i][2]=1;
    }
    shear(points,n);
    getch();
    return 0;
}

void init(int points[10][3],int n){
    int gd=DETECT,gm,i;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
    setcolor(10);
    line(0,240,640,240);
    line(320,0,320,480);
    setcolor(3);
    for(i=0;i<n-1;i++){
        line(320+points[i][0],240-points[i][1],320+points[i+1][0],240-points[i+1][1]);
    }
    line(320+points[n-1][0],240-points[n-1][1],320+points[0][0],240-points[0][1]);
}

void mul(int mat[3][3],int points[10][3],int n){
    int i,j,k;
    int res[10][3];
    for(i=0;i<n;i++){
        for(j=0;j<3;j++){ 
            res[i][j]=0;
            for(k=0;k<3;k++){
                res[i][j] = res[i][j] + points[i][k]*mat[k][j];
            }
        }
    }
    setcolor(15);
    for(i=0;i<n-1;i++){
       line(320+res[i][0],240-res[i][1],320+res[i+1][0],240-res[i+1][1]);
    }
    line(320+res[n-1][0],240-res[n-1][1],320+res[0][0],240-res[0][1]);
}


void shear(int points[10][3],int n){
    int opt;
    int arr_shear[3][3];
    cout<<"\n1.X-shear\n2.Y-shear\nYour Choice: ";
    cin>>opt;
    switch(opt){
        case 1: 
            int xsh;   
            cout<<"\nEnter the x shear : ";
            cin>>xsh;
            arr_shear[0][0]=1;
            arr_shear[1][0]=xsh;
            arr_shear[2][0]=0;
            arr_shear[0][1]=0;
            arr_shear[1][1]=1;
            arr_shear[2][1]=0;
            arr_shear[0][2]=0;
            arr_shear[1][2]=0;
            arr_shear[2][2]=1;
            init(points,n);
            mul(arr_shear,points,n);
        break;
	    case 2:
            int ysh;   
            cout<<"\nEnter the y shear : ";
            cin>>ysh;
            arr_shear[0][0]=1;
            arr_shear[1][0]=0;
            arr_shear[2][0]=0;
            arr_shear[0][1]=ysh;
            arr_shear[1][1]=1;
            arr_shear[2][1]=0;
            arr_shear[0][2]=0;
            arr_shear[1][2]=0;
            arr_shear[2][2]=1;
            init(points,n);
            mul(arr_shear,points,n);
	    break;
    }
}