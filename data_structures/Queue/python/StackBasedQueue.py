class Stack:
     def __init__(self):
         self.items = []

     def isEmpty(self):
         return self.items == []

     def push(self, item):
         self.items.append(item)

     def pop(self):
         return self.items.pop()

     def peek(self):
         return self.items[len(self.items)-1]

     def size(self):
         return len(self.items)
        
class StackBasedQueue:
    def __init__(self):
        self.stack1 = Stack() #actual queue
        self.stack2 = Stack() #container stack
    def push(self, ref_stack, elem):
        ref_stack.push(elem)
    def pop(self, ref_stack):
        if(ref_stack.isEmpty()):
            print("Stack Overflow")
            return
        return ref_stack.pop()
    def enqueue(self, elem):
        self.stack1.push(elem)
        return self.stack1
    def dequeue(self):
        tmp = ''
        if(self.stack1.isEmpty() and self.stack2.isEmpty()):
            print("Queue is empty")
            return
        if(self.stack2.isEmpty()):
            while(not self.stack1.isEmpty()):
                tmp = self.pop(self.stack1)
                self.push(self.stack2, tmp)
        tmp = self.pop(self.stack2)
        return tmp

class singleStackbasedqueue:
    def __init__(self):
        self.queue = Stack()
        
    def enqueue(self, elem):
        self.queue.push(elem)
        
    def dequeue(self):
        if(self.queue.isEmpty()):
            print("Queue is empty")
            return
        if(self.queue.size() == 1):
            return self.queue.pop()
        tmp = self.queue.pop()
        self.dequeue()
        self.queue.push(tmp)
            
    def displayQueue(self):
        while(not self.queue.isEmpty()):
            print(self.queue.pop())
            
        
def main():

    '''
    queue = StackBasedQueue()
    queue.enqueue(1)
    queue.enqueue(2)

    print(queue.dequeue())
    print(queue.dequeue())
    '''
    SingleStackqueue = singleStackbasedqueue()
    SingleStackqueue.enqueue(1)
    SingleStackqueue.enqueue(2)
    SingleStackqueue.dequeue()
    SingleStackqueue.displayQueue()
    #print(SingleStackqueue.dequeue())
    
if __name__ == '__main__':
    main()
    
