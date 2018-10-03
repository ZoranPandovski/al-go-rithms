#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> operatorStack;
int length;

void postfix2infix(char postfix[]){
  char currentChar;
  int i=0,j=0;
  int a,b,result;
  while(length--){
    currentChar = postfix[i];
    if(isdigit(currentChar)){
      operatorStack.push(currentChar-'0');
    }
    else if(currentChar=='+'||currentChar=='-'||currentChar=='*'||currentChar=='/')
    {
      a = operatorStack.top();
      operatorStack.pop();
      b = operatorStack.top();
      operatorStack.pop();
      switch(currentChar){
        case '+':{
          result = a+b;
          break;
        }
        case '-':{
          result = b-a;
          break;
        }
        case '*':{
          result = a*b;
          break;
        }
        case '/':{
          result = b/a;
          break;
        }
      }
      operatorStack.push(result);
    }
    i++;
  }
int temp = operatorStack.top();
  operatorStack.pop();
cout<<temp<<endl;
}

int main(){
  char postfix[4000];
  int testCases;
  cin>>testCases;
  while(testCases--){
    cout<<"enter the postfix expression";
    cin>>postfix;
    length = strlen(postfix);
    postfix2infix(postfix);
  }
  return 0;
}
