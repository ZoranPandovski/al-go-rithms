#include<stdio.h>
#include<iostream>
#include<string.h>
#define SIZE 10
using namespace std;

class queue
{
    int data[10];
    int front;
    int rear;
public:
    void insertAtRear(int a)
    {
        if(rear==SIZE-1)
        {
            cout<<"Queue Overflow"<<endl;
            return;
        }
        data[++rear]=a;
    }

    int deleteAtRear()
    {
        if(front>rear)
        {
            cout<<"Queue Underflow"<<endl;
            return -9999;
        }
        int v=data[rear--];
        return v;
    }
    void insertAtFront(int a)
    {
        if(front==0)
        {
            cout<<"Unable to insert at front"<<endl;
            return;
        }
        data[--front]=a;
    }

    int deleteAtFront()
    {
        if(front>rear)
        {

            return -9999;
        }
        int v=data[front++];
        return v;
    }
    void display()
    {
        for(int i=0;i<=rear;i++)
        {
            if(i==rear)
                cout<<data[i]<<" <-- rear"<<endl;
            else if(i==front)
                cout<<data[i]<<"<-- front"<<endl;
            else
                cout<<data[i]<<endl;
        }
    }
    queue()
    {
        front=0;
        rear=-1;
    }
};

void menu()
{
    cout<<"#####################################"<<endl;
    cout<<"############### DEQUEUE #############"<<endl;
    cout<<"Choose the following options- "<<endl;
    cout<<"1. Insert at Front\n2. Delete at Front\n3. Insert at Rear\n4. Delete at rear\n5. Display\n6. Exit"<<endl;
}
int main()
{
    queue q1;
    int quit=0,choice,value;
    menu();
    while(!quit)
    {
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"Enter value to be inserted at Front"<<endl;
                    cin>>value;
                    q1.insertAtFront(value);
                    break;
            case 2: value=q1.deleteAtFront();
                    if(value==-9999)
                        cout<<"Queue Underflow"<<endl;
                    else
                        cout<<"Popped item is: "<<value<<endl;
                    break;
            case 3: cout<<"Enter value to be inserted at Rear"<<endl;
                    cin>>value;
                    q1.insertAtRear(value);
                    break;

            case 4: value=q1.deleteAtRear();
                    if(value==-9999)
                        cout<<"Queue Underflow"<<endl;
                    else
                        cout<<"Popped item is: "<<value<<endl;
                    break;
            case 5: q1.display();
                    break;
            case 6: quit++;
                    break;
            default: cout<<"Wrong input recieved"<<endl;
        }
    }
    return 0;
}


