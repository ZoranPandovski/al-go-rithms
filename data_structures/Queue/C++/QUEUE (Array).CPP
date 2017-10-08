#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
int a[50];
int c=0;
int front=-1,rear=-1,data;

while(c<3)
{
cout<<"1.Insertion\n2.Deletion\n3.Exit\n";
cin>>c;
switch(c)
{
case 1:
if(rear>49)
{
cout<<"Overflow\n";
}

else
{
if(front==-1)
{
front++;
}

rear++;
cout<<"Enter Data\n";
cin>>a[rear];
cout<<"Item Inserted\n";
}
break;

case 2:
if(front==rear && front!=-1)
{
front=rear=-1;
cout<<"Item Deleted\n";
}

else if(rear==-1)
{
cout<<"Underflow\n";
}

else
{
front++;
cout<<"Item Deleted\n";
}
break;

}

if(front!=-1)
{
cout<<"Queue:\n";
for(int i=front;i<=rear;i++)
{
cout<<a[i]<<"<-";
}
cout<<"\n";
}

}

}