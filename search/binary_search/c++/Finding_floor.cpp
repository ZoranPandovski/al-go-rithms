/*Given an array, you have to find the floor of a number x. 
The floor of a number x is nothing but the largest number in the array less than or equal to x.*/


#include<bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define pb push_back
 
const double EPS = 1e-12;
const int N = 1e6 + 5;
//Just A Gentle Reminder about MOD
const int mod = 1e9 + 7;

static vector<vector<int>> result;
int main(){
    fast;
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int t;
    cin>>t;
    while(t--){
        int i=0,j=n-1;
        int q;
        cin>>q;
        int flag=0;
        int max=INT32_MIN;
        while(i<=j){
            int mid=(i+j)/2;
            if(a[mid]==q){
                cout<<q<<endl;
                flag=1;
                break;
            }
            if(a[mid]<q){
                max=a[mid];
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }    
        if(flag==0){
            cout<<max<<endl;
        }
        }
    return 0;
}