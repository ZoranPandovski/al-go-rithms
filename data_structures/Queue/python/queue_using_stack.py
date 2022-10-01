# Using the given stack implementation
# Done in the directory data_structures/Stack/Python/Stack.py
class Stack(object):
    
    def __init__(self, limit = 10):
        # Initialize stack as empty array
        self.stack = []
        self.limit = limit
    
    # Return and remove the last element of the stack array.
    def pop(self):
        # If the stack is not empty, pop.
        if len(self.stack) > 0:
            return self.stack.pop() 

    # Add an element to the end of the stack array.
    def push(self, element):
        if len(self.stack)<self.limit:
            self.stack.append(element)

    # Return the last element of the stack array (without removing it).
    def peek(self):
        return self.stack[-1]
    
    # Return whether the stack is empty or not.
    def __bool__(self):
        return len(self.stack) != 0
    
    # Return the size of the stack
    def size(self):
        return len(self.stack)
    
    # Return a string representation for the stack
    def __str__(self):
        return str(self.stack) 
    
    # Return whether the stack is empty or not.
    def is_empty(self):
        return len(self.stack) == 0

class Queue:
    """Represents a Queue (FIFO) data structure"""

    def __init__(self, limit = 10):
        self.primary_stack = Stack(limit)
        self.secondary_stack = Stack(limit)
        self.limit = limit

    def __bool__(self):
        return bool(self.primary_stack)

    def __str__(self):
        return str(self.primary_stack)

    def enqueue(self, data):
        """Add an element to the end of queue."""
        while not self.primary_stack.is_empty():
            self.secondary_stack.push(self.primary_stack.pop())

        self.primary_stack.push(data)

        while not self.secondary_stack.is_empty():
            self.primary_stack.push(self.secondary_stack.pop())

    def dequeue(self):
        """Remove and element from the front of queue."""
        return self.primary_stack.pop()

    def front(self):
        """Return the value of the element in front of the queue."""
        return self.primary_stack.peek()

    def is_empty(self):
        """Check if the queue is empty."""
        return not bool(self.primary_stack)

    def is_full(self):
        return self.size() == self.limit

    def size(self):
        """Return the size of the queue."""
        return self.primary_stack.size()

    def __contains__(self, data: int):
        """Check if item is in the queue."""
        return data in self.primary_stack


def test_queue() -> None:
    queue = Queue(10)
    assert queue.is_empty() is True
    assert queue.is_full() is False
    assert bool(queue) is False
    assert str(queue) == "[]"

    try:
        queue.dequeue()
        assert False  # This should not happen
    except:
        assert True  # This should happen

    try:
        queue.front()
        assert False  # This should not happen
    except IndexError:
        assert True  # This should happen

    for i in range(10):
        assert queue.size() == i
        queue.enqueue(i)

    assert queue.is_full() is True
    assert queue.is_empty() is False
    assert queue.dequeue() == 0
    assert queue.front() == 1

    queue.enqueue(100)
    assert str(queue) == str([100, 9, 8, 7, 6, 5, 4, 3, 2, 1])

    try:
        queue.enqueue(0)
        assert False  # This should not happen
    except:
        assert True  # This should happen

    assert queue.is_empty() is False
    assert queue.size() == 10


if __name__ == "__main__":
    test_queue()