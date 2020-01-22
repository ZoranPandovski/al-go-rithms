/* Author: Codiyapa
   finding factors of a number in O(sqrt(n))
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number\n";
    cin>>n;
    map<int, int>m;
    int i=2, n1=n;
    m[1]=1,
    m[n]=1;
    while(i<=sqrt(n)){
        if(n1%i==0 && n1!=0){
            m[i]=1;
            m[n1/i]=1;
            n1=n1/i;
            continue;
        }
        i++;
    }
    map<int, int>::iterator itr=m.begin();
    while(itr!=m.end()){
        cout<<itr->first<<" ";
        itr++;
    }
    return 0;
}

