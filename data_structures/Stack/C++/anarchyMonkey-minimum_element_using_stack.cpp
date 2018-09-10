#include <iostream>
/* PROGRAMME TO FIND THE MINIMUM ELEMENT  USING A SINGLE STACK :') */
using namespace std;
int * STACK;
int top = 0;
int element;
int choice;
int size;


void push(int x)
{
    STACK[top++]=x;
}
int pop()
{
    return STACK[top--];
}
int main()
{
    cout<<"Enter the size of the array"<<endl;
    cin>>size;
    cout<<"\nEnter the choice\n1.push()\n2.display minimum element"<<endl;
    cin>>choice;
    STACK = new int[size];
    while(choice != -1)
    {
        switch(choice)
        {

        case 1:
            cout<<"Enter the element"<<endl;
            cin>>element;
            // push(element);
            if(top == 0)
            {

                push(element);
                //cout<<"top is "<<top<<endl;
            }
            else if(element < STACK[0])
            {
                cout<<"\npopping larger value :-"<<STACK[0]<<"\npushing smaller value:-"<<element<<endl;
                pop();
                push(element);
            }
            break;
        case 2:
            cout<<"THE MINIMUM ELEMENT IS "<<endl;
            for(int i = 0; i<top; i++)
            {

                cout<<STACK[i]<<endl;
            }

        }

        cout<<"\nEnter the choice\n1.push()\n2.display minimum element"<<endl;
        cin>>choice;
    }
}
