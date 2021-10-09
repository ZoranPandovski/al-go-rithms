#include <iostream>
#include <algorithm>
using namespace std;
#include <queue>

/* A binary tree node has data, pointer to left child and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/* Function to print level order traversal a tree*/
void printLevelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *Node = q.front();
        q.pop();
        if (Node != NULL)
        {
            cout << Node->data << " ";
            if (Node->left)
                q.push(Node->left);
            if (Node->right)
                q.push(Node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}

/* Driver program to test above functions*/
int main()
{
    struct node *p = new node(4);
    p->left = new node(1);
    p->right = new node(6);
    p->left->left = new node(5);
    p->left->right = new node(2);
    p->right->left=new node(9);
    p->left->right->left = new node(3);
    p->left->right->right = new node(7);
    // p->right->right=p6;

    /*     4
         /   \
        1     6
      /   \  /  \
      5   2  9  NULL
         / \
         3  7
*/
    cout << "Level Order Traversal: ";
    printLevelOrder(p);
    cout<<endl;

/* Input:
    1
  /   \ 
 3     2
 Output:1 3 2

      10
     /  \
    20   30
  /   \
 40   60
Output:10 20 30 40 60 

Time Complexity: O(N)
Auxiliary Space: O(N)
*/