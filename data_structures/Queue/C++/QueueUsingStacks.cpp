#include <bits/stdc++.h> 
using namespace std; 

struct Queue { 
	stack<int> s1, s2; 

	void enQueue(int x) 
	{ 
		while (!s1.empty()) { 
			s2.push(s1.top()); 
			s1.pop(); 
		} 

		s1.push(x); 

		while (!s2.empty()) { 
			s1.push(s2.top()); 
			s2.pop(); 
		} 
	} 

	int deQueue() 
	{ 
		if (s1.empty()) { 
			return -1;
		} 

		int x = s1.top(); 
		s1.pop(); 
		return x; 
	} 
	
	int Front()
	{
	    if(s1.empty()){
	        return -1;
	    }
	    
	    return s1.top();
	}
	
	int size(){
	    
	    return s1.size();
	}
	
}; 

// Driver code

int main()
{
    Queue q;

    int choice = 0;
    
    while (choice != -1)
    {
      cout<<"Enter your choice "<<endl;
      cout<<"1) Enqueue an element "<<endl;
      cout<<"2) Dequeue an element "<<endl;
      cout<<"3) Display front of queue "<<endl;
      cout<<"4) Size of queue "<<endl;
      cout<<"Press -1 to exit"<<endl;
      cout<<endl;
      cin>>choice;
      cout<<endl;
      int res;

      switch(choice)
      {
        case 1:
                cout<<"Enter element value (int) - ";
                int num;
                cin>>num;
                q.enQueue(num);
                cout<<endl<<endl;
                break;
        case 2:
                res = q.deQueue();
                if(res == -1)
                  cout<<"Queue is empty\n\n";
                else
                  cout<<"The element dequeued is "<<res<<"\n\n";
                break;
        case 3:
                res = q.Front();
                if(res == -1)
                  cout<<"Queue is empty\n\n";
                else
                  cout<<"The element is : "<<res<<endl<<endl;
                break;
        case 4:
                res = q.size();
                cout<<"The size is : "<<res<<endl<<endl;
                break;
        case -1:
                break;
        default:
                cout<<"Enter valid option \n\n";
      }
    }
	return 0; 
}
