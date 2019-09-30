#include <iostream>
using namespace std;

int main(void) {
	int n,i;
	cin >> n >> i;
	cout << (n & ( ~(1 << i)))<<"\n";      // consider the position numbering starting with 0 from RHS
	
	return 0;
}
