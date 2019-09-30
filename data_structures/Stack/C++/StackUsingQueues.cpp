#include<bits/stdc++.h> 
  
using namespace std; 
  
class Stack 
{  
    queue<int> q1, q2; 
    int curr_size; 
  
    public: 
    Stack() 
    { 
        curr_size = 0; 
    } 
  
    void push(int x) 
    { 
        curr_size++; 
        q2.push(x); 
    
        while (!q1.empty()) 
        { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
   
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void pop(){ 
    
        if (q1.empty()) 
            return ; 
        q1.pop(); 
        curr_size--; 
    } 
  
    int top() 
    { 
        if (q1.empty()) 
            return -1; 
        return q1.front(); 
    } 
  
    int size() 
    { 
        return curr_size; 
    } 

}; 
  
// main function

int main() 
{ 
    Stack s;
  
    int choice = 0;
    
    while (choice != -1)
    {
      cout<<"Enter your choice "<<endl;
      cout<<"1) Push an element "<<endl;
      cout<<"2) Pop an element "<<endl;
      cout<<"3) Display top of stack "<<endl;
      cout<<"4) Size of stack "<<endl;
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
                s.push(num);
                cout<<endl<<endl;
                break;
        case 2:
                s.pop();
                break;
        case 3:
                res = s.top();
                if(res == -1)
                  cout<<"Stack is empty\n\n";
                else
                  cout<<"The element is : "<<res<<endl<<endl;
                break;
        case 4:
                res = s.size();
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
 
