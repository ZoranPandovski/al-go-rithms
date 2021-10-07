from collections import deque
 
 
# Insert the given key into the sorted stack while maintaining its sorted order.
# This is similar to the recursive insertion sort routine
def sortedInsert(stack, key):
 
    # base case: if the stack is empty or
    # the key is greater than all elements in the stack
    if not stack or key > stack[-1]:
        stack.append(key)
        return
 
    ''' We reach here when the key is smaller than the top element '''
 
    # remove the top element
    top = stack.pop()
 
    # recur for the remaining elements in the stack
    sortedInsert(stack, key)
 
    # insert the popped element back into the stack
    stack.append(top)
 
 
# Recursive method to sort a stack
def sortStack(stack):
 
    # base case: stack is empty
    if not stack:
        return
 
    # remove the top element
    top = stack.pop()
 
    # recur for the remaining elements in the stack
    sortStack(stack)
 
    # insert the popped element back into the sorted stack
    sortedInsert(stack, top)
 
 
if __name__ == '__main__':
 
    A = [5, -2, 9, -7, 3]
 
    stack = deque(A)
 
    print("Stack before sorting:", list(stack))
    sortStack(stack)
    print("Stack after sorting:", list(stack))