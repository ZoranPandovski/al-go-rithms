#include<iostream>
using namespace std;
int main(){
int x=6;
cout<<"The value of x= "<<x<<endl;
int *p=&x;
int **q=&p;
int ***r=&q;
**q=8;
cout<<"The value of x= "<<x<<endl;
***r=10;
cout<<"The value of x= "<<x<<endl;

return 0;
}
