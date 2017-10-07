#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
struct node
{
int info;
node *next;
}*top,*save,*ptr;

int c=0,data;
top=NULL;

while(c<3)
{
cout<<"1.Push\n2.Pop\n3.Exit\n";
cin>>c;

switch(c)
{
case 1:
cout<<"Enter Data\n";
cin>>data;
ptr =new node;
ptr->info=data;
ptr->next=NULL;

if(top==NULL)
{
top=ptr;
cout<<"Item Inserted\n";
}

else
{
save=top;
top=ptr;
top->next=save;
cout<<"Item Inserted\n";
}

break;

case 2:
if(top==NULL)
{
cout<<"Underflow\n";
}

else
{
ptr=top;
top=top->next;
delete ptr;
cout<<"Item Deleted\n";
}
break;
}

if(top!=NULL)
{
cout<<"Stack:\n";
ptr=top;
while(ptr!=NULL)
{
cout<<"<-"<<ptr->info;
ptr=ptr->next;
}
cout<<"\n";
}

}

}