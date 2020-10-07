#include<bits/stdc++.h>
#include<graphics.h>
#define ll long long int
#define ld long double
using namespace std;

int main()
{
    int gd = DETECT, gm, tmp = 0;

    ld dx, dy, d1, d2, x = 0, y, rx, ry, xc, yc;
    cin >> rx >> ry >> xc >> yc;
    y = ry;

    //declare all variables before it
    initgraph(&gd,&gm, NULL);
    //draw here


    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
      putpixel(100 + x + xc, 100 + y + yc, 15);
      putpixel(100 - x + xc, 100 + y + yc, 15);
      putpixel(100 + x + xc, 100 - y + yc, 15);
      putpixel(100 - x + xc, 100 - y + yc, 15);


      if (d1 < 0)
      {
        x++;
        dx = dx + (2 * ry * ry);
        d1 = d1 + dx + (ry * ry);
      }
      else
      {
        x++;
        y--;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        d1 = d1 + dx - dy + (ry * ry);
      }
      delay(300);
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +  ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {

      putpixel(100 + x + xc, 100 + y + yc, 15);
      putpixel(100 - x + xc, 100 + y + yc, 15);
      putpixel(100 + x + xc, 100 - y + yc, 15);
      putpixel(100 - x + xc, 100 - y + yc, 15);

      if (d2 > 0)
      {
          y--;
          dy = dy - (2 * rx * rx);
          d2 = d2 + (rx * rx) - dy;
      }
      else
      {
          y--;
          x++;
          dx = dx + (2 * ry * ry);
          dy = dy - (2 * rx * rx);
          d2 = d2 + dx - dy + (rx * rx);
      }
      delay(300);
    }

    //draw ends
    getche();
    closegraph();
    return 0;
}
