#include "queue.hpp"
using namespace cs202;
int main()
{
	queue<int> a;

	int b,c;
	while(1){
		cout<<"1.Push\n2.Pop\n3.Front\n4.Size\n5.Check for empty\n6.Print\n7.Exit\nqueue << ";
		cin>>b;
		switch(b)
		{
			case 1:cout<<"Enter value:";
					cin>>c;
					a.push(c);
					break;

			case 2:if(a.size()>0)cout<<a.pop()<<endl;
					else cout<<"Empty Queue\n";
					break;

			case 3:cout<<a.front()<<endl;
					break;

			case 4:cout<<a.size()<<endl;
					break;

			case 5:if(a.empty()) cout<<"True\n";
					else cout<<"\nFalse\n";
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