#include<cstddef>
#include<iostream>
using namespace std;

template <class DT>
class List {

	template <class DT>
	struct Node {
		DT data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
	};

	Node<DT>* head;
	Node<DT>* current;
	int nItems;
public:
	List();
	~List();
	int getNItems() {
		return nItems;
	}
	void insert(const DT& newDataItem);
	void insertAt(const DT& newDatItem, int index);
	bool isEmpty();
	void display();
	DT getCursor();
	bool gotoNext();
	bool gotoPrior();
	bool moveCursorToEnd();
};

template<class DT>
List<DT>::List() {
	head = NULL;
	current = NULL;
	nItems = 0;
}

template<class DT>
void List<DT>::insert(const DT& newDataItem) {

	if (isEmpty()) {
		Node<DT>* newNode = new Node<DT>;
		newNode->data = newDataItem;
		head = newNode;

		current = head;
		
		nItems++;
	}
	else {
		Node<DT>* newNode = new Node<DT>;
		newNode->data = newDataItem;
		newNode->next = NULL;

		current->next = newNode;
		current = newNode;

		nItems++;
	}
}

template<class DT>
bool List<DT>::isEmpty() {
	return (head == NULL);
}

template<class DT>
void List<DT>::display() {

	Node<DT>* temp = new Node<DT>;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
		
}

template<class DT>
DT List<DT>::getCursor() {
	return current->data;
}

template<class DT>
bool List<DT>::gotoNext() {

	if (current->next != NULL) {
		current = current->next;
		return true;
	}

	else
		return false;
}

template<class DT>
bool List<DT>::gotoPrior() {

	// check: not at the beginning
	if (current != head) {
		
		Node<DT>* temp = new Node<DT>;
		temp = head;
		while (temp->next != current) {
			temp = temp->next;
		}
		current = temp;

		return true;
	}

	else
		return false;
}

template<class DT>
bool List<DT>::moveCursorToEnd() {

	if (head == NULL)
		return false;
	
	Node<DT>* temp = new Node<DT>;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}

	current = temp;
}

template<class DT>
List<DT>::~List() {
	Node<DT>* currNode = head;
	Node<DT>* nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode; // destroy the current node
		currNode = nextNode;
	}
}

template<class DT>
void List<DT>::insertAt(const DT& newDataItem, int index) {

	if (index < 0 || index > nItems) {
		cout << "Out of Range index!\n";
		moveCursorToEnd();
		return;
	}
	
	if (index == 0) {
		Node<DT>* newNode = new Node<DT>;
		newNode->data = newDataItem;
		newNode->next = head;
		head = newNode;
		current = newNode;
		nItems++;
	}

	else {

		int currentIndex = 0;
		Node<DT>* temp = head;
		while (currentIndex + 1 < index) {
			temp = temp->next;
			currentIndex++;
		}


		Node<DT>* newNode = new Node<DT>;
		newNode->next = temp->next;
		temp->next = newNode;
		newNode->data = newDataItem;
		current = newNode;
		nItems++;
	}
	
}
