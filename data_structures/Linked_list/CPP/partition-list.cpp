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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy=new ListNode();
        ListNode *res=dummy;
        ListNode*curr=head,*prev=NULL,*s=NULL;
        while(head!=NULL)
        {
            if(head->val<x)
            {
                res->next=head;
                if(prev!=NULL)
                {
                    prev->next=head->next;
                }
                res=res->next;
            }
            else
            {
                if(s==NULL)
                {
                    s=head;
                }
                prev=head;
            }
            head=head->next;
        }
        res->next=s;
        return dummy->next;
    }
};