# Source
---

[https://www.youtube.com/watch?v=h-HBipu_1P0&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_](https://www.youtube.com/watch?v=h-HBipu_1P0&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)  

# Notes
---


#### Definition-

Pointers are variables that store the address of another variable.  

![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/introduction%20to%20pointers/1.png)
![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/introduction%20to%20pointers/2.png)

  

int a=10; **//a is a variable**  
int *p;  **//p is a pointer variable**  
p=&a; **//address of a stored in p**

print *p   //***p means Value at address p: dereferencing**  

## **Pointer Arithmetic**


* * *
![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/introduction%20to%20pointers/3.png)


The **value of p+1 is 4 more than the value of p**  **because the pointer is of integer types that takes 4** byte in the memory.  

If the pointer type was character pointer then the value of p+1 would be 1 more than the value of p.   

value at address p+1 is some garbage value. because we didn't allocate any integer value at address p+1.
