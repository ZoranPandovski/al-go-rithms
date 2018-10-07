// Author : Satyajit Das, NIT Durgapur, India

#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node *right;
    node *left;
};

void topview(node *root)
{
    if(root == NULL)
        return;
    unordered_map<int, int> m;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty())
    {
        pair<node *, int> p;
        p = q.front();
        node *n = p.first;
        int val = p.second;
        q.pop();

        if(m.find(val) == m.end())
        {
            m[val] = n->data;
            printf("%d ", n->data);
        }
        if(n->left != NULL)
            q.push(make_pair(n->left, val-1));
        if(n->right != NULL)
            q.push(make_pair(n->right, val+1));
    }
}
