class Stack:
    def __init__(self, stack = []):
            """ initialises the stack:
               1. if a list of elements is passed --> initailises the stack with list
               2. if no parameter is passed --> initailises the stack with empty list
            """
            self.stack = stack
    def size(self):
            """ return the size of the stack
            """
            return len(self.stack)
    
    def empty(self):
            """
            checks if the stack is empty and returns a boolean value
            """
            if self.size() == 0:
                return True
            return False
    
    def top(self):
            """
            returns the top element of the stack
            pre-condition: stack should not be empty
            returns -1 in case the stack is empty
            """
            if not self.empty():
                return self.stack[self.size()-1]
            return -1
    
    def push(self,element):
            """ push in stack is used to add element on top of the stack
            """
            self.stack.append(element)
    
    def pop(self):
            """
              pop in stack is used to remove element from the top.
              pre-condition: stack should be empty
              In case of empty stack return -1
            """
            removed_element = self.stack.pop()
            return removed_element
    
    
    def rev(self):
            """
            This  method will reverse the stack that is it will bring the bottom element to top and vice versa.
            pre-conditon: stack should not empty
            **This method is added to suit the problem(not a part of traditional stack implementation)**
            """

            if self.size!=0:
                self.stack.reverse()



'''
PROBLEM:
for given list we have to replace the element with the greatest element closest to it's right otherwise replace it with -1.
example:
    given : [1,5,3,4]
    for the first element 1(index 0) 5, 3,4 are greater but we replace it with 5 which is the greatest number closest to it.
    likewise for 5(index 1) 3,4 are not greater than 5 so it will be replaced by -1  and so on..

    answer: [5,-1,4,-1]
'''






#driver code
given_list = [1,5,3,4] #initally give list of element
ans_list = [] #initalised answer list
comparison_stack= Stack() #empty stack for comparison

for i in range(len(given_list)-1,-1,-1): #taking the list is reverse order

    if comparison_stack.empty()==True:
        ans_list.append(-1)  #empty stack symbolises no element is greater  so append  -1
    else:
        if comparison_stack.top() > given_list[i]: # check if top is greater 
            ans_list.append(comparison_stack.top()) # top is greater than append top into ans
        else:
            while ((not comparison_stack.empty()) and comparison_stack.top()<=given_list[i]):
                # pop until we reach an element greater than given element 
                # or till the stack is exhausted
                comparison_stack.pop() 
            if comparison_stack.empty():
                ans_list.append(-1) #append -1 if the stack is exhausted
            else:
                ans_list.append(comparison_stack.top()) #otherwise append the top element
    
    comparison_stack.push(given_list[i]) #append the element from the given_list into the stack for further comparisons


ans_list.reverse() #note: ans_list is present in revese form, so reverse it before printing out.
print("The given list: ", given_list)
print("-----Next Greatest Element(NGE)-----")
print("The NGE List: ", ans_list)
            
