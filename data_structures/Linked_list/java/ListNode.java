
// * Definition for singly-linked list.
public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class LinkedList {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int carry=0;
        ListNode t = new ListNode(0);
        ListNode t_s = t;

        while(l1 != null && l2 != null){
            carry = sum/10;
            sum = l1.val+l2.val+carry;
            t.next = new ListNode(sum%10);
            t = t.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null){
            carry = sum/10;
            sum = l1.val+carry;
            t.next = new ListNode(sum%10);
            t = t.next;
            l1 = l1.next;
        }
        while(l2 != null){
            carry = sum/10;
            sum = l2.val+carry;
            t.next = new ListNode(sum%10);
            t = t.next;
            l2 = l2.next;
        }
        carry = sum/10;
        if(carry != 0){
            t.next = new ListNode(carry);
            t = t.next;
        }
        return t_s.next;
    }
}