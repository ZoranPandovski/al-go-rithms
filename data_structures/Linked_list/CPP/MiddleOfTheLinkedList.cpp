//A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations!

#include <iostream>
using namespace std;

//Node Structure
class Node
{
    public:
     int data;
     Node *next;
};

//Linked List Functions
class LinkedList
{
    private:
     Node *first;
    public:
     LinkedList(){first=NULL;}
     LinkedList(int A[],int n);
     ~LinkedList();

     void Display();
     void Insert(int index,int x);
     int Delete(int index);
     int Length();
     int Middle();
};

//Parameterized Constructor to create a Linked List
LinkedList::LinkedList(int A[],int n)
{
     Node *last,*t;
     int i=0;

     first=new Node;
     first->data=A[0];
     first->next=NULL;
     last=first;

     for(i=1;i<n;i++)
     {
     t=new Node;
     t->data=A[i];
     t->next=NULL;
     last->next=t;
     last=t;
 }
}

//Destructor
LinkedList::~LinkedList()
{
     Node *p=first;
     while(first)
     {
        first=first->next;
        delete p;
        p=first;
     }
}

//Display of the Linked List
void LinkedList::Display()
{
    Node *p=first;

    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

//Length of the Linked List
int LinkedList::Length()
{
    Node *p=first;
    int len=0;

    while(p)
    {
        len++;
        p=p->next;
    }
    return len;
}

//Inserting in a Linked List
void LinkedList::Insert(int index,int x)
{
    Node *t,*p=first;

    if(index <0 || index > Length())
    return;
    t=new Node;
    t->data=x;
    t->next=NULL;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
 else
 {
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
 }
}

//Deletion in the Linked List
int LinkedList::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;

    if(index < 1 || index > Length())
    return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    delete p;
 }
 return x;
}

//Finding the middle element of the linked list. (If no. of elements even-> exact middle element   if even-> 2nd middle element)
int LinkedList::Middle()
{
    Node *slow=first,*fast=first;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
 int A[]={1,2,3,4,5};
 LinkedList l(A,5);  //Sending the Array of elements to the Linked List
 l.Display(); //Displaying the Linked List
 cout<<endl<<"Middle element of the Linked List: "<<l.Middle()<<endl; //Printing the Middle of the Element.
 return 0;
}
