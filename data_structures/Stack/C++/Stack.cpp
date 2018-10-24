#include <iostream>

using namespace std;
struct node
{
    int data;
    node*next;
};

 bool isempty(node*head)
    {
        if (head== NULL)
        {
            return true;
        }
        else
            {
                return false;
            }

    }
    void insertelement(int x, node &*head,node &*last){ // & because i will change the address
        // pointer for head and another for tail
    node *temp = new node; // pointer of type node points to new nodes
    temp -> data = x;       // using pointer to access node and data
    temp -> next = NULL; // puts node at the end always
    if (isempty(head)){
     head = temp;
     last = temp;
    }
    else{
     last -> next = temp; // make it point at temp
     last =temp;
    }
    }
int main()
{
    node *head= NULL;
    node *tail= NULL;
    isempty(head);
    cout<<(isempty(head));

    return 0;
}