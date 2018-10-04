#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
struct node{
	int info;
	node *left,*right;
}*ptr,*start,*last,*save;

int c=1,i=0,data,item;
start=last=NULL;

while(c<4 && c>0){
	cout<<"1.Insert\n2.Deletion\n3.Link List\n";
	cin>>c;

	switch(c){
		case 1:
		cout<<"Enter Data\n";
		cin>>data;

		ptr=new node;
		ptr->info=data;
		ptr->left=last;
		ptr->right=NULL;

		if(start==NULL){
			start=last=ptr;
		}

		else{
			last->right=ptr;
			last=ptr;
		}
		break;

		case 2:
		if(start==NULL){
			cout<<"Underflow\n";
		}

		else{
			cout<<"Enter Item to be Deleted\n";
			cin>>item;
			ptr=start;

			while(ptr!=NULL){
				if(ptr->info==item){
					i++;
					if(ptr==start){
						start->left=NULL;
						start=start->right;
					}

					else{
						ptr->left->right=ptr->right;
						ptr->right->left=ptr->left;
					}
				delete ptr;
				cout<<"Item Deleted\n";
				}
				ptr=ptr->right;
			}
	
			if(i==0){
				cout<<"Item Does not exist\n";
			}
			i=0;
		}
		break;

		case 3:

		ptr=start;

		while(ptr!=NULL){
			cout<<ptr->info<<"->";
			ptr=ptr->right;
		}
		cout<<"\n";
		break;

		default:
		cout<<"Wrong Choice\nExiting...\n";
	}

}

getch();
return 0;
}
