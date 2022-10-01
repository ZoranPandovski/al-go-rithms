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
    void insertion(ListNode**sorted,ListNode* node)
    {
        ListNode* curr;
        if (*sorted == NULL || (*sorted)->val >= node->val)
        {
        node->next = *sorted;
        *sorted = node;
        }
        else 
        {
            curr=*sorted;
            while(curr->next!=NULL && curr->next->val<node->val)
            {
                curr=curr->next;
            }
            node->next=curr->next;
            curr->next=node;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
    ListNode* sorted=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ListNode* next=curr->next;
            insertion(&sorted,curr);
            curr=next;
        }
        head=sorted;
        return head;
    }
};