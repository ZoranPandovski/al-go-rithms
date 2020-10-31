#-----------------------------------------------------------------------
# linkedqueue.py
#-----------------------------------------------------------------------

import stdio

# A Queue object is a first-in-first-out container.

class Queue:

    #-------------------------------------------------------------------

    # Construct Queue object self as an empty Queue object.

    def __init__(self):
        self._first = None  # Reference to first _Node
        self._last = None   # Reference to last _Node
        self._length = 0    # Number of items

    #-------------------------------------------------------------------

    # Return True if self is empty, and False otherwise.

    def isEmpty(self):
        return self._first is None

    #-------------------------------------------------------------------

    # Add item to the end of self.

    def enqueue(self, item):
        oldLast = self._last
        self._last = _Node(item, None)
        if self.isEmpty():
            self._first = self._last
        else:
            oldLast.next = self._last
        self._length += 1

    #-------------------------------------------------------------------

    # Remove the first item of self and return it.

    def dequeue(self):
        item = self._first.item
        self._first = self._first.next
        if self.isEmpty():
            self._last = None
        self._length -= 1
        return item

    #-------------------------------------------------------------------

    # Return the number of items in self.

    def __len__(self):
        return self._length

    #-------------------------------------------------------------------

    # Return a string representation of self.

    def __str__(self):
        s = ''
        cur = self._first
        while cur is not None:
            s += str(cur.item) + ' '
            cur = cur.next
        return s

#----------------------------------------------------------------------

# A _Node object references an item and a next _Node object.
# A Queue object is composed of _Node objects.

class _Node:
    def __init__(self, item, next):
        self.item = item  # Reference to an item
        self.next = next  # Reference to the next _Node object

#-----------------------------------------------------------------------

# Test the Queue class by reading strings from standard input and
# enqueueing or dequeueing as indicated. A minus sign indicates dequeue
# (and write to standard output), and any other string indicates
# enqueue.

def main():
    queue = Queue()
    while not stdio.isEmpty():
        item = stdio.readString()
        if item != '-':
            queue.enqueue(item)
        else:
            stdio.write(queue.dequeue())
            stdio.write(' ')
    stdio.writeln()

if __name__ == '__main__':
    main()