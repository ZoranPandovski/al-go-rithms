
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* right;
    struct Node* down;  
};
/* Function to insertAtBeginning ListA node */
void insertAtBeginning(struct Node** head, int dataToBeInserted)
{
    struct Node* curr = new Node;
    curr->data = dataToBeInserted;
    curr->right = NULL;
    curr->down = *head;
    *head = curr; 
    //O(1) constant time
}
 
//display linked list
void display(struct Node**node)
{
    struct Node *temp= *node;
    while(temp!=NULL)
        {
            if(temp->down!=NULL)
            cout<<temp->data<<"->";
            else
            cout<<temp->data;
            
            temp=temp->down; //move to right node
        }
        //O(number of nodes)
    cout<<endl;
}
 
//Merge sort of ListA and ListB
struct Node* MergeSort(struct Node* ListA, struct Node* ListB )
{
    //Base cases
    if (ListA == NULL)
    {
        return ListB;
    }
    if (ListB == NULL)
    {
        return ListA;
    }
    //compare data of heads and add smaller to root
    struct Node* result;
    if (ListA->data < ListB->data)
    {
        result = ListA;
        result->down = MergeSort(ListA->down, ListB);
    }
    else
    {
        result = ListB;
        result->down = MergeSort(ListA, ListB->down);
    }
 
    return result;
}
 
//Function that flattens the given list
struct Node* flatten(struct Node* root)
{
    if (root == NULL || root->right == NULL)
    {
        return root;
    }
    //Merge right with already flattens
    return MergeSort(root,flatten(root->right) );
}
 
//Main function
int main()
{
    //Given linked list
    struct Node* root = NULL;
 
    insertAtBeginning(&root, 14);
    insertAtBeginning(&root, 8);
    insertAtBeginning(&root, 7);
    insertAtBeginning(&(root->right), 6);
    insertAtBeginning(&(root->right), 4);
    insertAtBeginning(&(root->right->right), 18);
    insertAtBeginning(&(root->right->right), 13);
    insertAtBeginning(&(root->right->right), 9);
    insertAtBeginning(&(root->right->right->right), 17);
    insertAtBeginning(&(root->right->right->right), 15);
    insertAtBeginning(&(root->right->right->right), 11); 
    insertAtBeginning(&(root->right->right->right->right), 16);
   
    root = flatten(root);
    
    cout<<"Output (sorted) flatten List is: ";
    display(&root);
 
    return 0;
}