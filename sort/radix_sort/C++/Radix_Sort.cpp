#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
		int data;
		Node *next;
}node;
node *createNode(int n)
	{
		node *ptr=new node;
		ptr->data=n;
		ptr->next=NULL;
		return ptr;
	}
node *insert(node *head,int t)
	{
		node *ptr=createNode(t);
		if(head==NULL)
			head=ptr;
		else
		{
			node *tmp=head;
			while(tmp->next!=NULL)
				tmp=tmp->next;
			tmp->next=ptr;
		}
		return head;
	}
node *delete1(node *head,int arr[],int &k)
	{
		if(head!=NULL)
		{
			node *tmp=head;
			while(tmp!=NULL)
			{
				arr[k++]=tmp->data;
				node *t=tmp;
				tmp=tmp->next;
				free(t);
			}

		}
		head=NULL;
		return head;

	}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int d=1,k=0;
	node *head[10];
	for(int i=0;i<10;i++)
		head[i]=NULL;
	int flag=0;
	while(1)
	{
		flag=0;
	  for(int i=1;i<=n;i++)
	   {
	   	int t=arr[i];
		int x=arr[i]/d;
		if(x!=0)
			flag=1;
		x=x%10;
		head[x]=insert(head[x],t);
	   }
	   if(flag==0)
	   	break;
	   k=1;
	   for(int i=0;i<10;i++)
	   {
	   	   head[i]=delete1(head[i],arr,k);
	   }

	   d=d*10;
	  
   }
   for(int i=1;i<=n;i++)
   	cout<<arr[i]<<" ";

	return 0;
}