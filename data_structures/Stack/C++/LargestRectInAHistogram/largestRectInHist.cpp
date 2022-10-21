#include<iostream>
#include<deque>
#include<stack>
#include<math.h>
using namespace std;

//brute force:
int largestRect(int arr[], int n){
    int area = -1;
    for(int i=0; i<n; i++){
        int minH = 100000000;
        for(int j=i+1; j<n; j++){
            minH = min(arr[j], minH);
            area = max(area, (j - i )*minH);
        }
    }

    return area;
}


//optimised:
int largestRect2(int arr[], int n){
    stack<int> st;
    int area = -1;
    for(int i=0; i<n; i++){

        if(st.empty()){
            st.push(i);
            continue;
        }

        while(!st.empty() && arr[st.top()] > arr[i]){
            area = max(area, arr[st.top()] * (i- st.top()));
            st.pop();
        }

    }
    return area;
}

int main(){
    int arr[] = {2, 1, 5, 6, 2, 3};

    cout<<largestRect(arr, 6)<<endl;
    cout<<largestRect2(arr, 6)<<endl;

    return 0;
}