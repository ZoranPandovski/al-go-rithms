class Node(object):
    def __init__(self, value):
        self.value=value
        self.next=None
        self.prev=None

class List(object):
    def __init__(self):
        self.head=None
        self.tail=None

    def insert(self,n,x):
        #Not actually perfect: how do we prepend to an existing list?
        if n!=None:
            x.next=n.next
            n.next=x
            x.prev=n
            if x.next!=None:
                x.next.prev=x
        if self.head==None:
            self.head=self.tail=x
            x.prev=x.next=None
        elif self.tail==n:
            self.tail=x

    def display(self):
        values=[]
        n=self.head
        while n!=None:
            values.append(str(n.value))
            n=n.next
        print ("List: ",",".join(values))

    def removeNode(self, node_delete):
        """This function recieves a node and is responsible
        for deleting it and reconecting the nodes before and after it."""
        prev = node_delete.prev
        nxt = node_delete.next

        if(prev != None):
            prev.next = nxt
        if(nxt != None):
            nxt.prev = prev

    def removeRepeated(self):
        """this function uses a nested while loop to find
        the repeated values. every time one is found the method
        removeNode is called to remove the repeated node"""
        aux = self.head

        while(aux != None):
            aux2 = aux.next #needs to be .next otherwise it will compare the value on aux with itself

            while (aux2 != None):

                if(aux2.value == aux.value):
                    self.removeNode(aux2)
                aux2 = aux2.next

            aux = aux.next
        return self

    def toNativeList(self):
        """This method creates a list with all the nodes
        to use in the unit testing"""
        n = self.head
        out = []
        while(n != None):
            out += [n.value]
            n = n.next
        return out
