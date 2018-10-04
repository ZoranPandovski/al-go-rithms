//a turbo c++ program for armstrong
#include<iostream.h>
#include<conio.h>
void main()
{
	texbackground(10);
	textcolor(0);
	clrscr();
	int arm=0,num,r;
	cout<<"\n\t Enter a number:";
	cin>>num;
	while(num>0)
	{
		r=num%10;
		arm=arm+r*r*r;
		num=num/10;
	}
	if(num==arm)
		cout<<"\n\t armstrong number";
	else
		cout<<"\n\t not an armstrong number";
	getch();
}
