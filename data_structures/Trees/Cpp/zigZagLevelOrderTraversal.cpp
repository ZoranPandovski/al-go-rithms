/*
Introduction 
Given a Binary Tree , Print it in Zig Zag level order.
(i.e., from left to right, then right to left for the next level and alternate between).

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
*/

#include <bits/stdc++.h> 
using namespace std;

//Define Node as structure
struct Node 
{
    int key;
    Node* left;
    Node* right;
};
 
// Function to create a node with 'value' as the data stored in it. 
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to build tree with given input
struct Node* createTree(vector<int>v)
{
    int n=v.size();
    if(n==0) 
      return NULL;
    vector<struct Node* >a(n);
    //Create a vector of individual nodes with given node values
    for(int i=0;i<n;i++)  
    {
        //If the data is -1 , create a null node
        if(v[i]==-1)  
          a[i] = NULL;
        else 
          a[i] = newNode(v[i]);
    }
    //Interlink all created nodes to create a tree
    //Use two pointers using int to store indexes
    //One to keep track of parent node and one for children nodes
    for(int i=0,j=1;j<n;i++) 
    {
        //If the parent node is NULL , advance children pointer twice
        if(!a[i])
        {
          j=j+2;
          continue;
        } 
        //Connect the two children nodes to parent node
        //First left and then right nodes
        a[i]->left = a[j++];
        if(j<n) 
          a[i]->right = a[j++];
    }
    return a[0];
}

// Function to print Tree in zig zag level order
void ZigZagLevelOrderTraversal(struct Node* root)
{
    // If root is NULL , return 
    if (root == NULL)
        return ;

    vector<int>v;
    //Define a variable to store level
    int curr_level=0;

    // Create an queue
    queue<struct Node*> q;
    //Enqueue the root node and a null node to indicate a level is completed
    q.push(root);
    q.push(NULL);
 
    while (!q.empty()) 
    {
        if(q.front()==NULL)
        {
            curr_level++;
            q.pop();
            if(!q.empty())
            {
                //If there are more nodes in q , push a NULL node
                q.push(NULL);
            }
            //When a level is completed , print its elements
            //If it is a odd level, print from left to right
            //else print from right to left
            if(curr_level%2)
            {
                for(int i=0;i<v.size();i++)
                  cout<<v[i]<<" ";
            }
            else
            {
                for(int i=v.size()-1;i>=0;i--)
                  cout<<v[i]<<" ";
            }
            //Clear the vector after printing
            v.clear();
        }
        else
        {
            v.push_back(q.front()->key);
            //Enqueue node's children , if they exist
            if(q.front()->left)
               q.push(q.front()->left);
            if(q.front()->right)
               q.push(q.front()->right);
            q.pop();
        }
    }
    return ;
}
    
// Driver code
int main()
{

    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i]; //store the input values in a vector
    }

    //create the tree using input node values  
    struct Node* root=createTree(v); 

    //Call the function and print the result
    cout<<"Zig Zag Level Order Traversal of given tree is : ";
    ZigZagLevelOrderTraversal(root);
    
    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
if node is NULL , -1 is entered as it's key

Sample Test Case 1  
Input Binary Tree :                   

               1                                
           /         \                          
         2              11                    
     /       \        /   \               
    3        5       12    13             
   / \      /  \    / \   /  \            

  4 NULL    6  7    8  9 NULL  4         

Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
1 2 11 3 5 12 13 4 -1 6 7 8 9 -1 4

Output Format :
Example : ( Output to the above input example ) 
Zig Zag Level Order Traversal of given tree is : 1 11 2 3 5 12 13 4 9 8 7 6 4 

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
