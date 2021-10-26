//
//  Stack.cpp
//
//  Created by Mehmet Sahin on 10/2/18.
//  Copyright © 2018 Mehmet Sahin. All rights reserved.
//

#include "Stack.hpp"

template <class T>
Stack<T>:: Stack()
{
    head = nullptr;
}

template <class T>
Stack<T>:: Stack(const Stack<T> &other)
{
    copy(other);
}

template <class T>
Stack<T>:: ~Stack()
{
    MakeEmpty();
}

template <class T>
void  Stack<T>:: operator=(const Stack<T> &other)
{
    if (head) {
        MakeEmpty();
    }
    copy(other);
}

template <class T>
void Stack<T>:: copy(const Stack<T> &other)
{
    if (!other.IsEmpty()) {
        head = new Node<T>(head->info);
        Node<T>* pother = other.head->next;
        Node<T>* pthis = head;
        
        while (pother) {
            pthis->next = new Node<T>(pother->info);
            pthis = pthis->next;
            pother = pother->next;
        }
    } else {
        throw std::string("Stack is empty");
    }
}

template <class T>
bool Stack<T>:: IsEmpty()
{
    return (head == nullptr);
}

template <class T>
void Stack<T>:: MakeEmpty()
{
    while (!IsEmpty()) {
        Node<T>* p = head;
        head = head->next;
        delete p;
    }
}

template <class T>
T Stack<T>:: Top()
{
    if (!IsEmpty()) {
        return head->info;
    } else {
        throw -1;
    }
}


template <class T>
void Stack<T>:: Pop()
{
    if (!IsEmpty()) {
        Node<T>* p = head; // 1
        head = head->next;
        delete p;
    } else {
        throw std::string("Stack is empty");
    }
}


template <class T>
void Stack<T>:: Push(T item)
{
    Node<T>* temp = new Node<T>(item);
    temp->next = head;
    head = temp;
}

