# 23. Merge k Sorted Lists - LeetCode 

# You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

# Merge all the linked-lists into one sorted linked-list and return it.

 

# Example 1:

# Input: lists = [[1,4,5],[1,3,4],[2,6]]
# Output: [1,1,2,3,4,4,5,6]
# Explanation: The linked-lists are:
# [
#   1->4->5,
#   1->3->4,
#   2->6
# ]
# merging them into one sorted list:
# 1->1->2->3->4->4->5->6
# Example 2:

# Input: lists = []
# Output: []
# Example 3:

# Input: lists = [[]]
# Output: []

# Definition for singly-linked list.
from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Here we append all the elements of k lists to a list and sort the list. 
# We then use this sorted list to create a new linked list

class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        res = []
        for i in lists:
            while i != None:
                res.append(i.val)
                i = i.next
        # print(res)
        if res == []:
            return None
        
        res.sort()
        ans = ListNode(res[0])
        result = ans
        for i in range(1,len(res)):
            k = ListNode(res[i])
            ans.next = k
            ans = ans.next
        return result