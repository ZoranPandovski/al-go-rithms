#pragma once
#include <string>
/*Moderate exception class will go here*/
class myException
{
public:
	myException()
	{
		message = "Something is wrong!";
	}

	myException(std::string str)
	{
		message = str;
	}

	std::string what()
	{
		return message;
	}

private:
	std::string message;
};


/*But not until the linked list is re-built*/




/*Node class*/
template <class type>
class Node 
{
public:
	type datavalue;
	Node *Next; 


	/*
	  

	*/
};
/*End Node class*/



/*Linked List class*/
template <class type>
class LinkedList 
{

public:
	LinkedList();
	bool listEmpty(void);
	
	
	//void addBegin(type data); Replaced with Insert_Begining
	void Insert_Begining(type data);
	
	//type returnBegin(void); Replaced with Return_Begining
	type Return_Begining(void);
	
	//void removeBegin(void); Replaced with Remove_Begining
	void Remove_Begining(void);


	//void addEnd(type data); Replaced by Add_Last
	void Add_Last(type data);

	//type returnEnd(void); Replaced by Return_Last
	type Return_Last(void);


	//void removeEnd(void); Replaced by Remove_Last
	void Remove_Last(void);

	//void moveBegin(void); Replaced by start
	void Start(void);


	//void moveNext(void); Replaced with Next
	void Next(void);

	//void moveEnd(void); Replaced with End
	void End(void);

	//type returnCurrent(void); Replaced by Return_Current
	type Return_Current(void);
	
	//void addCurrent(type data); Replaced by Add_Current
	void Add_Current(type data);
	
	
	//void removeCurent(void); Replaced by Remove_Current
	void Remove_Current(void);

	//void printlist(void); Replaced by Print
	void Print(void);

	//void printReversed(void); // Replaced with Print_Forward
	void Print_Forward(void);

	void printRec();

private:
	Node<type> *head,
		       *last,
		       *current;

	void printRecursive(Node<type> *tempNode);


};
/*End Linked List class*/




/* Linked List Cosntructor */
template<class type>
LinkedList<type>::LinkedList()
{
	head = NULL;
	last = NULL;
	current = NULL;
}
/* End Linked List Constructor*/




/* Linked List: List Empty Function*/
template<class type>
bool LinkedList<type>::listEmpty(void)
{
	bool temp = false;
	if (head == NULL)
	{
		temp = true;
	}
	return temp;
}
/*Linked List: End List Empty Function*/





/*Linked List: Insert Begining Function */
template <class type>
void LinkedList<type>::Insert_Begining(type data)
{
	Node<type> *temp; 
	temp = new Node<type>; 
	temp->datavalue = data; 
	temp->Next = head;

	if (head == NULL)
	{
		last = temp;
	}

	head = temp;
}
/*Linked List: End Insert Begining Function*/





/*Linked List: Return Begining Function*/
template <class type>
type LinkedList<type>::Return_Begining(void) 
{
	try
	{
		if (head == NULL)
		{
			throw myException("ERROR: The list is empty");
		}
	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}

	return head->datavalue;
}
/*Linked List: End Return Begining Function*/





/*Linked List: Remove Begining Function*/
template <class  type>
void LinkedList<type>::Remove_Begining(void)
{
	Node<type> *temp;

	try
	{
		if (head == NULL)
		{
			throw myException("***ERROR***: The list is empty");
		}

		if (head == last)
		{
			last = NULL;
		}

		temp = head;
		head = head->Next;
		delete temp;
	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: End Remove Begining Function*/





/*Linked List: Add End Function*/
template <class type>
void LinkedList<type>::Add_Last(type data)
{
	Node<type> *temp;
	temp = new Node<type>;
	temp->datavalue = data;
	temp->Next = NULL;
	if (head == NULL)
	{
		last = temp;
		head = temp;
	}
	else
	{
		last->Next = temp;
		last = temp;


	}

}
/*Linked List: End Add End Function*/





/*Linked List: Return End Function*/
template <class type>
type LinkedList<type>::Return_Last(void)
{
	try
	{
		if (head == NULL || last == NULL)
		{
			throw myException("The list is empty, Or Pointer to Last ERROR");
		}
		else
			return last->datavalue;
	}

	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: End Return End Function*/





/*Linked List: Remove Last Function*/
template <class type>
void LinkedList<type>::Remove_Last(void)
{
	Node<type> *temp, *pos;

	try
	{
		if (head == NULL || last == NULL)
		{
			throw myException("ERROR: The list is empty, or pointer to last error");
		}

		if (head == last)
		{
			last = NULL;
			temp = head;
			head = NULL;
			delete temp;
		}

		else
		{
			pos = head;
			while (pos->Next->Next != NULL)
			{
				pos = pos->Next;
			}

			temp = pos->Next;
			pos->Next = NULL;
			last = pos;
			delete temp;
		}
	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}

}
/*Linked List: End Remove Last Function*/




/*Linked List: Start Function*/
template <class type>
void LinkedList<type>::Start(void)
{
	try
	{
		if (head == NULL)
		{
			throw myException("The list is empty, Error cannot move current");
		}

		else
		{
			current = head;
		}

	}
	catch (myException me)
	{
		cout << me.what() << endl;
	} 

	// Moves to the begining of the list for searching/printing etc.. purposes..
	//
	//

}
/*Linked List: End Start Function*/



/*Linked List: Function End, move to the end of the list*/
template <class type>
void LinkedList<type>::End(void)
{
	try
	{
		if (head == NULL)
		{
			throw myException("The list is empty, Error cannot move curren");
		}

		else
		{
			current = last;
		}

	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: End Function End*/




/*Linked List: Next Function, Moves forward by one position in the list*/
template <class type>
void LinkedList<type>::Next(void)
{
	try
	{
		if (head == NULL || current == NULL)
		{
			throw myException("The list is empty, Error cannot move current");
		}

		if (current == last)
		{
			current = head;
		}
		else
		{
			current = current->Next;
		}

	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: End Next Function*/





/*Linked List: Return Current Function*/
template <class type>
type LinkedList<type>::Return_Current(void)
{
	try
	{
		if (head == NULL || current == NULL)
		{
			throw myException("The list is empty, Error cannot move current");
		}

		return current->datavalue;

	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: End Return Current*/





/*Linked List: Add Current Function*/
template <class type>
void LinkedList<type>::Add_Current(type data)
{
	if (head == NULL && current == NULL)
	{
		Insert_Begining(data);
	}
	else
	{
		try
		{
			if (current == NULL)
			{
				throw myException("Current pointer is NULL");
			}
			Node<type> *temp;
			temp = new Node<type>;
			temp->datavalue = data;
			temp->Next = current->Next;
			if (current == last)
			{
				last = temp;
			}
			current->Next = temp;
		}
		catch (myException me)
		{
			cout << me.what() << endl;
		}

	}
}
/*Linked List: End Add Current Function*/



/*Linked List: Remove Current Function*/
template <class type>
void LinkedList<type>::Remove_Current(void)
{
	try
	{
		if (current == NULL)
		{
			throw myException("Current pointer is NULL");
		}

		if (current == head)
		{
			Remove_Begining();
			current = head;
		}
		else
		{
			if (current == last)
			{
				Remove_Last();
				current = last;
			}
			else
			{
				Node<type> *pos;
				pos = new Node<type>;
				pos = head;
				while (pos->Next->Next != current)
				{
					pos = pos->Next;
				}

				pos->Next = current->Next;
				delete current;
				current = pos;
			}
		}

	}
	catch (myException me)
	{
		cout << me.what() << endl;
	}
}
/*Linked List: end Remove Current Function*/





/*Linked List: Print Function, Standard Print Function*/
template <class type>
void LinkedList<type>::Print(void)
{
	Node<type> *pos;
	pos = head;
	while (pos != NULL)
	{
		std::cout << pos->datavalue << "\n";
		pos = pos->Next;
	}
	std::cout << "\n\n";
}
/*Linked List: End Print Function*/




/*Linked List: Print Forward Function*/
template <class type>
void LinkedList<type>::Print_Forward(void)
{
	Node<type> *pos;
	pos = last;

	while (pos != head && head != NULL)
	{
		cout << Return_Last() << "\n";
		Remove_Last();
	}
	cout << "\n\n";

}
/*Linked List: End Print Forward Function*/




/*Linked List:Print Recursive function*/
template <class type>
void LinkedList<type>::printRecursive(Node<type> *tempNode)
{
	try
	{

		if (listEmpty())
		{
			throw(myException("List empty, Error"));
		}

		if (tempNode != NULL)
		{
			printRecursive(tempNode->Next);
			cout << tempNode->datavalue << endl;
		}


	}
	catch (...)
	{
		cout << "Unknown Error " << endl;
	}
}
/*Linked List: End Print Recursive Function*/



/*Linked List: Print Rec Function*/
template <class type>
void LinkedList<type>::printRec()
{
	Start();
	printRecursive(current);
	cout << endl;
}
/*Linked List: End Print Rec Function*/