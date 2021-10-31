#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

Node *KthLargestelement(Node *root, int k)
{
    Node *curr = root;
    Node *Klargest = NULL;

    int count = 0;

    while (curr != NULL)
    {
        if (curr->right == NULL)
        {

            if (++count == k)
                Klargest = curr;

            curr = curr->left;
        }

        else
        {

            Node *succ = curr->right;

            while (succ->left != NULL && succ->left != curr)
                succ = succ->left;

            if (succ->left == NULL)
            {

                succ->left = curr;

                curr = curr->right;
            }

            else
            {

                succ->left = NULL;

                if (++count == k)
                    Klargest = curr;
                curr = curr->left;
            }
        }
    }

    return Klargest;
}

// Driver code

int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(10);

    cout << "Finding K-th largest Node in BST : "
         << KthLargestelement(root, 2)->data;

    return 0;
}
