#include <iostream>
using namespace std;


/*
This represents the structure of the node of the Doubly Linked List.
*/


struct node
{
    node * next;
    node * prev;
    int data;
};


/*
This function deletes a node in a doubly linked list
*/

node * delete_node(node *head,int val)
{
    if (head == NULL)
        return NULL;

    node * temp=head;

    while(temp!=NULL)
    {
        if(temp->data==val)
        {

            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;

            return head;
        }
        temp=temp->next;
    }
    return NULL;
}


/*
This function adds new data into doubly linked list. 
It takes head of the list as parameter along with the new data to be inserted.
*/


node * add_data_end(node * head,int val)
{
    node * newNode = new node;
    newNode->data = val;
    newNode->next = NULL;
    
    if(head == NULL)
    {
        newNode->prev=NULL;
        return newNode;
    }
    
    node * temp = head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newNode;
    newNode->prev = temp;

    return head;
}


/*
This function traverses the list and prints the values
*/


node * print_list(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    node * head =NULL;
    
    //  Insertion into list
    head=add_data_end(head,30);
    head=add_data_end(head,12);
    head=add_data_end(head,2);
    head=add_data_end(head,15);
    head=add_data_end(head,6);
    head=add_data_end(head,54);
    head=add_data_end(head,27);

    print_list(head);
    cout<<"\n";

    delete_node(head,15);
    
    print_list(head);
    cout<<"\n";

    return 0;
}