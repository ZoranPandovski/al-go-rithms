/**
 * SinglyLinkedListImplementation
 */
class SinglyLinkedList(dat: Any) {

    private var head: Node? = Node(dat)
    var size: Int = 0

    fun addHead(dat: Any) {
        val temp = head
        head = Node(dat)
        head!!.next = temp
        size++
    }

    fun addTail(dat: Any) {
        var temp = head
        while (temp!!.next != null) {
            temp = temp.next
        }

        temp.next = Node(dat)
        size++
    }

    fun addAtIndex(index: Int, dat: Any) {
        var temp = head
        val holder: Node?
        var i = 0
        while (i < index - 1 && temp!!.next != null) {
            temp = temp.next
            i++
        }
        holder = temp!!.next
        temp.next = Node(dat)
        temp.next!!.next = holder
        size++
    }

    fun deleteAtIndex(index: Int) {
        var temp = head
        var i = 0
        while (i < index - 1 && temp!!.next != null) {
            temp = temp.next
            i++
        }
        temp!!.next = temp.next!!.next
        size--
    }

    fun find(n: Node): Int {
        var t = head
        var index = 0
        while (t !== n) {
            index++
            t = t!!.next
        }
        return index
    }

    fun find(index: Int): Node? {
        var temp = head
        for (i in 0 until index) {
            temp = temp!!.next
        }
        return temp
    }

    fun printList() {
        var temp = head
        while (temp != null) {
            println(temp.data)
            temp = temp.next
        }
    }

    inner class Node(val data: Any) {
        //Declare class variables
        var next: Node? = null
    }
}

/**
 * Testing SinglyLinkedList
 */
class TestSinglyLinkedList{
    companion object {

        @JvmStatic
        fun main(args: Array<String>) {
            val ll = SinglyLinkedList(10)
            ll.addHead(11)
            ll.addHead(12)
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