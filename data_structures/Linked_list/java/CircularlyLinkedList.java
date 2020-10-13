public class CircularlyLinkedList<E> implements Cloneable {

    private static class Node<E> {

        private E element;            

        public Node(E e, Node<E> n, Node <E> p) {
            element = e;
            next = n;
        }

        public E getElement() { return element; }

        public Node<E> getNext() { return next; }

        public Node<E> getPrevious() { return previous; }
    
        public void setNext(Node<E> n) { next = n; }
        public void setPrevious(Node<E> p){previous = p;}
    }

    private Node<E> head = null;

    private Node<E> tail = null;               

    public CircularlyLinkedList() { }

    public int size() { //size is not perfect in terms of performance
                        //however it's just another way to do it as an idea
                        // if you want, you can just add an size int and count it.
        int cnt = 0;
        Node cntPtr = head;
        if (cntPtr!=null)
            cnt++;
            while (!(cntPtr==tail)){
            cntPtr = cntPtr.next;
            cnt++;
        }
        return cnt; }

    public boolean isEmpty() { return size() == 0; }


    public E first() {             // returns (but does not remove) the first element
        if (isEmpty()) return null;
        return head.getElement();
    }

    public E last() {              // returns (but does not remove) the last element
        if (isEmpty()) return null;
        return tail.getElement();
    }

    public void addFirst(E e) {                // adds element e to the front of the list
        if(tail!=null){
            head = new Node<>(e, head, tail);
        }
        else{
        head = new Node<>(e, head, head);      // create and link a new node
        if (size() == 2)                       // ADDS FIRST ELEMENT UNCONTROLLED AND EMPTY ELEMENT SO IT'S 2
            tail = head;                           // special case: new node becomes tail also
        }
    }

    public void addLast(E e) {                 // adds element e to the end of the list
        Node<E> newest = new Node<>(e, head, tail);    // node will eventually be the tail
        if (isEmpty())
            head = newest;                         // special case: previously empty list
        else
            tail.setNext(newest);                  // new node after existing tail
        tail = newest;                           // new node becomes the tail

    }
    public void addBetween(E element, Node<E> p, Node<E> n){
        Node<E> newNode = new Node(element, n, p);
        p.setNext(newNode);
        n.setPrevious(newNode);
    }

    public E removeFirst() {                   // removes and returns the first element
        if (isEmpty()) return null;              // nothing to remove
        E answer = head.getElement();
        head = head.getNext();                   // will become null if list had only one node
        if (size() == 0)
            tail = null;                           // special case as list is now empty
        return answer;
    }

    public E removeTail(){
        if (isEmpty()) return null;
        E answer = tail.getElement();
        tail=tail.getPrevious();
        if (size() == 0)
            tail = null;
        return answer;
    }
    public E removeElement(Node<E> node){
        node.getPrevious().setNext(node.getNext());
        node.getNext().setPrevious(node.getPrevious());
        return node.getElement();
    }

    @SuppressWarnings({"unchecked"})
    public boolean equals(Object o) {
        if (o == null) return false;
        if (getClass() != o.getClass()) return false;
        CircularlyLinkedList other = (CircularlyLinkedList) o;   // use nonparameterized type
        if (size() != other.size()) return false;
        Node walkA = head;                               // traverse the primary list
        Node walkB = other.head;                         // traverse the secondary list
        while (walkA != null) {
            if (!walkA.getElement().equals(walkB.getElement())) return false; //mismatch
            walkA = walkA.getNext();
            walkB = walkB.getNext();
        }
        return true;   // if we reach this, everything matched successfully
    }

    @SuppressWarnings({"unchecked"})
    public CircularlyLinkedList<E> clone() throws CloneNotSupportedException {
        CircularlyLinkedList<E> other = new CircularlyLinkedList<E>();
        if (size() > 0) {
            other.addFirst(head.getElement());
            Node <E> cloningElement = head.next;
            for(int i = 0; i < size()-1; i++){
                other.addLast(cloningElement.getElement());
                cloningElement = cloningElement.next;
            }
        }
        return other;

    }

    public int hashCode() {
        int h = 0;
        for (Node walk=head; walk != null; walk = walk.getNext()) {
            h ^= walk.getElement().hashCode();      // bitwise exclusive-or with element's code
            h = (h << 5) | (h >>> 27);              // 5-bit cyclic shift of composite code
        }
        return h;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("(");
        Node<E> walk = head;
        while (walk != tail) { //we need to run it till the last element, if null; the program will work forever
            sb.append(walk.getElement());
            if (walk != tail)
                sb.append(", ");
            walk = walk.getNext();
        }
        if(walk==tail){
            sb.append(walk.getElement());
        }
        sb.append(")");
        return sb.toString();
    }
}