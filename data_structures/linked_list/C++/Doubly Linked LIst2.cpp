#include "iostream.h"
using namespace std;
struct Node
{
	int data;
	Node* prevs;
	Node* link;
};
Node* A;
void insert()
{
	int n,p;
	Node* temp=new Node;
	cout<<"Enter the number to be inserted:";
	cin>>n;
	cout<<"Enter the position:";
	cin>>p;
	if(p==1)
	{
		temp->prevs=NULL;
		temp->data=n;
		temp->link=A;
		A=temp;
		return;
	}
	Node* temp2=new Node;
	temp=A;
	for (int i=1;i<p-1;i++)
	{
		temp=temp->link;
	}
	temp2->data=n;
	temp2->link=temp->link;
	temp2->prevs=temp;
	temp->link=temp2;
	temp=temp2->link;
	if (temp!=NULL)
	{
		temp->prevs=temp2;
	}
}
void delet()
{
	int p;
	cout<<"Enter the position to be deleted:";
	cin>>p;
	Node* temp=A;
	if(p==1)
	{
		A=temp->link;
		temp=NULL;
		A->prevs=NULL;
		return;
	}
	for(int i=1;i<=p-1;i++)
	{
		temp=temp->link;
	}
	Node* temp2=new Node;
	temp2=temp->prevs;
	temp2->link=temp->link;
	temp=NULL;
	if(temp2->link==NULL)
	{
		return;
	}
	temp=temp2->link;
	temp->prevs=temp2;
}
void display()
{
	Node* temp=new Node;
	temp=A;
	while(temp!=NULL)
	{
		cout<<"->"<<temp->data;
		temp=temp->link;
	}
	cout<<"\n";
}
void rev()
{
	Node* temp=A;
	Node* pt=new Node;
	while(temp!=NULL)
	{
		if(temp->link==NULL)
		{
			A=temp;
		}
		pt=temp->link;
		temp->link=temp->prevs;
		temp->prevs=pt;
		temp=temp->prevs;
	}
	
}
void main()
{
	A=NULL;
	while(1)
	{
		int ch;
		cout<<"Enter your choice:\n1-Insert\n2-Delete\n3-Display\n4-Reverse\n5-Exit\n->";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				rev();
				break;
			case 5:
				exit(0);
		}
	}
}

