# Author: AlexBanks97
# Purpose: LIFO Stack implementation using python array.
# Date: October 15th 2017

class Stack(object):
    def __init__(self):
        # Initialize stack as empty array
        self.stack = []

    # Return and remove the last element of the stack array.
    def pop(self):
        # If the stack is not empty, pop.
        if len(self.stack) > 0:
            return self.stack.pop() 

    # Add an element to the end of the stack array.
    def push(self, element):
        self.stack.append(element)

    # Return the last element of the stack array (without removing it).
    def peek(self):
        return self.stack[-1]