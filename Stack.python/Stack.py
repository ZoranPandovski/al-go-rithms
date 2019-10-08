#Stack Implementation
# Size=100
def switch(ch):
    if(ch==1):
        push()
    elif(ch==2):
        pop()
    elif(ch==3):
        topview()
    elif(ch==4):
        stackview()
    elif(ch==5):
        exit(0)
    else:
        print("Invalid Choice")
def push():
    global top
    if(top>=99):
        print("Stack Overflow")
        
    else:
        top=top+1
        cont=int(input("Enter Number to be pushed into Stack: "))
        stack.append(cont)
        print(top)
        
    return()    
def pop():
    global top
    if(top==-1):
        print("Stack UnderFlow")
    else:
        top=top-1
    return()
def topview():
    global top
    print("Number of elements in Stack :",top+1)
    print("Top element: ",stack[top])
    return()
def stackview():
    global top
    for i in range(top,-1,-1):
        print(stack[i])
top=-1
stack=[]
print("Stack Of Size 100")
while(True):
       ch=int(input("Enter The Operation:\n1.Push\n2.Pop\n3.Top Element view\n4.stackview\n5.Exit\n"))

       switch(ch)
       

