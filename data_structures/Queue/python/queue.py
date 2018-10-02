class Node(object):
    """Represents a Node in the queue """
    
    cargo = None
    next = None
    
    def __init__(self, cargo=None, next=None):
        self.cargo = cargo
        self.next = None

        
class Queue(object):
    """Represents a Queue (FIFO) datastructure """
    
    length = 0
    head = None
    last = None
    
    def __init__(self):
        """Constructor"""
        self.length = 0
        self.head = None
        self.last = None
        
    def is_empty(self):
        return self.length == 0
    
    def insert(self, cargo):
        node = Node(cargo)
        
        # If list is empty the new node goes first
        if self.head is None:
            self.head = node
            self.last = self.head
            
        # Insert at the end
        else:
            self.last.next = node
            self.last = self.last.next
            
        self.length += 1

        
    def remove(self):
        cargo = self.head.cargo
        self.head = self.head.next
        self.length -= 1
        
        return cargo
