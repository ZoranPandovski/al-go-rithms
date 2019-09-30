#include <iostream>

int highest_common_factor(int *a,int *b){
	if(a%b==0)return b;
	else {
	   return highest_common_factor(b,a%b);
	}

}

int main(){
	int x,y;
	cin >> x >> y;
	cout << highest_common_factor(x,y) <<endl;

}
