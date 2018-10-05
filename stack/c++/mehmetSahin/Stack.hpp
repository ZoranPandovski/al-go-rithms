//
//  Stack.hpp
//  This program creates the stack data structure implementation using pointers.
//
//  Created by Mehmet Sahin on 10/2/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>

template <class T>
struct Node {
    T info;
    Node* next;
    Node(T i): info(i), next(nullptr) {};
};

template <class T>
class Stack {
    
private:
    Node<T>* head; // a pointer to top node
    
public:
    Stack(); // default constructor
    Stack(const Stack<T> &other); // copy constructor
    ~Stack(); // destructor
    
    /**
     * Overloaded assignment operator to copy other object to this object
     * @param other is a reference to Stack<T> object
     */
    void  operator=(const Stack<T> &other);
    
    /**
     * Copy function to help copy constructor and (=) operator
     * @param other is a reference to Stack<T> object
     */
    void copy(const Stack<T> &other);
    
    /**
     * Is the stack empty?
     * @return a bool
     */
    bool IsEmpty();
    
    /**
     * Makes the stack empty
     */
    void MakeEmpty();
    
    /**
     * Get the item on top of the stack
     * @return a T type item
     */
    T Top();
    
    /**
     * Deletes the top item in the stack
     */
    void Pop();
    
    /**
     * Push given item to top of the stack
     * @param item is a T type.
     */
    void Push(T item);
    
};

#endif /* Stack_hpp */
