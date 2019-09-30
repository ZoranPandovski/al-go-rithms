#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *last;
struct node * createNode(int data)
{
    struct node * nnode = (struct node * ) malloc (sizeof(struct node));
    nnode->data = data;
    nnode->next = NULL;
    return nnode;
}
void addAtBeg(int x)
{
    struct node * nnode =  createNode(x);
    if(last == NULL)
    {
        last = nnode;
        nnode->next = last;
        return;
    }
    struct node *temp = last->next;
    last->next = nnode;
    nnode->next = temp;
}
void addAtEnd(int x)
{
    if(last == NULL)
    {
        return addAtBeg(x);
    }
    struct node * nnode =  createNode(x);
    nnode->next = last->next;
    last->next = nnode;
    last = nnode;
}
void addAfter(int x, int item)
{
    struct node * temp = last->next;
    do
    {
        if(temp->data == item)
        {
            struct node * nnode =  createNode(x);
            nnode->next = temp->next;
            temp->next = nnode;
            if(temp == last)
                last = nnode;
            return;
        }
        temp = temp->next;
    }while(temp != last->next);
    cout<<"Element not found"<<endl;
}
void del(int x)
{
    if(last == NULL)
    {
        cout<<"linked list is empty"<<endl;
        return;
    }
    struct node *temp = last->next;
    if(last == last->next && temp->data == x)
    {
        struct node *xyz = last;
        last = NULL;
        delete(xyz);
        return;
    }
    struct node *p = last;
    while(p->next != last)
    {
        if(p->next->data == x)
        {
            struct node *xyz = p->next;
            p->next = xyz->next;
            delete(xyz);
            return;
        }
        p = p->next;
    }
    if(last->data == x)
    {
        struct node *xyz = last;
        p->next = last->next;
        last = p;
        delete(xyz);
        return;
    }
    cout<<"Element not found"<<endl;
}
void print()
{
    if(last == NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return;
    }
    struct node *temp = last->next;
    do
    {
        cout<<temp->data<<" => ";
        temp = temp->next;
    }while(temp != last->next);
    cout<<"NULL"<<endl;
}
int main()
{
    int x = 1,n,d,nd;
    last = NULL;
    cout<<"Enter 0 to exit"<<endl;
    cout<<"Enter 1 to add node at beginning"<<endl;
    cout<<"Enter 2 to add node at end"<<endl;
    cout<<"Enter 3 to add node after specific node"<<endl;
    cout<<"Enter 4 to delete node"<<endl;
    cout<<"Enter 5 to display linked list"<<endl;
    while(x)
    {
        cout<<"Enter case ";
        cin>>n;
        switch(n)
        {
        case 0:
            x = 0;
            break;
        case 1:
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            addAtBeg(d);
            break;
        case 2:
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            addAtEnd(d);
            break;
        case 3:
            cout<<"Enter node data to insert after: "<<endl;
            cin>>nd;
            cout<<"Enter data to insert: "<<endl;
            cin>>d;
            addAfter(d,nd);
            break;
        case 4:
            cout<<"Enter data to delete: "<<endl;
            cin>>d;
            del(d);
            break;
        case 5:
            print();
            break;
        default:
            cout<<"Not a valid case"<<endl;
        }
    }
    return 0;
}
