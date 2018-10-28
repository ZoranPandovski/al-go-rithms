//Writing a fuction that reverses a string
#include<bits/stdc++.h>
using namespace std;
void reverse(string s){
    char temp;
    float l = (s.length()-1)/2;
    for(int i=0;i<=floor(l);i++){
        temp = s[i];
        s[i] = s[(s.length()-1)-i];
        s[(s.length()-1)-i] = temp;
    }
    cout<<s;
}


int main(){
    //string s = "appledoor";
    string s = "abcdefgh";
    reverse(s);
    return 0;
}
