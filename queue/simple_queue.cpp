#include <bits/stdc++.h>
using namespace std;

struct Staff {
	int no;
	string name;
	string faculty;
	Staff* next;
};

class StaffQueue {
private:
	Staff* front;
	Staff* rear;
	int counter;

public:
	StaffQueue() {
		front = NULL;
		rear = NULL;
		counter = 0;
	}
	bool isEmpty() {
		if (counter == 0) return true;
		else return false;
	}
	void Enqueue(int no, string name, string faculty) {
		Staff* newStaff = new Staff;
		newStaff->no = no;
		newStaff->name = name;
		newStaff->faculty = faculty;
		newStaff->next = NULL;

		if(isEmpty()) {
			front = newStaff;
			rear = newStaff;
		}
		else {
			rear->next = newStaff;
			rear = newStaff;
		}
		counter++;		
		cout<<"YOU ALREADY ENQUEUED :"<<endl
			<<"NO: "<<newStaff->no<<endl
			<<"NAME: "<<newStaff->name<<endl
			<<"FACULTY: "<<newStaff->faculty<<endl;
	}
	void Dequeue() {
		if(isEmpty()) {
			cout<<"ERROR:THE QUEUE IS EMPTY"<<endl;
		}
		else {
			front = front->next;
			counter--;
			cout<<"DEQUEUED!!"<<endl;
		}
	}
	void DisplayQueue() {
		Staff *curr = front;
		cout<<"Staff Details"<<endl
			<<"-------------"<<endl;
		for(int i=0; i<counter; i++) {
			cout<<"\tNo: "<<curr->no<<endl
				<<"\tName: "<<curr->name<<endl
				<<"\tFaculty: "<<curr->faculty<<endl
				<<"--------------------------"<<endl;
			curr = curr->next;
		}
	}
};

int main() {
	StaffQueue q;
	if(q.isEmpty()) cout<< "Queue is empty"<<endl;
	q.Enqueue(123, "Zafar", "KICT");
	q.Enqueue(456, "Zarif", "KOE");
	q.Enqueue(789, "Zul", "KAED");
	q.DisplayQueue();
	q.Dequeue();
	q.DisplayQueue();

	return 0;
}