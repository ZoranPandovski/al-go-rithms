#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(char* a){
	stack<char> s;
	for(int i=0;a[i]!='\0';i++){
		char ch=a[i];

		switch(ch){
			case '(':
			case '{':
			case '[': s.push(ch);
			break;
			case ')': if(!s.empty() && s.top()=='('){
						s.pop();
						break;
			        }
			        else{
			        	return false;
			        }
            case '}': if(!s.empty() && s.top()=='{'){
						s.pop();
						break;
			        }
			        else{
			        	return false;
			        }
			case ']': if(!s.empty() && s.top()=='['){
						s.pop();
						break;
			        }
			        else{
			        	return false;
			        }              
		}
	}
	return s.empty();
}

int main()
{
	stack<int>s;
    char a[]="{a+[b+(c+d)]+(e+f)}";
	if(isbalanced(a)){
		cout<<"Balanced."<<endl;
	}
	else{
		cout<<"Not balanced."<<endl;
	}
return 0;
}
