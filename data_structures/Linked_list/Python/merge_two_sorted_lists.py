# 21. Merge Two Sorted Lists - LeetCode 

# You are given the heads of two sorted linked lists list1 and list2.

# Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

# Return the head of the merged linked list.

 

# Example 1:


# Input: list1 = [1,2,4], list2 = [1,3,4]
# Output: [1,1,2,3,4,4]
# Example 2:

# Input: list1 = [], list2 = []
# Output: []
# Example 3:

# Input: list1 = [], list2 = [0]
# Output: [0]
 

# Constraints:

# The number of nodes in both lists is in the range [0, 50].
# -100 <= Node.val <= 100
# Both list1 and list2 are sorted in non-decreasing order.

# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        if list1 == None and list2 == None: 
            return None
        if list1 == None:
            return list2
        if list2 == None:
            return list1
        if list1.val <= list2.val:
            first = list1.val
            list1 = list1.next
        else:
            first = list2.val
            list2 = list2.next
        ans = ListNode(first)
        k = ans
        # res = []
        
        while list1 and list2:
            if list1.val <= list2.val:
                # res.append(list1.val)
                temp_val = list1.val
                list1 = list1.next
            else:
                # res.append(list2.val)
                temp_val = list2.val
                list2 = list2.next
            temp = ListNode(temp_val)
            k.next = temp
            k = k.next
            
        if list1:
            while list1:
                # res.append(list1.val)
                temp = ListNode(list1.val)
                k.next = temp
                k = k.next
                list1 = list1.next
        if list2:
            while list2:
                # res.append(list2.val)
                temp = ListNode(list2.val)
                k.next = temp
                k = k.next
                list2 = list2.next
                
        return ans
        