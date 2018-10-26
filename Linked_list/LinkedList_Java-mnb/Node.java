public class Node{

    public int item;
    public Node next;

    public Node(int i){
        this.item = i;
        this.next = null;
    }

    public void displayNode(){
        System.out.println(item);
    }
}