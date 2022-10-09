
# creation of the node class make it contain the data ,next,prev
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

# creation of the main double linked list class


class DoubleLinkedList:
    def __init__(self):
        self.head = None  # the head is being created as soon as the classs is invoked

    def append(self, data):  # insertion or addition of the nodess
        new_node = Node(data)  # creation of the node
        if self.head is None:  # The list is checked wheater it is empty or not
            new_node.prev = None
            self.head = new_node
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = new_node
            new_node.prev = cur
            new_node.next = None

    def traverse(self):  # The tree is traversed and all the nodess are printed
        cur = self.head
        while cur:
            print(cur.data)
            cur = cur.next

    def remove(self):  # deletio of nodes
        if self.head == None:  # if empty is notified that it is empty
            print("Non node is present")
        else:
            cur = self.head
            while cur.next:
                prev = cur
                cur = cur.next
            prev.next = None
            # cur.next = None


# creation of the class and being invoked
ddlist = DoubleLinkedList()
ddlist.append(1)
ddlist.append(2)

ddlist.append(3)
ddlist.append(4)
ddlist.append(5)
ddlist.append(6)
ddlist.traverse()
ddlist.remove()
ddlist.traverse()
