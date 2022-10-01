class Node{
        Node next=null;
        Node prev=null;
        int data;
        Node(int data){
            this.data = data;
        }
    }

class DoublyLinkedList{
    Node head;
    public void addAtFront(int data){
        if(head ==null){
            head = new Node(data);
            return;
        }
        Node newNode = new Node(data);
        head.prev = newNode;
        newNode.next = head;
        head = newNode;
    }
    
    public void printList(){
        Node current = head;
        while(current != null){
            System.out.println(current.data);
            current = current.next;
        }
    }
    
    public void printListReverse(){
        Node current = head;
        //going to the last node
        while(current.next !=null){
            current = current.next;
        }
        //traversing using prev pointer
        while(current!=null){
            System.out.println(current.data);
            current = current.prev;
        }
    }
    
    public void append(int data){
        Node current = head;
        while(current.next!=null){
            current = current.next;
        }
        Node newNode = new Node(data);
        newNode.prev = current;
        current.next = newNode;
    }
    
    //todo add method for insert at position and delete
     public void deleteWithValue(int data){
        if(head ==null) return;
        if(head.data==data){
            head = head.next;
            return;
           
        }
        Node current = head;
        while(current.next!=null){
            if(current.next.data ==data){
                current.next = current.next.next;
                return;
            }
            current =current.next;
        }
    }
    public static void main(String args[]){
        DoublyLinkedList list = new DoublyLinkedList();
        list.addAtFront(1);
        list.append(12);
        list.addAtFront(5);
        list.addAtFront(7);
        list.printList(); //prints in current order
        //list.printListReverse(); //prints in reverse order
        //list.append(8);
        //list.printList();
        list.deleteWithValue(5);
        list.deleteWithValue(7);
        list.printList(); 
        
    }
    
}
