#include<iostream>
using namespace std;
int main(){
int a=10;
int* p=&a;
cout<<a<<endl;
cout<<p<<endl;
cout<<a+1<<endl;
cout<<p+2<<endl;

int x=10,y=20;
int *r=&x,*s=&y;
cout<<"x= "<<*r<<" and "<<"y= "<<*s<<endl;
swap(r,s);
cout<<"x= "<<*r<<" and "<<"y= "<<*s<<endl;


return 0;
}
