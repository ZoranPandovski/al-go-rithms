#include<iostream.h>
#include<conio.h>

void main()
{clrscr();
struct node
{
int info;
node *next;
}*front,*ptr,*rear;

int c=0,data;
front=rear=NULL;

while(c<3)
{
cout<<"1.Insertion\n2.Deletion\n3.Exit\n";
cin>>c;

switch(c)
{
case 1:
cout<<"Enter Data\n";
cin>>data;

ptr =new node;
ptr->info=data;
ptr->next=NULL;

if(front==NULL)
{
front=rear=ptr;
cout<<"Item Inserted\n";
}

else
{
rear->next=ptr;
rear=ptr;
cout<<"Item Inserted\n";
}
break;

case 2:
if(front==NULL)
{
cout<<"Underflow\n";
}

else
{
if(front==rear)
{
front=rear=NULL;
cout<<"Item Deleted\n";
}
else
{
front=front->next;
cout<<"Item Deleted\n";
}

}
break;
}

ptr=front;

if(front!=NULL)
{
cout<<"Queue Now is\n";
while(ptr!=NULL)
{
cout<<ptr->info<<"<-";
ptr=ptr->next;
}
cout<<"\n";
}

}

}