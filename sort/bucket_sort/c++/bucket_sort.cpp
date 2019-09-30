#include <iostream>
 
using namespace std;
 
// A structure to represent a node.
struct Node
{
  int value;
  struct Node* next;
};
 
// A structure to represent a Head Bucket Node of the bucket list.
struct Bucket
{
  // Pointer to head node of Bucket.
  struct Node *head;  
};
 
struct BucketList
{
  int V;
  struct Bucket * array;
};
 
 
// A utility function to create a new node for a particular entry in a bucket.
struct Node* newNode(int value)
{
  struct Node* newnode = new Node;
  newnode->value = value;
  newnode->next = NULL;
  return newnode;
}
 
// A utility function that creates a list of the bucket over the range of input data.
struct BucketList* createBucket(int V)
{
  int i;
  struct BucketList* bl = new BucketList;
 
  bl->V = V;
  bl->array = new Bucket[V];   
 
 
  // Initialize each Bucket list as empty by making head as NULL.
  for(i = 0; i < V; i++)
    bl->array[i].head = NULL;
 
  return bl;
}
 
// A function to Insert the nodes to corresponding Buckets.
void addNode(struct BucketList* bl, int bckt, int value)
{
  // Creating new data node.
  struct Node *newnode = newNode(value);
  struct Node *temp = new Node;
 
  if(bl->array[bckt].head != NULL)
  {
    temp = bl->array[bckt].head;
 
    // Sorting.
    // If the head node value is lesser than the newnode value, then add node at beginning.
    if(temp->value > newnode->value)
    {
      newnode->next = bl->array[bckt].head;
      bl->array[bckt].head = newnode;
    }
    else
    {
      // Search for the node whose value is more than the newnode value.
      while(temp->next != NULL)
      {
        if((temp->next)->value > newnode->value)
          break;
 
        temp = temp->next;
      }
 
      // Insert newnode after temp node.
      newnode->next = temp->next;
      temp->next = newnode;
    }
  }
  else
  {
    // Assign head of the Bucket as newnode since bucket head is NULL.
    bl->array[bckt].head = newnode;
  }
}
 
// A function to print the result as sorted Data.
void printBuckets(struct BucketList *bl)
{
  int v;
  struct Node* pCrawl = new Node;
 
  for(v = 0; v < bl->V; v++)
  {
    // To view the data in individual bucket remove next line from comment.
    // cout<<"\n\t bucket "<<v+1;
 
    pCrawl = bl->array[v].head;
    while (pCrawl != NULL)
    {
      cout<<"->"<< pCrawl->value;
      pCrawl = pCrawl->next;
    }
  }
}
 
 
int main()
{
  // Create the BucketLists for the data and set 10 as default number of Buckets.
  int V = 10, range, NOE, i;
  struct BucketList* mybucket = createBucket(V);
 
 
  cout<<"\n\nEnter the upper limit in the power of 10 (10 or 100 or 1000 ..) to create Bucket: ";
  cin>>range;
 
  // Dividing range into 10 parts so it will have 10 buckets as default.
  range = range/10;
 
  cout<<"\nEnter the number of data element to be sorted: ";
  cin>>NOE;
  int arr[NOE];
 
  for(i = 0; i < NOE; i++)
  {
    cout<<"Enter element "<<i+1<<" : ";
    cin>>arr[i];
    addNode(mybucket, arr[i]/range, arr[i]);
  }
 
  // Print the adjacency list representation of the BucketList i.e the sorted Output.
  cout<<"\nSorted Data ";
  printBuckets(mybucket);
 
  return 0;
}