/** <copyright github.com/jrezzende> */
#ifndef STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <stdexcept>  // c++ exceptions

namespace structures {

/**CLASS LINKED QUEUE*/

template<typename T>
class LinkedQueue {
 public:
    LinkedQueue(); // DEFAULT CONSTRUCTOR
    ~LinkedQueue(); // DESTRUCTOR
    void clear();  // EMPTY THE QUEUE
    void enqueue(const T& data);  // PUSHES A NODE AT THE END OF THE QUEUE
    T dequeue();  // REMOVES AND RETURNS THE FIRST NODE OF THE QUEUE
    T& front() const;  // FIRST NODE'S DATA
    T& back() const;  // LAST NODE'S DATA
    bool empty() const;  // TRUE IF QUEUE IS EMPTY
    std::size_t size() const;  // ACTUAL SIZE OF THE QUEUE

 private:
    class Node {
     public:
        explicit Node(const T& data): data_{data} {}
        Node(const T& data, Node* next): data_{data}, next_{next} {}

        T& data() {  // getter: info
            return data_;
        }
        const T& data() const {  // const-getter: info
            return data_;
        }
        Node* next() {  // getter: next
            return next_;
        }
        const Node* next() const {  // const-getter: next
            return next_;
        }

        void next(Node* next) {  // setter: next
            next_= next;
        }

     private:
        T data_;
        Node* next_;
    };

 private:
    Node* head;  // head node
    Node* tail;  // tail node
    std::size_t size_;  // size
};

}  // namespace structures

#endif

    //  using namespace structures

template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    head= nullptr;
    tail= nullptr;
    size_= 0;
}

template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template<typename T>
void structures::LinkedQueue<T>::clear() {
    while (size_)
        dequeue();
}

template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    if (empty()) {
        head= new Node(data);
        tail= head;
    } else {
        Node* new_node= new Node(data);
        tail->next(new_node);
        tail= new_node;
    }
    size_++;
}

template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    if (empty()) {
        throw std::out_of_range("LIST IS EMPTY!");
    } else if (size_ == 1) {
        Node* current;
        current= head;
        T temp= current->data();
        delete current;
        head= nullptr;
        tail= nullptr;
        size_--;
        return temp;
    } else {
        Node* current= head;
        T temp= current->data();
        head= current->next();
        delete current;
        size_--;
        return temp;
    }
}

template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (empty())
        throw std::out_of_range("LISTA IS EMPTY!");
    return head->data();
}

/**RETURNS THE DATA OF THE LAST NODE*/
template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (empty())
        throw std::out_of_range("LISTA IS EMPTY!");
    return tail->data();
}

/**TRUE IF THE QUEUE IS EMPTY*/
template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    return size_ == 0;
}

/**CLEARS THE QUEUE*/
template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}
