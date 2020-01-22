'''This code is written MTH Junaidi github: Miranjunaidi on 26th Oct 2019 at 7:15 PM IST'''

#POP function removes the last element of the list
def pop(stack):
    del stack[-1]
    return stack
#push function adds a new number num to the list at the end. 
def push(stack,num):
    stack.append(num)
    return stack
#print function prints all the element of the stack sequestially
def prints(stack):
    for i in stack:
        print(i,end = " ")
    print("")
#This is where the main funtions start

print("\n welcome, a new empty stack is created. \n press index numbers to do the opertations \n")
stack = []
a=0
while a!=4:
    print(" 1.push \n 2.pop \n 3.see the stack \n 4.quit")
    a = int(input())
    if a == 1:
        num = int(input("Enter the number you want to push"))
        push(stack, num)
    elif a == 2:
        pop(stack)
    elif a==3:
        prints(stack)
    elif a>4 or a<0:
        print("enter a valid operation")