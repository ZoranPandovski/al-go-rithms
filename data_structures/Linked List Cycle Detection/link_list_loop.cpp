#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  node *next;
};

struct node* new_node(int key) 
{ 
    struct node *temp = new node(); 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

void detect_loop(struct node *head)
{
  node *slow,*fast;
  slow = fast = head;
  bool loop = false;
  
  while(slow && fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next;
    fast = fast->next;
    
    if(slow==fast)
    {
    	loop = true;
    	break;
    }
  }
  if(loop)
  cout<<"Loop detected\n";
  else
  cout<<"Loop not detected\n";
}

int main()
{
  struct node *head = new_node(10);
  head->next = new_node(20);
  head->next->next = new_node(30);
  head->next->next->next = new_node(40);
  head->next->next->next->next = new_node(50);
  
//Adding a loop
  head->next->next->next->next->next = head->next->next;
  detect_loop(head);
  return 0; 
}
