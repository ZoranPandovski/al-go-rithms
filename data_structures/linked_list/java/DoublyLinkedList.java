
public class DoublyLinkedList<T> {

    private T data;
    private Node head;
    private Node tail;
    private int size = 0;

    /**
     * Constructs an empty DoublyLinkedList
     */
    public DoublyLinkedList() {

        this.head = new Node();
        this.tail = new Node();
        this.size = 0;

        this.head.next = tail;
        this.tail.previous = head;

    }

    /**
     * Adds a value at the end of the list.
     *
     * @param data The value to add at the end of the list.
     */
    public void addLast(T data) {
        Node newNode = new Node(data);
        Node temp = tail.previous;

        temp.next = newNode;
        newNode.previous = temp;
        newNode.next = tail;
        tail.previous = newNode;
        size++;
    }

    /**
     * Adds a value at the beginning of the list.
     *
     * @param data The value to add at the beginning of the list.
     */
    public void addFirst(T data) {
        Node newNode = new Node(data);
        Node temp = head.next;

        head.next = newNode;
        newNode.previous = head;
        temp.previous = newNode;
        newNode.next = temp;
        size++;
    }

    /**
     * Adds the value at the specified index in the list.
     *
     * @param i The index to insert the value at.
     * @param data The value to insert.
     */
    public void addAtIndex(int i, T data) {
        if (i > size || i < 0) {
            throw new IndexOutOfBoundsException();
        } else if (this.isEmpty() || i == 0) {
            this.addFirst(data);
            return;
        } else if (i == size) {
            this.addLast(data);
            return;
        }

        Node currentNode = getNodeAtIndex(i);
        Node newNode = new Node(data);

        newNode.previous = currentNode.previous;
        newNode.previous.next = newNode;
        newNode.next = currentNode;
        newNode.next.previous = newNode;
        size++;
    }

    /**
     * Helper method used for getting the Node at a specified index in the list.
     *
     * @param i The index of the Node to retrieve.
     * @return The Node at the given index.
     */
    private Node getNodeAtIndex(int i) {
        Node currentNode;
        if (i > size - 1 || i < 0) {
            throw new IndexOutOfBoundsException();
        }

        // To allow for faster list traversal, we can traverse from the head or the tail
        // based on which one the given index is closest to.
        if (i < this.size / 2) {
            currentNode = head.next;
            int currentIndex = 0;

            while (currentIndex != i) {
                currentNode = currentNode.next;
                currentIndex++;
            }
        } else {
            currentNode = tail.previous;
            int currentIndex = this.size - 1;

            while (currentIndex != i) {
                currentNode = currentNode.previous;
                currentIndex--;
            }
        }

        return currentNode;
    }

    /**
     * Use to get the value in the last at the given index.
     *
     * @param i The index to get the value from.
     * @return
     */
    public T get(int i) {
        if (i > size - 1 || i < 0) {
            throw new IndexOutOfBoundsException();
        }
        return getNodeAtIndex(i).data;
    }

    /**
     * Sets the data of the value at the given index.
     *
     * @param i
     * @param data
     */
    public void set(int i, T data) {
        getNodeAtIndex(i).data = data;
    }

    /**
     * Removes the Node at the given index from the list. If there is no longer
     * anything referencing the object, JVM garbage collection will git rid of
     * it.
     *
     * @param i The index of the Node to remove.0
     */
    public void remove(int i) {
        if (i > size - 1 || i < 0) {
            throw new IndexOutOfBoundsException();
        }

        Node removeMe = getNodeAtIndex(i);
        removeMe.previous.next = removeMe.next;
        removeMe.next.previous = removeMe.previous;
        size--;
    }

    /**
     * @return The number of values in the list
     */
    public int size() {
        return this.size;
    }

    /**
     * @return True if the list is empty, false if not.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        Node currentNode = head.next;

        while (currentNode != tail) {
            sb.append(currentNode.data.toString());
            if (currentNode.next != tail) {
                sb.append(", ");
            }
            currentNode = currentNode.next;
        }

        return sb.toString();
    }

    /**
     * For creating the nodes of a DoublyLinkedList
     */
    private class Node {

        T data;
        Node next;
        Node previous;

        Node() {
        }

        Node(T data) {
            this.data = data;
        }
    }

}
