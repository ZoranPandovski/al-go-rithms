#include <iostream>
#include <cstdlib>

/***********************************************
Node to store data and to point to other nodes.
This queue is linked list based
************************************************/

template <class T>
struct Node {
    //stores a pointer to an additional node
    Node* next = NULL;
    //store data of any type
    T data;
};

/*****************************************************
This is the queue data structure class. Implementation
is below
******************************************************/
template <class T>
class Queue {
    public:
    //Intializes the Queue to be empty. Takes no parameters.
    Queue();
  
    //Destroys the queue safely upon deletion.
    ~Queue();

    //Parameters: Takes no parameters
    //Return Value: returns true if the queue is empty. Otherwise returns false 
    //preconditions: none
    //postconditions: queue is non modified, returns boolean testing 
    //if queue is empty
    bool isEmpty() const;

    //Parameters: Takes no parameters
    //Return Value: returns size of queue as an unsigned int
    //preconditions: none
    //postconditions: queue is non modified, returns integer signifing size
    unsigned int size() const;

    //Parameters: Takes no parameters
    //Return Value: returns front value of queue
    //preconditions: at least one item is available in queue. if not, error
    //will log to user and program will terminate
    //postconditions: queue is non modified, returns front item in queue, 
    //queue, error logged and program terminated if no items in queue
    T front() const;

    //Parameters: Takes a constant reference parameter of a user defined type
    //Return Value: returns void
    //preconditions: none
    //postconditions: queue is modified, contains one more item, queue size increase by
    //one. newEntry is now in back of queue.
    void push(const T& newEntry);

    //Parameters: Takes no parameters
    //Return Value: returns void
    //preconditions: at least one item is available in queue. if not, error
    //will log to user and program will terminate
    //postconditions: queue is modified, front item is removed from queue.
    //size decrements by one
    void pop();
    
    private:
    Node<T>* head;
    Node<T>* tail;
    int sizeOfQueue;
};

/*****************************************************
This is the queue data structure implementation.
******************************************************/
template <class T>
Queue<T>::Queue() {
    //head and tail set to null upon declaration
    //size is initialized to 0
    head = NULL;
    tail = NULL;
    sizeOfQueue = 0;
}

template <class T> 
Queue<T>::~Queue(){
    //declare a temp ptr to point to the head
    Node<T>* tempPtr = head;
    //increment through entire linked list, and
    //delete every item
    while (tempPtr != NULL) {
        head = head -> next;
        delete tempPtr;
        tempPtr = head;
    }
    //also sets tail to null and size to 0
    tail = NULL;
    sizeOfQueue = 0;
    return;
}

template <class T>
bool Queue<T>::isEmpty() const {
    //boolean to signify results test signifing if queue is
    //empty test
    bool isQueueEmpty = false;
    //if size is 0, test passed
    if (sizeOfQueue == 0) {
        isQueueEmpty = true;
    }
    return isQueueEmpty;
}

template <class T>
unsigned int Queue<T>::size() const {
    return sizeOfQueue;
}

template <class T>
void Queue<T>::push(const T& newEntry) {
    //Case 1: empty list, must add first head. Head is
    //same as tail, neither is NULL anymore.
    if (head == NULL) {
        head = new Node<T>;
        head -> data = newEntry;
        tail = head;
        head -> next = NULL;
    }
    //Case 2: head already exists, tail exists. Add
    //new item to tail with data newEntry.
    else {
        tail -> next = new Node<T>;
        tail = tail -> next;
        tail -> data = newEntry;
        tail -> next = NULL;
    }
    //make queue larger by 1
    sizeOfQueue += 1;
    return;
}

template <class T>
void Queue<T>::pop() {
    //Case 1: if queue is empty, log error to user and terminate program.
    //termination is for safety purposes, forcing user to use queue safely
    if (isEmpty()) {
        std::cerr << "Queue is empty, cannot remove item. \nProgram terminated." << std::endl;
        std::exit(1);
    }
    //Case 2: queue only has a head. Head is removed, head and tail are set to null.
    //size of queue is set to 0
    else if (head -> next == NULL) {
        //std::cout << "That Case" << std::endl;
        delete head;
        head = NULL;
        tail = NULL;
        sizeOfQueue = 0;
    }
    //Case 3: every other case. Head is removed, the next item is the new head.
    else {
        Node<T>* oldHead = head;
        head = head -> next;
        delete oldHead;
        sizeOfQueue -= 1;
    }
    return;
}

template <class T>
T Queue<T>::front() const {
    //if queue is empty, terminate program for safety purposes. Log error to user.
    if (isEmpty()) {
        std::cerr << "Queue is empty. No value in front of queue. \nProgram terminated." << std::endl;
        std::exit(1);
    } 
    //returns the data from the head
    return head->data;
}

//Macro defined to terminate program if test failed. Will give line number 
//so user can fix error
int logError (int line) {
    std::cerr << "Test failed, check error on line: [" << line << "]";
    std::cerr << "\nProgram terminated" << std::endl;
    exit(1);
}



/********************************************************
This is the main function, which tests the queue to make
sure it is working properly.
*********************************************************/
#define TESTFAILED() logError( __LINE__)

int main() {
    //*********************************************
    //Declare Queue object of type int for testing*
    //*********************************************
    Queue<int> test;
    //test queue should be empty, and the size should be 0.
    if (!test.isEmpty() || test.size() != 0) {
        TESTFAILED();
    }
    test.push(5);
    test.push(6);
    //Queue shouldnt be empty, should be size 2, with items {5,6} in Queue
    if (test.isEmpty() || test.size() != 2) {
        TESTFAILED();
    }
    if (test.front() != 5) {
        TESTFAILED();
    }
    test.pop();
    if (test.front() != 6) {
        TESTFAILED();
    }
    test.pop();
    //Queue should be empty with size 0
    if (!test.isEmpty() || test.size() != 0) {
        TESTFAILED();
    }
    test.push(1);
    test.push(2);
    test.pop();
    test.push(3);
    test.push(4);
    test.pop();
    test.push(5);
    test.push(6);
    test.pop();
    //queue should be non empty and of size 3
    if (test.isEmpty() || test.size() != 3) {
        TESTFAILED();
    }
    //queue should be {4,5,6}
    if (test.front() != 4) {
        TESTFAILED();
    }
    test.pop();
    //queue shoule be {5,6}
    if (test.front() != 5) {
        TESTFAILED();
    }
    test.pop();
    //queue should be {6}
    if (test.front() != 6) {
        TESTFAILED();
    }
    test.pop();
    //queue should be empty with size 0
    if (!test.isEmpty() || test.size() != 0) {
        TESTFAILED();
    }
    //tests the destructor of program for double delete and other common errors associated with
    //deallocating pointers properly
    for (int i = 0; i < 2; i++) {
        Queue<int> testTheDestructor;
        testTheDestructor.push(2);
    }
    //************************************************
    //Declare Queue object of type string for testing*
    //************************************************  
    Queue<std::string> stringTest;
    //test queue should be empty, and the size should be 0.
    if (!stringTest.isEmpty() || stringTest.size() != 0) {
        TESTFAILED();
    }
    stringTest.push("5");
    stringTest.push("6");
    //Queue shouldnt be empty, should be size 2, with items {5,6} in Queue
    if (stringTest.isEmpty() || stringTest.size() != 2) {
        TESTFAILED();
    }
    if (stringTest.front() != "5") {
        TESTFAILED();
    }
    stringTest.pop();
    if (stringTest.front() != "6") {
        TESTFAILED();
    }
    stringTest.pop();
    //Queue should be empty with size 0
    if (!stringTest.isEmpty() || stringTest.size() != 0) {
        TESTFAILED();
    }
    stringTest.push("1");
    stringTest.push("2");
    stringTest.pop();
    stringTest.push("3");
    stringTest.push("4");
    stringTest.pop();
    stringTest.push("5");
    stringTest.push("6");
    stringTest.pop();
    //queue should be non empty and of size 3
    if (stringTest.isEmpty() || stringTest.size() != 3) {
        TESTFAILED();
    }
    //queue should be {4,5,6}
    if (stringTest.front() != "4") {
       TESTFAILED();
    }
    stringTest.pop();
    //queue shoule be {5,6}
    if (stringTest.front() != "5") {
        TESTFAILED();
    }
    stringTest.pop();
    //queue should be {6}
    if (stringTest.front() != "6") {
        TESTFAILED();
    }
    stringTest.pop();
    //queue should be empty with size 0
    if (!stringTest.isEmpty() || stringTest.size() != 0) {
        TESTFAILED();
    }
    //tests the destructor of program for double delete and other common errors associated with
    //deallocating pointers properly
    for (int i = 0; i < 2; i++) {
        Queue<std::string> testTheDestructor;
        testTheDestructor.push("hello");
    }
    std::cout << "ALL TESTS PASSED!" << std::endl;
    return 0;
}

