/*

https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]


Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

*/

#include <iostream>
#include <sstream>
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(head == NULL || head->next == NULL)
        return NULL;
    ListNode *beg = head, *end = head;
    while(end!=NULL)
    {
        if(n>0)
        {
            n--;
            end = end->next;
        }
        else
        {
            if(end->next == NULL)
            {
                beg->next = beg->next->next;
                break;
            }
            else
            {
                beg = beg->next;
                end = end->next;
            }
        }
    }
    if(end == NULL && beg == head)
    {
        return head->next;
    }
    return head;
}

void insert(ListNode** root, int item)
{
    ListNode* temp = new ListNode;
    ListNode* ptr;
    temp->val = item;
    temp->next = NULL;

    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display(ListNode* root)
{
while (root != NULL)
  {
    std::cout << root->val << " ";
    root = root->next;
  }
}

int main(int argc, char const *argv[])
{
  ListNode *number1 = new ListNode();
  ListNode *number2 = new ListNode();
  int input,len=0;
  std::string line;
  std::cout << "Enter a list of numbers between 0 and 100. If there are invalid numbers they will be discarded. " << '\n';
  std::getline(std::cin, line);
  std::istringstream stream(line);
  while (stream >> input && len <=30)
  {
    if(input <=100 && input>=0)
    {
      insert(&number1, input);
      len++;
    }
  }
  std::cout << "Enter the index from the end you want to delete between 1 and the total number of elements" << '\n';
  std::cin >> input;
  ListNode *answer;
  if(input>0 && input<=len)
  {
    answer = removeNthFromEnd(number1->next,input);
  }
  std::cout << "the list after deleting is: \n";
  display(answer);
  std::cout << "\n";
  return 0;
}

/* the solution is 4ms */
