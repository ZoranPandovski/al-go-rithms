// kadane's Algorithm
// uding STL
#include<bits/stdc++.h>
using namespace std;
#define fast_input ios_base::sync_with_stdio(false); cin.tie(NULL)

void Result(long int arr[], long int size){ // funtion to print Maximum value..
	
	long int MaxValue=arr[0], CurrValue=arr[0];
	
	for(int i=1;i<size;i++){                       // loop check the maximum sum of contiguous sub_array..
		CurrValue=max(arr[i] , CurrValue+arr[i]); 
		if(MaxValue<CurrValue){
			MaxValue=CurrValue;		
		}
	}
	cout<< MaxValue; // print max value.. 
}
int main(){
    fast_input;
    int TestCase;
    cin>>TestCase;
    while(TestCase--){   //  number of testcase..
    long int size;
    cin>>size;
    long int arr[size];
    for(int i=0; i<size; i++) cin>>arr[i];
    Result(arr,size);
    cout<<"\n";
	}
return 0;
}
/* input:
	1
	5
	1 3 4 -1 5
	output:
	12
*/
	

