#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
	int info;
	node * link;
};
int main()
{
	int n,item;
	node *start;
	start=NULL;
	do
	{
		cout<<"1.Insert a new node\n2.Delete a node\n3.Find a node with given data\n4.Find middle of Linked List\n5.Insert a node with "
			<<"some data before another node\n6.Exit";
		cin>>n;
		switch(n)
		{
			case 1:
			{
				node *newnode=new node();
				node *ptr;
				cout<<"Enter the info of node";
				cin>>item;
				newnode.info=item;
				newnode.link=NULL;	
				if(start==NULL)
				{
					start=newnode;
				}
				else
				{
					ptr=start;
					while(ptr.link!=NULL)
					{	
						ptr=ptr.link;
					}
					ptr.link=newnode;
				}
				break;
			}
			case 2:
			{
				int item;
				cout<<"Enter the info of the node to be deleted";
				cin>>item;
				
			}
			case 3:
			{
				cout<<"Enter the data to find";
				cin>>item;
				node *ptr,*loc;
				ptr=start;
				while(ptr!=NULL)
				{
					if(ptr.info==item)
					{
						loc=ptr;
						break;
					}
					ptr=ptr.link;
				}
				if(loc!=NULL)
					cout<<"Found at address: "<<loc;
				else
					cout<<"Not Found";
				/*ALTERNATE
				node *ptr,*loc=NULL;
				ptr=start;
				while(ptr.info!=item && ptr!=NULL)
				{
					ptr=ptr.link;
				}
				loc=ptr;
				if(loc!=NULL)
					cout<<"Found at position "<<loc;
				else
					cout<<"Not Found";*/
			}
			case 4:
			{
				node *ptr1,*ptr2,*loc,*loc2;
				int cnt=0,mid,mid2;
				ptr1=start;
				ptr2=start;
				while(ptr1!=NULL)
				{
					cnt++;
					ptr1=ptr1.link;
				}
				mid=cnt/2;
				while(--mid)
				{
					ptr2=ptr2.link;
				}
				if(cnt%2==0)
				{
					loc=ptr2;
					loc2=ptr2.link;
					cout<<loc.info<<" "<<loc2.info<<endl;
				}
				else	
				{
					loc=ptr2.link;
					cout<<loc.info<<endl;
				}
			}
			case 5:
			{
				node *ptr,*ptr2;
				ptr=start;
				ptr2=start;
				int x,y;
				cout<<"Enter the new node's data and data of next node";
				cin>>x>>y;
				node *newnode=new node();
				newnode.info=x;
				if(ptr.info==y)
				{
					newnode.link=ptr;
					start=newnode;
				}
				else
				{	while(ptr.info!=y)
					{
						ptr=ptr.link;
					}
					while(ptr2.link!=ptr)
					{
						ptr2=ptr2.link;
					}
					newnode.link=ptr;
					ptr2.link=newnode;
				}
			}
		}	
	}
	while(n!=6);
	return 0;
} 
