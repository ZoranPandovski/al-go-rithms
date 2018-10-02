#### Pointer types, pointer arithmetic, void pointers and Pointer to Pointer
---

## Source:
---

**[https://www.youtube.com/watch?v=JTttg85xsbo&index=3&list=PL2_aWCzGMAwLZfp6LMUKI3cc7pgGsasm2_](https://www.youtube.com/watch?v=JTttg85xsbo&index=3&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)**

---


**NOTES**
---



**![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/pointer%20types/1.png)**
Because pointer type is integer and integer is 4 byte long so While printing *p (dereferencing p )the compiler looks at 4 bytes starting from address 200 and prints 1025. If the pointer type of p was character pointer (The size of character variable is 1 byte ) then it only looks at 1 byte and prints 1 (00000001) as the value of *p. 

So **pointer variables are strongly typed**.It means we need a pointer variable of particular type to store the address of variable of particular type.

**int***=&gt; to store the address of int variable.

**char***=&gt; to store the address of char variable.

**![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/pointer%20types/2.png)**
## Void Pointer / Generic pointer type
---
Void pointers are pointer variables which can store the address of variable of any data type. These pointers are also called Generic pointers.  

**Dereferencing** and **Arithmetic operations** are not possible for Void pointers.  

We use keyword **void** to declare a void pointer variable.  

Explicit typecasting is not important in case of void pointer.

**![Image](http://blog.ashutoshdwivedi.in/tutorials/pointers/pointer%20types/3.png)**
#### Thank you :)
##### This tutorial is prepared by me checkout my profile :
**My Wesbite**  **[![Awesome](https://awesome.re/badge.svg)](https://ashutoshdwivedi.in)**
