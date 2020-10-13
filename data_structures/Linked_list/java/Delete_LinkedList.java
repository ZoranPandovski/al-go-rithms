package linkedlist;

class LinkedList {
    Node head;
    
    class Node {
        int data;
        Node next;
        
        Node(int data) {
            this.data = data;
            next = null;
        }
    }
    
    public void push(int data) {
        Node new_node = new Node(data);
        new_node.next = head;
        head = new_node;
    }
    public void printList() {
        Node n = head;
        while(n != null) {
            System.out.print(n.data+" ");
            n = n.next;
        }
    }
    public void deleteList() {
        head = null;
    }
    public static void main(String args[]) {
        LinkedList ll = new LinkedList();
        ll.push(2);
        ll.push(3);
        ll.push(4);
        ll.printList();
        System.out.println("After Deleting");
        ll.deleteList();
        ll.printList();
    }
}
