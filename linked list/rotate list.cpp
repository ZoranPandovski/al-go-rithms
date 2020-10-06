// Question : Given a linked list, rotate the list to the right by k places, where k is non-negative.


// Question link : https://leetcode.com/problems/rotate-list/


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head, *temp2 = head, *temp3 = head;
        if(head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }
        while(temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
        count++;
        
        if(k >= count)
        {
            k = k % count;
        }
        if(k == 0)
        {
            return head;
        }

        count = count - k -1;

        while(count--)
        {
            temp3 = temp3->next;
        }
        cout << temp3->val << endl;
        head = temp3->next;
        temp3->next = NULL;
        temp->next = temp2;
        return head;
    }
};
