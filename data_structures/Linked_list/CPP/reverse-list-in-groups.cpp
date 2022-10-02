we will reverse in sublists of sizes k each 

Reverse the first sub-list of size k.
 While reversing keep track of the next node and previous node. 
 Let the pointer to the next node be next and pointer to the previous node be prev.

 head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )

 Return prev 


 prog:
  struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(!head)
        return NULL;
        node * curr=head,*prev=NULL,*next=NULL;
        int count=0;
        while(curr!=NULL && count<k)
        {
            next=curr->next;
            curr->next=prev;
             prev=curr;
            curr=next;
           
            count++;
        }
        
        if(next!=NULL)
        head->next=reverse(next,k);
        return prev;
        
    }

 Time Complexity: O(n). 
Traversal of list is done only once and it has ‘n’ elements.
Auxiliary Space: O(n/k). 
For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.
