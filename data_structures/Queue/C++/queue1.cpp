#include <bits/stdc++.h>

using namespace std;

template<typename T>

class Node{
public:
	T data;
	Node *next;
	Node *prev;
	Node(T data){
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

template<typename T>
class Queue {
public:
	Node<T> *head, *tail;
	int sz;
	Queue(){
		head = NULL;
		tail = NULL;
		sz = 0;
	}

	bool empty(){
		return head == tail;
	}

	int size(){
		return sz;
	}

	void push_back(T data){
		Node<T> *node = new Node<T>(data);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}

	void push_front(T data){
		Node<T> *node = new Node<T>(data);
		if(head == NULL){
			head = node;
			tail = node;
		}
		else{
			head->prev = node;
			head = node;
			node->next = head;
		}
	}

	void pop_front(){
		if(head != NULL){
			head = head->next;
			sz--;
		}
	}
    // TODO: 
	void pop_back(){
		if(tail != NULL){
			tail = tail->prev;
			sz--;
		}
	}

	void print(){
		Node<T> *node = head;
		while(node != NULL){
			cout << node->data << " ";
			node = node->next;
		}
	}
};

int main(){
	Queue<int> *deque = new Queue<int>();
	deque->push_back(1);
	deque->push_back(2);
    deque->push_back(3);
    deque->print();
    cout << endl;
    deque->pop_back();
    deque->print();
    return 0;
}