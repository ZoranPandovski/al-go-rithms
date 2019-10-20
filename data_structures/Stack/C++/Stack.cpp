#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
class Stack {
public:
	Stack();

	void push(T x);
	T pop();
	bool isEmpty();
	T peek();
private:
	std::vector<T> v;
};

template <class T>
Stack<T>::Stack() {
}

template <class T>
bool Stack<T>::isEmpty() {
	return v.empty();
}

template <class T>
void Stack<T>::push(T x) {
	v.push_back(x);
}

template <class T>
T Stack<T>::pop() {
	T val = v.back();
	v.pop_back();
	return val;
}

template <class T>
T Stack<T>::peek() {
	return v.back();
}

int main() {
	Stack<int> s;
	s.push(4);
	cout<<s.peek();
	return 0;
}