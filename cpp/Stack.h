// Remove #pragma once unless using microsoft visual studio software
// Array based stack

#pragma once
#include <cassert>

template <class Type>
class sNode
{
public:
	Type value;
	sNode *Next;
};


template <class Type>
class Stack
{
public:

	/*Array based Stack*/
	Stack(int sSize = 100); 
	
	Stack(const Stack<Type>& otherStack); 

	~Stack(); 

	const Stack<Type>& operator= (const Stack<Type>& otherStack);

	void initializeStack(); 

	bool isEmpty() const; 

	bool isFull() const; 

	void Push(const Type& v); 

	Type Top() const; 

	void Pop(); 


	/*End Array based stack*/


protected:

	

private:
	sNode<Type> *head,
			    *last,
				*current;

	int maxSize,
		stackTop;

	Type *list;

	void copyStack(const Stack<Type>& otherStack);
};

/*Stack: This section uses the examples laid out in the book to build an implementation of a stack using an array*/

/*Array based stack: Constructor*/
template <class Type>
Stack<Type>::Stack(int sSize)
{
	if (sSize <= 0)
	{
		cout << "The size of the array must ba positve value above 0, \nCreating an array of size 100" << endl;
		maxSize = 100;
	}
	else
		maxSize = sSize;
	
	stackTop = 0;
	list = new Type[maxSize];
}
/*Array based stack: End Constructor*/




/*Array based Stack: Copy Constructor*/
template <class Type>
Stack<Type>::Stack(const Stack<Type>& otherStack)
{
	list = nullptr;
	copyStack(otherStack);
}
/*Array based stack: End Copy constructor*/




/*Array based stack: Destructor*/
template <class Type>
Stack<Type>::~Stack()
{
	delete [] list;
}
/*Array based stack: End Destructor*/


/*Array based stack: Copy Stack*/
template <class Type>
void Stack<Type>::copyStack(const Stack<Type>&  otherStack)
{
	delete [] list;
	maxSize = otherStack.maxSize;
	stackTop = otherStack.stackTop;

	list = new Type[maxSize];

	for (int i = 0; i < stackTop; i++)
	{
		list[i] = otherStack.list[i];
	}
}
/*Array based stack: End Copy Stack*/


/*Array based stack: Operator = Overload*/
template <class Type>
const Stack<Type>& Stack<Type>::operator=(const Stack<Type>& otherStack)
{
	if (this != &otherStack)
	{
		copyStack(otherStack);
	}
	return *this;
}
/*Array based stack: End Operator = Overload*/



/*Array based stack: Initialize Stack*/
template <class Type>
void Stack<Type>::initializeStack()
{
	stackTop = 0;
}
/*Array Based stack: End Initialize Stack*/



/*Array based stack: Is Empty*/
template <class Type>
bool Stack<Type>::isEmpty() const
{
	return (stackTop == 0);
}
/*Array based stack: End Is Empty*/


/*Array based stack: Is Full*/
template <class Type>
bool Stack<Type>::isFull() const
{
	return (stackTop == maxSize);
}
/*Array based stack: End Is Full*/



/*Array based stack: Push*/
template <class Type>
void Stack<Type>::Push(const Type& v)
{
	try
	{
		if (!isFull())
		{
			list[stackTop] = v;
			stackTop++;
		}
		else
			cout << "The stack is full, you cannot add more to it" << endl;
	}
	catch (...)
	{
		cout << "An uknown Catastrophic Error has ocured" << endl;
	}
}
/*Array based stack: End Push*/



/*Array based stack: Top*/
template <class Type>
Type Stack<Type>::Top() const
{
	assert(stackTop != 0);
	return list[stackTop - 1];

}
/*Array absed stack: End Top*/



/*Array based stack: Pop*/
template <class Type>
void Stack<Type>::Pop()
{
	try
	{
		if (!isEmpty())
		{
			stackTop--;
		}
		else
			cout << "The stack is empty, there is nothing left to be removed" << endl;
	}
	catch (...)
	{
		cout << "An uknown Catastrophic Error has ocured" << endl;
	}
}
/*Array based stack: End Pop*/


/*Stack: End Array based stack section*/