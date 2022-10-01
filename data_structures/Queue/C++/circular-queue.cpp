#include <iostream>
#include <cctype>

using namespace std;

class queue
{
    int q[20], front, rear;
    const int SIZE = 20;
    
    bool isEmpty()
    {
        if(front == -1 && rear == -1) return true;
        return false;
    }

    public:

    queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(int a)
    {
        // Overflow Condition
        if((front == 0 && rear == SIZE - 1) || rear == front - 1)
        {
            cout << "OVERFLOW - Queue is full." << endl;
            return;
        }

        // Queue Empty
        else if(isEmpty())
        {
            front = rear = 0;
        }

        // Insert element at rear
        else if(rear < SIZE-1)
        {
            rear++;
        }

        // Circle back
        else
        {
            rear = 0;
        }

        // Insert Element
        q[rear] = a;
        
        cout << "Element with value " << a << " added to the queue." << endl;
    }

    void dequeue()
    {
        int element;
        // Underflow Condition
        if(isEmpty())
        {
            cout << "UNDERFLOW - Queue is empty." << endl;
            return;
        }

        element  = q[front];

        // Only one element in queue
        if(front == rear)
        {
            front = rear = -1;
        }

        // front at end of array
        else if(front == SIZE - 1)
        {
            front = 0;
        }

        else
        {
            front++;
        }
        
        cout << "Element with value " << element << " deleted from the queue." << endl;
    }

    void dispQueue()
    {
        if(isEmpty())
        {
            cout << "UNDERFLOW - Queue is empty." << endl;
            return;
        }
        else if(front <= rear)
        {
            for(int i=front;i<=rear;i++)
            {
                cout << q[i] << " ";
            }
        }
        else
        {
            for(int i=front;i<SIZE;i++)
            {
                cout << q[i] << " ";
            }
            for(int i=0;i<=rear;i++)
            {
                cout << q[i] << " ";
            }
        }
        
        
        cout << endl;
    }
};

int main()
{
    queue q1;
    int choice = 0, element;
    char repeat = 'y';

    do
    {
        cout << "************* Circular Queue *************" << endl << endl;
        cout << "1. Add Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Display Queue" << endl;

        cin >> choice;
        
        switch(choice)
        {
            case 1:
            cout << "Enter the element: ";
            cin >> element;
            q1.enqueue(element);
            break;

            case 2:
            q1.dequeue();
            break;

            case 3:
            q1.dispQueue();
            break;

            default:
            cout << "Invalid selection" << endl;
            break;
        }
        cout << "Go back to main menu? (y/n) ";
        cin >> repeat;
    } while (tolower(repeat) == 'y');
    

    return 0;
}