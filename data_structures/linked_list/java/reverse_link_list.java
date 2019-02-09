//  Reverse a linked list and return pointer to the head
//  The input list will have at least one element  
//  Node is defined as  
class Node {
   int data;
   Node next;
}

Node Reverse(Node head) {
    Node prev, nex , curr;
    prev = null;
    curr = head;
    while(curr != null){
        nex = curr.next;
        curr.next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
    return head;
}
