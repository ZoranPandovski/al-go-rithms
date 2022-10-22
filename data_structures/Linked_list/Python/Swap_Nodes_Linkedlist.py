# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None:
            return None
        if head.next==None:
            return head
        tmp1=head
        tmp2=head.next
        while tmp1:
         
         if tmp1 !=None and tmp2 !=None:
            print(tmp1.val)
            print(tmp2.val)
            
            tmpx_val=tmp1.val
            tmpx=tmp1
            
            tmp1.val=tmp2.val
            tmp2.val=tmpx_val
            
            tmp1=tmp2.next
            if tmp2.next!=None:
             tmp2=tmp2.next.next
            else:
             temp2=None
         else:
             break
        return head
        
            
         
