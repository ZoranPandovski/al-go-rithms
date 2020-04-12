#include<iostream>

using namespace std;


class node
{
	int info;
	node* next;
	node* prev;
public:
	node* insert(node*);
	node* dele(node*);
	void display(node*);
};
node* node::insert(node* start)
{
	int info,ch;
	node* cur;
	node* temp=new node;
	cout<<"Enter information..\n";
	cin>>temp->info;
	temp->next=temp;
	temp->prev=temp;
	cout<<"Enter choice..\n1.Insert at beg\n2.Insert at end\n";
	cin>>ch;
	if(ch==2)//Insert at end..
	{
		if(start==NULL)
		{
			cout<<"List empty..\n";
			start = temp;
			cout<<start->info;
		}
		else
		{
			node* cur;
			cur = start;
			while(cur->next != start)
				cur=cur->next;
			cur -> next = temp;
			start -> prev = temp;
			temp -> next = start;
			temp -> prev = cur;
		}

	}
	else//insert at beg
	{
		if(start==NULL)
		{
			cout<<"List empty..\n";
			start = temp;
		}
		else
		{
			cur = start;
			temp -> next = start;
			start -> prev = temp;
			while(cur->next != start)
				cur = cur->next;
			temp -> prev = cur;
			cur -> next = temp;
			start = temp;
		}
	}
	return start;
}
node* node::dele(node* start)
{
	if(start==NULL)
	{
		cout<<"List empty..\n";
		return start;
	}
	else
	{
		int ele;
		cout<<"Enter the element you want to delete..\n";
		cin>>ele;
		node* cur = start;

		// Works with a single while loop aswell
		// No need to specifically write the cases for first and last elements..

		if(start->info==ele)
		{
			cout<<"first element matched..\n";
			(start->prev)->next = start->next;
			(start->next)->prev = start->prev;
			start = start->next;
			delete cur;
			return start;
		}
		while((cur->next != start))
		{
			if(cur->info == ele)
			{
				cout<<"Key matched..\n";
				(cur->prev)->next = cur->next;
				(cur->next)->prev = cur->prev;
				delete cur;
				return start;
			}
			cur = cur->next;
		}
		if(cur->info==ele)
		{
			cout<<"Last element matched..\n";
			(cur->next)->prev = cur->prev;
			(cur->prev)->next = cur->next;
			delete cur;
			return start;
		}
		else
		{
			cout<<"Key not matched..\n";
			return start;
		}
	}
}
void node::display(node* start)
{
	if(start==NULL)
	{
		cout<<"LIST EMPTY...\n";
		return;
	}
	if(start == start->next)
	{
		cout<<"only one element present..\n";
		cout<<start->info<<" ";
		return;
	}
	cout<<"Displaying the list..\n";
	node* cur = start;
	while(cur->next != start)
	{
		cout<<" "<<cur->info<<" ";
		cur=cur->next;
	}
	cout<<cur->info<<"";
}
int main()
{
	node* start = NULL;
	node n;
	int ch=1,ch1;
	while(ch)
	{
		cout<<"\n\nEnter   1.insert\n\t2.dele\n\t3.display\n\t4.Exit\n\n";
		cin>>ch1;
		switch(ch1)
		{
			case 1: cout<<"insert..\n";
			start = n.insert(start);
			break;
			case 2: cout<<"dele..\n";
			start = n.dele(start);
			break;
			case 3: cout<<"Displaying..\n";
			n.display(start);
			break;
			case 4: cout<<"Exit..\n";
			ch=0;
			break;
		}
	}
}