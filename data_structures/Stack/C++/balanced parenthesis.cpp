#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int flag=1;
    stack <char> s;
    for (int i=0;i<str.length();i++){
        if (str[i]=='('||str[i]=='{'||str[i]=='[') s.push(str[i]);
        if (str[i]==')'||str[i]=='}'||str[i]==']'){
            if (s.empty()) flag=0;
            else{
                char temp=s.top();
                if (str[i]==')' && (temp=='{'||str[i]=='[')) flag=0;
                if (str[i]=='}' && (temp=='('||str[i]=='[')) flag=0;
                if (str[i]==']' && (temp=='{'||str[i]=='(')) flag=0;
                else s.pop();
            }
        }
    }
    if (!s.empty()) flag=0;
    if (flag==1) cout<<"valid"<<endl;
    else cout<<"invalid"<<endl;
}
