#include<constrea.h>
#include<math.h>
#include<graphics.h>
void main()
{
clrscr();
int graphdriver=DETECT,graphmode;
initgraph(&graphdriver,&graphmode,"C:\\TC\\BGI");
int x1,x2,y1,y2,dx,dy,steps;
cout<<"Enter x1 and y1\n";
cin>>x1>>y1;
cout<<"Enter x2 and y2\n";
cin>>x2>>y2;
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
{
steps=dx;
}
else
steps=dy;
float x=x1,y=y1;
for(int i=0;i<steps;i++)
{putpixel(x,y,GREEN);
 x=x+(dx/steps);
 y=y+(dy/steps);
}
getch();
closegraph();
}