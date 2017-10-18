// AUTHOR:      Mitchell Haugen
// GITHUB:      https://github.com/haugenmitch
// DATE:        October 9, 2017
// DESCRIPTION: This C++ program implements the factorial operation in a space efficient, non-recursive manner

// TEST VALUES:
// 0!  = 1
// 1!  = 1
// 2!  = 2
// 3!  = 6
// 5!  = 120
// 10! = 3,628,800
// 20! = 2,432,902,008,176,640,000

#include <iostream.h>
#include<conio.h>
void main();
clrscr();
int fact=1,num,k;
cout<<"\n\t Enter a number:";
cin>>num;
k=num;
while(num>0)
{
	fact=fact*num;
	--num;
}
cout<<"\n\t factorial of "<<k<<" is:"<<fact;
getch();
}
