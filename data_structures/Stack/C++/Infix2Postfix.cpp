#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack<char> operatorStack;
int length;

int priority(char Operator){
	if(Operator=='^')
		return 3;
 	if(Operator=='*' || Operator=='/')
		return 2;
	if(Operator=='+'|| Operator=='-')
		return 1;
	return-1;
}

bool isOperand(char currentChar){
return ((currentChar>=65 && currentChar<=90)||(currentChar>=97 && currentChar<=122));
}

void infix2postfix(char infix[]){
	char postfix[10000]={0};
	char currentChar;
	int i=0,j=0;
	while(length--){
		currentChar = infix[i];
		if(isOperand(currentChar)){
			postfix[j++] = currentChar;
		}
		else{
			if(currentChar=='('){
				operatorStack.push(currentChar);
			}
			else if(operatorStack.empty() && currentChar!=')'){
				operatorStack.push(currentChar);
			}
			else if(currentChar==')'){
				while(!operatorStack.empty()){
				if(operatorStack.top()=='('){
					operatorStack.pop();
					break;
				}
				else{
					postfix[j++] = operatorStack.top();
					operatorStack.pop();
				}
			}
			}
			else{
				if(priority(currentChar)>priority(operatorStack.top())){
					operatorStack.push(currentChar);
				}
				else{
					while(!operatorStack.empty()){
						if(operatorStack.top()=='('){
							operatorStack.pop();
							break;
						}
						else{
							postfix[j++] = operatorStack.top();
							operatorStack.pop();
						}
					}
					operatorStack.push(currentChar);
				}
			}
		}
		i++;
	}
	while(!operatorStack.empty()){
		postfix[j++] = operatorStack.top();
		operatorStack.pop();
	}
	postfix[j]='\0';
	cout<<postfix<<endl;

}
int main(){
	char infix[4000];
	int testCases;
	cin>>testCases;
	while(testCases--){
		cin>>infix;
		length = strlen(infix);
		infix2postfix(infix);
	}
	return 0;
}
