#include<bits/stdc++.h>
using namespace std;

int Highest_Power_of_2(int n){
    return n&(~(n-1)); 
}

int main(){
    int n;
    cin>>n;
    cout<<Highest_Power_of_2(n)<<endl;
    return 0;
}

// Time complexity: O(1)
// Space complexity: O(1)

/*
    Description:
    *This program calculates the highest power of 2 less than the given n.
    *The idea is to subtract calculate n&(~(n-1)) which would make all bits of the number 0 except the leading 1.
    *Thus the number is reduced to the greatest power of 2 less than it.
*/