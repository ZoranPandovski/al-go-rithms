// swap 2 numbers without using the third variable
#include<iostream>
using namespace std;
int main(){int num1,num2;
    cout<<"Enter the numbers to be swaped"<<endl<<"Number 1: ";
    cin>>num1;
    cout<<endl<<"Number 2: ";
    cin>>num2;
    cout<<"The numbers before swapping are Number 1: "<<num1<<" and Number 2: "<<num2<<endl;
    //method 1
    num1 = num1+num2;
    num2= num1-num2;
    num1=num1-num2;
    cout<<"The numbers after swapping are Number 1: "<<num1<<" and Number 2: "<<num2<<endl;

    //method 2
    num1 = num1*num2;
    num2= num1/num2;
    num1=num1/num2;
    cout<<"The numbers after swapping are Number 1: "<<num1<<" and Number 2: "<<num2<<endl;
    return 0;
}
