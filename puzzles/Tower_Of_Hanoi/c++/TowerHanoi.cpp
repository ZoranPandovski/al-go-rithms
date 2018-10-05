#include<iostream>
using namespace std;
void move(int n,char pole1,char pole2,char pole3){
	if(n==0) return;
	move(n-1,pole1,pole3,pole2);
	cout<<n<<" "<<pole1<<" to "<<pole2<<endl;
	move(n-1,pole3,pole2,pole1);
}
int main(){
	int n;
	cin>>n;
	move(n,'a','b','c');
}