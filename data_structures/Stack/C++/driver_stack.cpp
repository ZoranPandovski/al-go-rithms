#include "stack.hpp"
using namespace cs202;
int main()
{
	stack<int> a;

	int b,c;
	while(1){
		cout<<"1.Push\n2.Pop\n3.Top\n4.Size\n5.Check for empty\n6.Print\n7.Exit\nstack << ";
		cin>>b;
		switch(b)
		{
			case 1:cout<<"Enter value:";
					cin>>c;
					a.push(c);
					break;

			case 2:if(a.size()>0)cout<<a.pop()<<endl;
					else cout<<"Empty Stack\n";
					break;

			case 3:cout<<a.top()<<endl;
					break;

			case 4:cout<<a.size()<<endl;
					break;

			case 5:if(a.empty()) cout<<"True\n";
					else cout<<"\nFalse";
					break;

			case 6:a.print();break;
			case 7:return 0;
					break;


			default:cout<<"Incorrect Choice"<<endl;
					break;
		}
	}
return 0;	
}