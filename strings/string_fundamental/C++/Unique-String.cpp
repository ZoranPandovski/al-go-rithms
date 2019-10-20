// Finding if a string has unique character or not
#include<bits/stdc++.h>
using namespace std;
bool unique_char(string s){
    sort(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
        if(s[i]==s[i+1])
            return false;
    return true;
}

bool unique_char_new(string s){
    int uniqueChar = 256;
    if(s.length()>uniqueChar)
        return false;
    
    bool charac[uniqueChar] = {0};
    for(int i=0;i<s.length();i++){
        if(charac[int(s[i])]==true)
                return false;
        charac[int(s[i])]=true;
     }
    return true;
}

int main(){
    string s = "appledoor";
    //string s = "abcdefgh";
    if(unique_char_new(s))
        cout<<"All Unique Characters";
    else
        cout<<"Has Duplicates";
    return 0;
}