from __future__ import print_function


class LinkedList:
    class Node:
        next_node = None
        data = None

        def compare_to(self, node):
            return node.data == self.data

        def __init__(self, data, next_node):
            self.data = data
            self.next_node = next_node


    class NoSuchNodeException(Exception):
        pass


    head = None
    list_size = 0

    def __init__(self):
        pass


    def size(self):
        """
        This methods returns the size of the linked list.
        :return: The size of the linked list. That is to say; the amount of elements in the linked list.
        """
        return self.list_size


    def is_empty(self):
        """
        This methods determines whether the list is empty, which means it holds no values.
        :return: True if the list is empty; False otherwise.
        """
        return self.list_size == 0


    def get_first(self):
        """
        This method returns the first element of the list.
        :return: The first element of the list.
        """
        if self.is_empty():
            raise self.NoSuchNodeException()

        return self.head.data


    def getNode(self, i):
        """
        This method takes an index and finds the node residing at the given index.
        Raises an NoSuchNodeException() if there is no such element.
        :param i: The index of the node.
        :return: The ith node of the list.
        """
        if i < 0 or i > self.list_size - 1:
            raise self.NoSuchNodeException()

        current = 0
        p = self.head

        while current < i:
            p = p.next_node
            current += 1

        return p


    def add_first(self, data):
        """
        This method adds a node to the front of the list.
        :param data: The data of the node to add.
        """

        node = self.Node(data, self.head)
        self.head = node

        self.list_size += 1


    def add_last(self, data):
        """
        This method adds a node to the back of the list.
        :param data: The data of the node to add.
        """
        node = self.Node(data, None)

        if self.is_empty():
            self.head = node
        else:
            tail = self.getNode(self.list_size - 1)
            tail.next_node = node

        self.list_size += 1


    def remove_first(self):
        """
        This method removes the first element of the list.
        :return: The value of the first element.
        """
        if self.is_empty():
            raise self.NoSuchNodeException()

        tmp_val = self.head.data
        self.head = self.head.next_node
        self.list_size -= 1
        return tmp_val


    def remove_last(self):
        """
        This method removes the last element of the list.
        :return: The value of the removed element.
        """
        if self.is_empty():
            raise self.NoSuchNodeException()

        tail = self.getNode(self.list_size - 1)
        tail_data = tail.data

        if self.list_size == 1:
            self.head = None
        else:
            before_tail = self.getNode(self.list_size - 2)
            before_tail.next_node = None

        self.list_size -= 1

        return tail_data


    def print_list(self):
        """
        This method prints a list which a newline after each element.
        """
        p = self.head
        i = 0

        while i < self.size():
            print(p.data)
            i += 1
            p = p.next_node




