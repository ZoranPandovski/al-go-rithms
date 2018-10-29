#include<bits/stdc++.h> 
  
using namespace std; 

//Change this to set the size of the stack you want.
#define MAX 1000 
  
class Stack 
{ 
    int top; 
public: 
    int a[MAX];  
    Stack()  
    {
        top = -1;
    } 
    bool push(int x); 
    int pop(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(int x) 
{ 
    if (top >= (MAX-1)) 
    { 
        cout << "Stack Overflow, Please pop some values first."; 
        return false; 
    } 
    else
    { 
        a[++top] = x;  
        return true; 
    } 
} 
  
int Stack::pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack Underflow, Please push some values first."; 
        return 0; 
    } 
    else
    { 
        int x = a[top--]; 
        return x; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
   
int main() 
{ 
    struct Stack s; 
    //Do whatever with the stack
    return 0; 
} 
