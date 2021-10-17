class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
            if(head==null || head.next==null)
                    return null;
      ListNode t1=head;
           ListNode t2=head;
            int t=n;
            while(t-->0)
            {
                    t2=t2.next;
            }
           
        //    t2=t2.next;
            while(t2!=null)
            {
                    t1=t1.next;t2=t2.next;
                    
            }
            //t1 to be removed
         ListNode temp=head;
            //if n=size of ll and we have to remove 1st element
            if(temp==t1)
            {
                    head=t1.next;
                    return head;
            }
            while(temp.next!=t1)
                    temp=temp.next;
            temp.next=temp.next.next;
            t1.next=null;
            return head;
            
    }
}
