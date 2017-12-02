/* In a normal Queue, we can insert elements until queue becomes
full. But once queue becomes full, 
we can not insert the next element even 
if there is a space in front of queue.
So ,we use CIRCULAR QUEUE
*/

#include<iostream>
using namespace std;
#define SIZE 10
/* Circular Queue using class */
class CircularQueue
{
	int queue[10];
	int front, rear;
    public:CircularQueue()
           {
				front = -1;
				rear = -1;
        }
	   void push(int data);
	   void pop();
	   void display();

};
void CircularQueue::push(int data)
{
/*Check if Queue is not full
if queue is empty initialise front and rear to zero
else increment rear in circular fashion

*/
	if (front == -1)
	{
		front++;
		rear++;
		queue[front] = data;
	}
	else {

		if (((rear + 1) % SIZE) == front)
		{
			cout << "Queue is Full ,cannot insert more elements " << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;//Inserting element Circularly
			queue[rear] = data;

		}

	}
}
void CircularQueue::pop()
{
/*Check if Queue is empty
if Queue is empty reset front and rear
else move front circularly
*/
	if (front == -1)
	{
		cout << "Queue is empty ,cannot pop more elements";
	}
	else
	{
		if (front == rear)
		{
			front = rear = -1;

		}
		else
		{
			front = (front + 1) % SIZE;
		}
	}
}

	void CircularQueue::display()
	{
		int f = front;
		
		while (f != rear)
		{
			cout <<queue[f]<<" , " ;
			f = (f + 1) % SIZE; //Move front circularly

		}
		cout <<queue[rear] <<endl;
	}
	int main()
	{
		CircularQueue q;
		int choice, data;
		while (1)
		{
			cout << "\nMENU\n[1]Push\n[2]Pop\n[3]Display\n[4]Exit\nChoice :";
			cin >> choice;
			switch (choice)
			{
			case  1:cout << "Enter data :"; cin >> data;
				q.push(data);
				break;
			case 2:q.pop();
				break;
			case 3:q.display();
				break;
			case 4:return 0;

			default:cout << "Enter valid choice ";

			}

		}
		return 0;
	}




