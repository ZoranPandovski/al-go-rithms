class LinkedListNode(object):
    
    def __init__(self, value):
        self.value = value
        self.nextnode = None


def cycle_check(node):
    
    marker1 = marker2 = node
    
    while marker2 != None and marker2.nextnode != None:
        marker1 = marker1.nextnode
        
        marker2 = marker2.nextnode.nextnode
        
        if marker1 == marker2:
            return True
        
    return False

if __name__ == '__main__':
    # CREATE CYCLE LIST
    a = LinkedListNode(1)
    b = LinkedListNode(2)
    c = LinkedListNode(3)

    a.nextnode = b
    b.nextnode = c
    c.nextnode = a # Cycle Here!


    # CREATE NON CYCLE LIST
    x = LinkedListNode(1)
    y = LinkedListNode(2)
    z = LinkedListNode(3)

    x.nextnode = y
    y.nextnode = z

    assert cycle_check(a) == True
    assert cycle_check(x) == False
