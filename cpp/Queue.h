// Remove #pragma once unless using microsoft visual studio
// Two functions are not compelte
// Every thing works except the two I've not done yet (they're of no importance)
// Array based Queue
#pragma once
#include <cassert>

template <class Type>
class Queue
{

public:

	Queue(int qSize = 100); // Constructor

	Queue(const Queue<Type>& otherqueue); // Copy Constructor

	~Queue(); // Destructor

	bool isEmpty() const;

	bool isFull() const;

	void initQueue();

	Type Front() const;

	Type Back() const;

	void addItem(const Type& queueElement);

	void deleteItem();

	const Queue<Type>& operator=(const Queue<Type>&);


private:

	int maxSize,
		count,
		queueFront,
		queueRear;

	Type *list;

};




/*Array Based Queue: Constructor*/
template <class Type>
Queue<Type>::Queue(int qSize)
{
	if (qSize <= 0)
	{
		cout << "The size of the queue must be a postive value that is greater than 0, \nCreate an array of size 100 " << endl;
		maxSize = 100;
	}
	else
		maxSize = qSize;

	queueFront = 0;
	queueRear = maxSize - 1;
	count = 0;
	list = new Type[maxSize];
}
/*Array Based Queue: End Constructor*/


/*Array Based Queue: Destructor*/
template <class Type>
Queue<Type>::~Queue()
{
	delete[] list;
}
/*Array Based Queue: End Destructor*/




/*Array Based Queue: Is Empty Function*/
template <class Type>
bool Queue<Type>::isEmpty() const
{
	return (count == 0);
}
/*Array Based Qeue: End Is Empty*/


/*Array Based Queue: Is Full Function*/
template <class Type>
bool Queue<Type>::isFull() const
{
	return (count == maxSize);
}
/*Array Based Queue: End Is Full Function*/


/*Array Based Queue: Init Queue Function*/
template <class Type>
void Queue<Type>::initQueue()
{
	queueFront = 0;
	queueRear = maxSize - 1;
	count = 0;
}
/*Array Based Queue: End Init Queue Funciton*/


/*Array Based Queue: Front Function*/
template <class Type>
Type Queue<Type>::Front() const
{
	assert(!isEmpty());
	return list[queueFront];
}
/*Array Based Queue: End Front Function*/


/*Array Based Queue: Back Function*/
template <class Type>
Type Queue<Type>::Back() const
{
	assert(!isEmpty());
	return list[queueRear];
}
/*Array Based Queue: End Back Function*/


/*Array Based Queue: Add Item Function*/
template <class Type>
void Queue<Type>::addItem(const Type& newElement)
{
	if (!isFull())
	{
		queueRear = (queueRear + 1) % maxSize;
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "The Queue is full you cannot add any thing to it" << endl;
}
/*Array Based Queue: End Add Item Funciton*/

/*Array Based Queue: Delete Item Function*/
template <class Type>
void Queue<Type>::deleteItem()
{
	if (!isEmpty())
	{
		count--;
		queueFront = (queueFront + 1) % maxSize;
	}
	else
		cout << "The queue is empty there is nothing to remove" << endl;
}
/*Array Based Queue: End Delete Item*/