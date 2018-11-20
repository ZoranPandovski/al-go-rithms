class DoublyLinkedList<T> {

    private val head: Node
    private val tail: Node
    private var size = 0

    val isEmpty: Boolean
        get() = size == 0

    init {
        this.head = Node()
        this.tail = Node()
        this.size = 0

        this.head.next = tail
        this.tail.previous = head
    }

    fun addTail(data: T) {
        val newNode = Node(data)
        val temp = tail.previous

        temp!!.next = newNode
        newNode.previous = temp
        newNode.next = tail
        tail.previous = newNode
        size++
    }

    fun addHead(data: T) {
        val newNode = Node(data)
        val temp = head.next

        head.next = newNode
        newNode.previous = head
        temp!!.previous = newNode
        newNode.next = temp
        size++
    }

    fun addAtIndex(i: Int, data: T) {
        if (i > size || i < 0) {
            throw IndexOutOfBoundsException()
        } else if (this.isEmpty || i == 0) {
            this.addHead(data)
            return
        } else if (i == size) {
            this.addTail(data)
            return
        }

        val currentNode = getNodeAtIndex(i)
        val newNode = Node(data)

        newNode.previous = currentNode!!.previous
        newNode.previous!!.next = newNode
        newNode.next = currentNode
        newNode.next!!.previous = newNode
        size++
    }

    private fun getNodeAtIndex(i: Int): Node? {
        var currentNode: Node?
        if (i > size - 1 || i < 0) {
            throw IndexOutOfBoundsException()
        }

        // To allow for faster list traversal, we can traverse from the head or the tail
        // based on which one the given index is closest to.
        if (i < this.size / 2) {
            currentNode = head.next
            var currentIndex = 0

            while (currentIndex != i) {
                currentNode = currentNode!!.next
                currentIndex++
            }
        } else {
            currentNode = tail.previous
            var currentIndex = this.size - 1

            while (currentIndex != i) {
                currentNode = currentNode!!.previous
                currentIndex--
            }
        }

        return currentNode
    }

    operator fun get(i: Int): T {
        if (i > size - 1 || i < 0) {
            throw IndexOutOfBoundsException()
        }
        return getNodeAtIndex(i)!!.data!!
    }

    operator fun set(i: Int, data: T) {
        getNodeAtIndex(i)!!.data = data
    }

    fun deleteAtIndex(i: Int) {
        if (i > size - 1 || i < 0) {
            throw IndexOutOfBoundsException()
        }

        val removeMe = getNodeAtIndex(i)
        removeMe!!.previous!!.next = removeMe.next
        removeMe.next!!.previous = removeMe.previous
        size--
    }

    fun size(): Int {
        return this.size
    }

    override fun toString(): String {
        val sb = StringBuilder()

        var currentNode = head.next

        while (currentNode !== tail) {
            sb.append(currentNode!!.data.toString())
            if (currentNode.next !== tail) {
                sb.append(", ")
            }
            currentNode = currentNode.next
        }

        return sb.toString()
    }

    fun printList() {
        var temp: Node? = head
        while (temp != null) {
            if(temp.data != null)
                println(temp.data)
            temp = temp.next
        }
    }

    private inner class Node(internal var data: T? = null) {
        internal var next: Node? = null
        internal var previous: Node? = null
    }
}

class DoublyLinkedListTest{
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            val ll = DoublyLinkedList<Int>()
            ll.addHead(11)
            ll.addTail(12)
            ll.addHead(13)
            ll.addTail(8)
            ll.addTail(7)
            ll.addAtIndex(4, 9)
            ll.addAtIndex(4, 9)
            ll.deleteAtIndex(4)
            ll.printList()
        }
    }
}
