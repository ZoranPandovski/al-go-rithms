#include<bits/stdc++.h>
using namespace std;

string reverse_number(string s){
    reverse(s.begin(),s.end());
    for(auto it:s){
        if(it<'0'||it>'9') return "Error";
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<reverse_number(s)<<endl;
    return 0;
}
