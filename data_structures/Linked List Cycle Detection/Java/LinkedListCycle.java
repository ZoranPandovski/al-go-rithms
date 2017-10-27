/*-----------------------------------------------------------------------------------
 * <p> Title: LinkedList Cycle </p>
 *
 * <p> Description: A program that detects whether the given Linkedlist has a cycle(loop). </p>
 *
 * @author Venkatesh Bejjenki
 *------------------------------------------------------------------------------------
*/



class LinkedListNode {

    public int value;
    public LinkedListNode next;

    public LinkedListNode(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        String result ="" + value;
        LinkedListNode temp = next;

        while( temp != null ){
            result = result + " " + temp.value;
            temp = temp.next;
        }
        return result;
    }


}

class LinkedListCycle {

    public boolean containsCycle(LinkedListNode head){

        LinkedListNode temp = head;
        LinkedListNode slowPointer = head;
        LinkedListNode fastPointer = head;

        while (slowPointer!=null && fastPointer!=null) {
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;

            if (slowPointer == fastPointer) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        LinkedListCycle obj = new LinkedListCycle();

        LinkedListNode a = new LinkedListNode(1);
        LinkedListNode b = new LinkedListNode(2);
        LinkedListNode c = new LinkedListNode(3);
        LinkedListNode d = new LinkedListNode(4);
        LinkedListNode e = new LinkedListNode(5);
        LinkedListNode f = new LinkedListNode(6);

        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = a;

        System.out.println("Does this LinkedList contains cycles : "+obj.containsCycle(a));
    }
}
