// C++ program to populate inorder
// traversal of all nodes
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
    node *next;
};

/* Set next of p and all descendants of p
by traversing them in reverse Inorder */
void populateNext(node* p)
{
    // The first visited node will be the
    // rightmost node next of the rightmost
    // node will be NULL
    static node *next = NULL;

    if (p)
    {
        // First set the next pointer
        // in right subtree
        populateNext(p->right);

        // Set the next as previously visited
        // node in reverse Inorder
        p->next = next;

        // Change the prev for subsequent node
        next = p;

        // Finally, set the next pointer in
        // left subtree
        populateNext(p->left);
    }
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new
node with the given data and NULL left
and right pointers. */
node* newnode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    Node->next = NULL;

    return(Node);
}

// Driver Code
int main()
{

    /* Constructed binary tree is
            10
            / \
        8 12
        /
    3
    */
    node *root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);

    // Populates nextRight pointer in all nodes
    populateNext(root);

    // Let us see the populated values
    node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)
             << endl;
        ptr = ptr->next;
    }

    return 0;
}
