 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
    ListNode *prev = NULL;
    ListNode *cur = head;
    ListNode *successor = cur;

    while(cur != NULL)  {

      successor = successor->next;
      cur->next = prev;
      prev = cur;
      cur = successor;

    }

    return prev;
    }
};