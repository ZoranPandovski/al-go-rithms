#include<stdio.h>
void TOH(int n,char x,char y,char z);
void main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}
void TOH(int n,char a,char b,char c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("\n%c -> %c",a,c);
        TOH(n-1,b,a,c);
    }
}