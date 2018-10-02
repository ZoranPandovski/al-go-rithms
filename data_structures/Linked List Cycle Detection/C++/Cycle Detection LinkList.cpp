#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* newNode(int val)
{
    Node* ptr = new Node;
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}
int Detect_Cycle(Node *root)
{
    if(!root || !root->next)
        return false;

    Node *slow=root, *fast = root->next;
    while(fast && fast->next)
    {
        if(slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main()
{
    Node* a = newNode(1);
    Node* b = newNode(2);
    Node* c = newNode(3);
    Node* d = newNode(4);
    Node* e = newNode(5);
    Node* f = newNode(6);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = a; //Make this NULL for NO cycle

    if(Detect_Cycle(a))
        cout<<"Cycle Exist\n";
    else
        cout<<"Cycle doesnot exist\n";

    return 0;
}
