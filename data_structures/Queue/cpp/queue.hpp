/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * use the abstraction of linked lists
 * to implement the functionality of queues
 * 
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include <iostream>
using namespace std;


namespace cs202
{
    template<class T>
class queue;    
template<class T>
class listnode{
    friend class queue<T>;
    private:
            T data;
            listnode *link;    
};
  template <class T>
    class queue
    {
           private:
            listnode<T> *fron;
            listnode<T> *last;
                int len;

      public:
        /*
         * Constructs a new queue.
         */
        queue();
        void print();
        /*
         * Pushes t to at the back of the queue.
         */
        void push(const T& t);
        /*
         * Returns the element at the front of the queue.
         * Also removes the front element from the queue.
         */
        T pop();
        /*
         * Returns the element at the front of the queue.
         * Does not remove the front element.
         */
        T front();
        /*
         * Returns the number of elements currently in the queue.
         */
        inline int size();
        /*
         * Returns a boolean indicating whether the queue is empty or not.
         */
        inline bool empty();
        /*
         * Destructor
         * Fress the memory occupied by the queue elements.
         */
        ~queue();
    };
            template<class T>
    void queue<T>::print()
    {
         listnode<T> *tmp=fron;
        while ( tmp!= NULL ) 
       
        {   
            cout<<tmp->data<<endl;
            tmp = tmp->link;
        }
    }


        template<class T>
    queue<T>::queue()
    {
        fron=NULL;
        last=NULL;
        len=0;
    }

    template<class T>
    void queue<T>::push(const T& t)
      {

listnode<T>* newnode=new listnode<T>();
        newnode->data=t;
        newnode->link=NULL;
         listnode<T> *tmp = fron;
    if ( tmp != NULL ) {

        last->link=newnode;
        last=newnode;
    
    len++;
    }
    else {
    fron = last = newnode;
    len++;
    }

      }  
        

        template<class T>
    T queue<T>::pop()
        {

            listnode<T> *tmp;
            T a= fron->data;
           tmp = fron->link;
            delete fron;
            fron=tmp;
            len--;
            return a;
        }
        template<class T>
    T queue<T>::front()
        {return fron->data;}

        template<class T>
    inline int queue<T>::size()
        {return len;}

        template<class T>
        inline bool queue<T>::empty()
        {
            if(len>0) return false;
            return true;

        }

        template<class T>
        queue<T>::~queue()
        {

        listnode<T> *tmp;
        while (fron) 
       
        {   tmp = fron->link;
            delete fron;
            fron=tmp;
        }

        }

}
#endif