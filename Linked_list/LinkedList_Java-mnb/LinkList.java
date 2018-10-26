public class LinkList{
    private Node head;

    public void LinkList(){
        head=null;
    }

    public void insert(int i){
        Node newNode = new Node(i);
        newNode.next = head;
        head = newNode;

        System.out.println("New Node Inserted : "+i);
    }

    public Node find(int key){
        int i=1;
        Node current = null;

        current = head;

        while(current != null && i != key){
            current = current.next;
            i++;
        }

        return current;
        
    }
 
    public void delete(int key){
        Node current = null;
        Node previous = null;

        current = head;
        previous = head;

        int i = 1;

        while(current.next != null && i != key){

            previous = current;
            current = current.next;
            i++;
        }
        if(current==head){
            head = head.next;
        }else{
            previous.next = current.next;
        }
         System.out.println("Item Deleted");
    }

    public void display(){
        Node current;

        current = head;

        while(current != null){
            System.out.println("Node : "+ current.item);
            current = current.next;
        }
    }


}