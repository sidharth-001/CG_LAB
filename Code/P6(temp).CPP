
#include<stdio.h>
#include<graphics.h>
#include "clipping.h"


double dotProduct(Point p1, Point p2)
{
    return p1.x*p2.x + p1.y*p2.y;
}
//z is a point on polygon other than on line l
/*
had a lot of trouble in this method - see this carefully
*/
Point getInsideNormal(Line l, Point z)
{
    double delX = l.p2.x - l.p1.x;
    double delY = l.p2.y - l.p1.y;
    Point n = {-delY, delX};
    Point v = {z.x-l.p1.x, z.y-l.p1.y};
    double dot = dotProduct(v,n);
    if(dot==0)
    {
        printf("Error - 3 collinear points along polygon\n");
        delay(2000);
        exit(0);
    }
    if(dot < 0) //outside normal
    {
        n.x*=-1;
        n.y*=-1;
    }
    return n;
}

/*
only for convex polygon
*/
void cyrusBeck(Poly *poly, Line *ll, int color)
{
    Line l = *ll;
    int delX = l.p2.x - l.p1.x;
    int delY = l.p2.y - l.p1.y;
    //vector D = Direction vector
    Point D = {delX, delY};

    //iterate over edges of polygon
    Point boundaryPoint = poly->next->next->p;
    double tEnter = 0;
    double tLeave = 1;
    while(1)
    {
        if(poly->next == NULL) //no more edges
        {
            break;
        }
        Point p = poly->p;
        p.print();
        poly = poly->next;
        Point q = poly->p;
        Line line = Line{p,q};
        Point n = getInsideNormal(line, boundaryPoint);
        //f = p1
        Point w = {l.p1.x-p.x, l.p1.y - p.y};
        double num = dotProduct(w, n);
        double den = dotProduct(D, n);
        if(den == 0) //line and edge are parallel
        {
            if(num < 0) //w.n<0  -> point/line outside coz P(t) outside polygon
            {
                return;
            }
            else
            {
                continue;
            }
        }

        double t = -num/den;
        if(den > 0) //outside to inside case
        {
            tEnter = Max(tEnter, t);
        }
        else //den < 0, inside to outside case
        {
            tLeave = Min(tLeave, t);
        }
        boundaryPoint = p;
    }
    if(tEnter > tLeave)
    {
        return;
    }
    double x1 = l.p1.x + delX * tEnter;
    double y1 = l.p1.y + delY * tEnter;
    double x2 = l.p1.x + delX * tLeave;
    double y2 = l.p1.y + delY * tLeave;
    Line lClip = {Point{x1,y1}, Point{x2,y2}};
    lClip.plotLineDDA(color);
}



/*
-30 70
60 100
80 -10
20 -20
-80 0
-30 70
Enter line
-150 100
150 20
-30 70
60 100
80 -10
20 -20
-80 0
-30 70
Enter line
*/
int main()
{
	int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    setbkcolor(WHITE);
    cleardevice();
    drawAxis(BLACK);
    int n;
    Poly *poly = NULL;
    printf("Enter n for convex polygon\n");
    scanf("%d", &n);
    printf("Enter points in clockwise/anticlockwise order\n");
    for(int i = 0; i<n; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        Point p = Point{x,y};
        Poly *newPoly = (Poly *)malloc(sizeof(Poly));
        *newPoly = Poly{p, poly};
        poly = newPoly;
    }
    poly->plotPoly(BLACK, 0);
    printf("Enter line\n");
    Line l;
    scanf("%lf%lf%lf%lf", &l.p1.x, &l.p1.y, &l.p2.x, &l.p2.y);
    l.plotLineDDA(BLUE);
    cyrusBeck(poly, &l, YELLOW);
    getch();
    closegraph();
    return 0;

}