/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        int len=0;
        ListNode* curr=head,*temp=head,*t,*prev,*r,*node;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        
            t=temp->next;
            temp->next=t->next;
            t->next=temp;
            head=t;
            node=temp;
            while(node->next!=NULL && node->next->next!=NULL)
            {
                prev=node->next;
                r=prev->next;
                node->next=r;
                prev->next=r->next;
                r->next=prev;
                node=prev;
                
            }
        
        return head;
    }
};