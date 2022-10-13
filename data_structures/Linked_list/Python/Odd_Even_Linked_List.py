'''
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
'''
class Solution(object):
    def oddEvenList(self, head):
        if head is None: return None
        if head.next is None: return head
        o = head
        p = o.next
        ehead = p
        while p.next is not None:
            o.next = p.next
            p.next = p.next.next
           
            o = o.next
            p = p.next
            if p is None: break
        o.next = ehead
        return head
 
'''
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
----------------------
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
'''
