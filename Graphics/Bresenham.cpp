#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;

    dx=x1-x0;
    dy=y1-y0;

    x=x0;
    y=y0;

    p=2*dy-dx;

    while(x<x1)
    {
	if(p>=0)
	{
	    putpixel(x,y,YELLOW);
	    y=y+1;
	    p=p+2*dy-2*dx;
	    delay(5);
	}
	else
	{
	    putpixel(x,y,YELLOW	);
	    p=p+2*dy;
	    delay(5);
	}
	x=x+1;
    }
}

void main()
{
    int gdriver=DETECT,gm;
    int error, x0, y0, x1, y1;
    initgraph(&gdriver, &gm, "C:\\TC\\BGI");

    cout<<"Enter co-ordinates of first point: ";
    cin>>x0>>y0;

    cout<<"Enter co-ordinates of second point: ";
    cin>>x1>>y1;
    outtextxy(200,150,"Bresenham 's Algorithm");
    drawline(x0, y0, x1, y1);
    getch();
    closegraph();
}