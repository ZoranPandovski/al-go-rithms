#include <iostream>
using namespace std;
int main()
{
    int A,B;
    cout<<"Enter the first number:";
    cin>>A;
    cout<<"Enter the second number:";
    cin>>B;
     int dvd=B;
     int div=A;
     while(dvd%div!=0){
        int rem=dvd%div;
        dvd=div;
        div=rem;
        cout<<"GCD of given number is:"<<div<<endl;
     }
     cout<<div<<endl;
     int lcm=(A+B)/div;
     cout<<"LCM of given number is:"<<lcm<<endl;
}
