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


"""
PROBLEM:
Trapping Rainwater Problem states that we need to find the maximum units of rainwater that can be stored between 
the bars of different sizes where the sizes of bars are given as an input.
Example: given input: [3,2,0,2,0,4] ---> answer: 8


                       0
             0 x x x x 0
             0 0 x 0 x 0
             0 0 x 0 x 0
    -----------------------------------

    Here 0 represen the blocks and number of x is the total area where water can be trapped.

"""


#driver code
input_height = [3,2,0,2,0,4] #input height
water_above_block = [] #water above each block i
max_left_height = Stack() #maximum height to the left of each block i
max_right_height = Stack([]) #maximum height to right of each black i
sum_water_trapped = 0 #sum of the area of trapped water


#store all the maximum left height of block i in stack
for i in range(len(input_height)):
    if max_left_height.empty(): 
        #if stack empty append block height
        max_left_height.push(input_height[i])
    else: 
        #if stack not empty append max(top, block height)
        max_left_height.push(max(max_left_height.top(),input_height[i]))

#store all the maximum right height of block i in stack
for i in range(len(input_height)-1,-1,-1): #note: reverse travesal
    if max_right_height.empty():
        #if stack empty append black height
        max_right_height.push(input_height[i])
    else: 
        #if stack not empty append max(top, block height)
        max_right_height.push(max(max_right_height.top(),input_height[i]))

max_right_height.rev()


#water above block = min(left height, right height) - input height
for i in range(len(input_height)):
    water_above_block.append(min(max_left_height.stack[i], max_right_height.stack[i]) - input_height[i])

#sum up water above each block
for i in range(len(water_above_block)):
    sum_water_trapped+=water_above_block[i]

print("Total area of trapped water: ", sum_water_trapped)

