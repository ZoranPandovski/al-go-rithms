
/*
Problem : Minimum Steps to One

Problem Statement: On a positive integer, you can perform any one of 
the following 3 steps.
 1.) Subtract 1 from it. ( n = n - 1 )  
 2.) If its divisible by 2, divide by 2. ( if n % 2 == 0 , then n = n / 2  )  ,
 3.) If its divisible by 3, divide by 3. ( if n % 3 == 0 , then n = n / 3  ). Now the question is, 
given a positive integer n, find the minimum number of steps that takes n to 1

eg: 1.)For n = 1 , output: 0       ]
    2.) For n = 4 , output: 2  ( 4  /2 = 2  /2 = 1 )   
    3.)  For n = 7 , output: 3  (  7  -1 = 6   /3 = 2   /2 = 1 )

*/

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
	return a > b ? b : a;
}

int getMinSteps(vector<int> &memo, int n){
	if(n==1){
		return 0;
	}
	if(memo[n] != -1){
		cout<<"Alredy solver encounterd "<<n<<endl;
		return memo[n];
	}

	int r = 1 + getMinSteps(memo,n-1);
	if( n % 2 == 0){
		r =   min(r, 1 + getMinSteps(memo,n/2));
	}
	if( n % 3 == 0){
		r = min(r, 1 + getMinSteps(memo,n/3));
	}
	memo[n] = r;
	return r;

}

int main(){
	int n;
	cin>>n;
	std::vector<int> memo(n+1);
	std::fill(memo.begin(), memo.end(), -1);
	//memset(memo,-1,memo.size());
	cout<<getMinSteps(memo, n)<<endl;
	for(int i = 0; i < memo.size(); i++){
		cout<<memo[i]<<" ";
	}
}

