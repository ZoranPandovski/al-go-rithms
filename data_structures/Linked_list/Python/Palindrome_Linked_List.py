'''
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
'''
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        # single node case
        if head.next is None:
            return True
        
        # two pointer to find the middle point of linked list
        first_pointer = head
        second_pointer = head.next
        
        while second_pointer and second_pointer.next:
            first_pointer = first_pointer.next
            second_pointer = second_pointer.next.next
        
        # reverse the second half of linked list
        prev_node = None
        current_node = first_pointer.next
        
        while current_node != None:
            temp = current_node.next
            current_node.next = prev_node
            prev_node = current_node
            current_node = temp
        
        # judge if is palindrome
        last = prev_node
        
        while last != None:
            if head.val != last.val:
                return False
            head = head.next
            last = last.next
            
        return True

'''
Input: head = [1,2,2,1]
Output: true
-----------------------
Input: head = [1,2]
Output: false
'''
