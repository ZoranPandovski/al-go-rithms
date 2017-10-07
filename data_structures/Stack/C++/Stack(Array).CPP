#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
int a[50];
int c=0;
int top=-1,data;

while(c<3)
{
cout<<"1.Push\n2.Pop\n3.Exit\n";
cin>>c;
switch(c)
{
case 1:
top++;
if(top>49)
{
top--;
cout<<"Overflow\n";
}
else{
cout<<"Enter Data\n";
cin>>a[top];
cout<<"Item Inserted\n";
}
break;

case 2:
if(top==-1){
cout<<"Underflow\n";
}
else{
top--;
}
break;

}

if(top!=-1)
{
cout<<"Stack:\n";
for(int i=top;i>=0;i--)
{
cout<<"<-"<<a[i];
}
cout<<"\n";
}

}
}