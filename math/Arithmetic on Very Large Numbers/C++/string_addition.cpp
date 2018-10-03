#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

void main()
{
 clrscr();	
char ch[100],ch1[100];
	cout<<"\n Enter string 1: ";
	gets(ch);
	cout<<"\n Enter String 2: ";
	gets(ch1);
	cout<<"\n Merged string is: "<<strcat(ch,ch1);	
getch();	
}
