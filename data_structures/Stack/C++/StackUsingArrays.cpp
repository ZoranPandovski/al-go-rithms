#include <iostream>
using namespace std;
#define MAX 10000
// defined a class stack
class Stack {
	//top variable which represents the top of the stack
	int top;
public:
	//declared an array of MAX size to store the elements of the stack
	int arr[MAX];
	//top is intialised to -1 when stack is created
	Stack() {
		top = -1;
	}
	// function to push elements into the stack
	bool push(int num) {
		//maximum size of the stack
		if (top >= MAX) {
			cout << "Stack OverFlow" << endl;
			return false;
		}
		else {
			arr[++top] = num;
			cout << num << " is pushed into the stack" << endl;
			return true;
		}
	}
	bool pop() {
		//minimum size of the stack
		if (top <= -1) {
			cout << "Stack UnderFlow";
			return false;
		}
		else {
			int x = arr[top--];
			cout << x << " is popped out of the stack" << endl;
			return true;
		}
	}
	bool isEmpty() {
		//checking if stack is empty or not.
		if (top <= -1) {
			return true;
		}
		else return false;
	}
};
int main() {
	Stack s;
	if (s.isEmpty()) cout << "Stack is empty" << endl;
	s.push(10);
	s.push(20);
	if (!s.isEmpty()) cout << "Stack is not empty" << endl;
	s.pop();
	s.pop();
	return 0;
}