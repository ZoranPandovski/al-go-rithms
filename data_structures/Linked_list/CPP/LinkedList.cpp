/* A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations, which is a linked list 
consists of nodes where each node contains a data field and a reference(link) to the next node in the list */

#include <iostream>
using namespace std;
int count =0;
class Node{   //To create Node in heap with data and next pointer
public:
    int data;
    Node *next;
};

class LinkedList{     //creates Linked List with help of class Node
    
private:
    Node *first;
    
public:
    LinkedList()     
    {
        first=NULL;
    }
    
    LinkedList(int arr[],int n)  //Takes input as array and its size from main to create Linked List 
    {
        Node *tmp,*last;
        first=new Node;
        first->data = arr[0];  //First element in array is First Node in Linked List
        first->next = NULL;
        last = first;
        for(int i=1;i<n;i++)   //Remaining Elements are followed by first Node
        {
            tmp = new Node;
            tmp->data = arr[i];
            tmp->next=NULL;
            last->next=tmp;
            last=tmp;
        }
   }
 
void display()          // To Display an Linked List
{
    Node *p=first;
    cout << "Nodes in Linked List are: " << endl;
    while(p)
    {
        cout << p->data << " "<< endl;
        p=p->next;
    }
}


int countNodes(Node *p)  //To return total count of Nodes in Linked List
{
    if(p==NULL)
        return 0;
    else
    {
        count++;
         return countNodes(p->next) + 1;
    }
    
}


void InsertNode(int index,int x)  //Takes index and Node's Data to be insterted into Linked List
{
    Node *p=first;
    Node *tmp;
    if(index < 0 || index > countNodes(p))
    {
        return;
    }
    tmp = new Node;
    tmp->data=x;
    if(index==0)
    {
        tmp->next=p;
        first=tmp;
    }
else
    {
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    tmp->next=p->next;
    p->next=tmp;
    }
}

int DeleteNode(int pos)   //Takes position to delete the corresponding Node from Linked List
{
    Node *p,*q=NULL;
    int x;
    if(pos==1)
    {
        p=first;
        x=p->data;
        first=first->next;
        delete p;
        return x;
    }
    else{
    p=first;
    q=NULL;
    for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
    q->next=p->next;
    x=p->data;
    delete p;
    return x;
    }
}
};

int main(){
cout <<"Enter number of elements to be inserted into LinkedList: " << endl;
int num,position,index,Element;
cin >> num;
int arr[num];
for(int i=0;i<num;i++)  // Array of Elements will be inserted into Linked List as separate Node,where each Node contains Data and next pointer which points to next Node
{
    cin >> arr[i];
}
LinkedList LL(arr,num);
LL.display();
cout <<"Enter an Element and its position to insert in LinkedList: " << endl;  //Enter Node data to be inserted into LL with position-1
cin >> Element;
cin >> position;
LL.InsertNode(position,Element);
cout <<"AFter Insertion" << endl;
LL.display();
cout <<"Enter a position to delete from LinkedList: " << endl;
cin >> index;
cout <<"Node " <<LL.DeleteNode(index)<<" Deleted from Linked List" << endl;
return 0;
}
