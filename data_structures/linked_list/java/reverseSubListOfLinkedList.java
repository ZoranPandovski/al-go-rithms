/**
Problem Statement ---> 
  Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
  
  Test Case: 
  Input: head = [1,2,3,4,5], left = 2, right = 4
  Output: [1,4,3,2,5]
  
  */
/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(head==null || head.next==null || left==right) return head;
        
        if(head.next.next==null){
            ListNode temp = head.next;
            ListNode h1 = head;
            h1.next = null;
            temp.next = h1;
            
            return temp;
        }
        HashMap<Integer,ListNode> hm = new HashMap<>();
        int c = 1;
        ListNode temp = head;
        while(temp!=null){
            hm.put(c,temp);
            temp = temp.next;
            c++;
        }
        
        ListNode s1 = hm.get(1);
        ListNode e1 = hm.get(left-1);
        
        ListNode s2 = hm.get(right+1);
        ListNode e2 = hm.get(c);
        
        for(int i=left+1;i<=right;i++){
            hm.get(i).next = hm.get(i-1);
        }
        if(e1==null){
            hm.get(left).next = s2;
            return hm.get(right);
        }else{
            e1.next = hm.get(right);
            
            hm.get(left).next = s2;
        }
        
        return s1;
        
    }
}
