#include <bits/stdc++.h>
using namespace std;

int sum_arr(int freq[], int i, int j){
    int sum = 0;    
    for(int k=i; k<=j; k++){
        sum+=freq[k];
    }
    return sum;
}
int optimal_binary_tree(int arr[], int freq[], int n){
    /*int sum_arr[n+1];
    sum_arr[0]=0;
    for(int i=1; i<=n; i++){
        sum_arr[i] = sum_arr[i-1] + freq[i-1];
    }
    for(int i=0; i<=n; i++)
        cout<<sum_arr[i]<<" ";
    cout<<endl;*/
    int dp[n][n];
    for(int i=0; i<n; i++)
        dp[i][i] = freq[i];

    for(int l=2; l<=n; l++){
        for(int i=0; i<=n-l; i++){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<=j; k++){
                int sum = sum_arr(freq, i, j) + ((k>i)? dp[i][k-1]:0) + ((k<j)? dp[k+1][j]:0);
                if(sum<dp[i][j])
                    dp[i][j] = sum;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}
int main(){
    int n;
    cout<<"Enter the no. of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter array of elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"\nEnter the search frequencies for each element: ";
    int freq[n];
    for(int i=0; i<n; i++)
        cin>>freq[i];
    
    int optimal_cost = optimal_binary_tree(arr, freq, n);
    cout<<"\nOptimal cost: "<<optimal_cost<<endl;
    return 0;
}
