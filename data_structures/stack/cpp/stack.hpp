/* 
 * stack.hpp
 * 
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 * 
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
using namespace std;

namespace cs202
{

        template<class T>
        class stack;    
        template<class T>
        class listnode
        {
            friend class stack<T>;
            private:
            T data;
            listnode *link;    
        };

    template<typename T>
    class stack
    {
            private:
            listnode<T> *topm;
                int len;

      public:
        /*
         * Constructs a new stack.
         */
        stack();
        /*
         * Pushes t to on the top of the stack.
         */
        void push(const T& t);
        /*
         * Returns the element at the top of the stack.
         * Also removes the top element from the stack.
         */
        T pop();
        /*
         * Returns the element at the top of the stack.
         * Does not remove the top element.
         */
        T top();
        /*
         * Returns the number of elements currently in the stack.
         */
        void print();

        int size();
        /*
         * Returns a boolean indicating whether the stack is empty or not.
         */
        inline bool empty();
        /*
         * Destructor
         * Fress the memory occupied by the stack elements.
         */
        ~stack();
    };

        template<class T>
    void stack<T>::print()
    {
         listnode<T> *tmp=topm;
        while ( tmp!= NULL ) 
       
        {   
            cout<<tmp->data<<endl;
            tmp = tmp->link;
        }
    }

        template<class T>
        stack<T>::stack()
        {
            topm=NULL;
            len=0;
        }

        template<class T>
        void stack<T>::push(const T& t)
        {
                    listnode<T>* newnode=new listnode<T>();
        newnode->data=t;
        newnode->link=NULL;
         listnode<T> *tmp = topm;
         topm=newnode;
         topm->link=tmp;
         len++;

        }
        
        template<class T>
        T stack<T>::pop()
        {
            listnode<T> *tmp;
            T a= topm->data;
            tmp = topm->link;
            delete topm;
            topm=tmp;
            len--;
            return a;

        }
        
        template<class T>
        T stack<T>::top()
        {
            return topm->data;
        }
        
        template<class T>
        int stack<T>::size()
        {
            return len;
        }
        
        template<class T>
        inline bool stack<T>::empty()
        {
            if(len>0) return false;
            return true;
        }

        template<class T>
        stack<T>::~stack()
        {
        listnode<T> *tmp;
        while (topm) 
        {   tmp = topm->link;
            delete topm;
            topm=tmp;
        }

        }
}

#endif