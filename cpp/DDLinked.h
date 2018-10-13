#include <string>
using namespace std;
class myException
{
public:
    myException()
    {
        message = "Something is wrong!";
    }
	
    myException(string str)
    { 
        message = str; 
    }

    string what()
    {
        return message;
    }

private:
    string message;
};


template <class datatype>
class doublenode{
public:
	datatype data;
	doublenode<datatype> *llink, *rlink;
};

template<class datatype>
class doublelink{
private:
	doublenode<datatype> *headnode, *current, *temp;

public:
	doublelink(); 
	 bool ddlist_empty(); 
	 void insertnode(datatype d); 
	 void deletenode(void); 
	 
	 
	 datatype returncurrent(void);
	 void moveBegin(void);
	 void moveEnd(void);
	 void moveRight(void);
	 void moveLeft(void);
};




///////////////////////////////////////CONSTRUCTOR/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class datatype>
doublelink<datatype>::doublelink()
{
	headnode = new doublenode<datatype>;
	headnode->llink = headnode;
	headnode->rlink = headnode;
	current = headnode;

};
///////////////////////////////////////END CONSTRUCTOR////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////DELETE NODE FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class datatype>
void doublelink<datatype>::deletenode(void)
{
	//current has been set
	if(current != headnode)
	{
		temp = current;
		temp->llink->rlink = temp->rlink;
		temp->rlink->llink = temp->llink;
		current = headnode;
		delete(temp);
	}
};
//////////////////////////////////////////END DELETE NODE FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////INSERT NODE FUNCTION/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class datatype>
void doublelink<datatype>::insertnode(datatype d)
{
	// current has been set to the point in the list
	temp = new doublenode<datatype>;
	temp->data= d;
	
	if(ddlist_empty())
	{
		current = headnode;
	}

	temp->llink = current;
	temp->rlink = current->rlink;
	current->rlink->llink = temp;
	current->rlink = temp;

};
/////////////////////////////////////////END INSERT NODE FUNCTION/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////DDLIST EMPTY FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class datatype>
bool doublelink<datatype>::ddlist_empty()
{
	bool emptylist = true;
	
	if(headnode == headnode->llink && headnode == headnode->rlink)
	{
		emptylist = true;
	}
	
	else
	{
		emptylist = false;
	}

  return emptylist;
};
/////////////////////////////////////////END DDLIST EMPTY FUNCTION/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////RETURN CURRENT FUNCTION/////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class datatype>
datatype doublelink<datatype>::returncurrent(void)
{
	try
	{
		if(ddlist_empty())
		{
			 throw myException("The list is empty, Error cannot move current");
		}

		else
			return current->data;
			

	}
	catch(myException e)
	{
		cout << e.what();
	}



}
//////////////////////////////////////////////////////////////////////////////////END RETURN CURRENT FUNCTION/////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////MOVE BEGIN FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class datatype>
void doublelink<datatype>::moveBegin(void)
{
	try
	{
		if(ddlist_empty())
		{
			throw myException("The list is empty, Error cannot move current");
		}

		else current = headnode->rlink;

	}	
	catch(myException e)
	{
		cout << e.what(); 
	}


}
//////////////////////////////////////////////////////////////////////////////////END MOVE BEGIN FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////MOVE END FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class datatype>
void doublelink<datatype>::moveEnd(void)
{
	try
	{
		if(ddlist_empty())
		{
			throw myException("The list is empty, Error cannot move current");
		}

		else current = headnode->llink;

	}	
	catch(myException e)
	{
		cout << e.what(); 
	}
}
//////////////////////////////////////////////////////////////////////////////////END MOVE END FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////MOVE  RIGHT FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class datatype>
void doublelink<datatype>::moveRight(void)
{
	try
	{
		if(ddlist_empty())
		{
			throw myException("The list is empty, Error list empty");
		}

		current = current->rlink;

	}	
	catch(myException e)
	{
		cout << e.what(); 
	}
}
//////////////////////////////////////////////////////////////////////////////////END MOVE  RIGHT FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////MOVE LEFT FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class datatype>
void doublelink<datatype>::moveLeft(void)
{
	try
	{
		if(ddlist_empty())
		{
			throw myException("The list is empty, Error list empty");
		}

		current = current->llink;

	}	
	catch(myException e)
	{
		cout << e.what(); 
	}
}
//////////////////////////////////////////////////////////////////////////////////END MOVE LEFT FUNCTION////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	






