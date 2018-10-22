// Program which converts infix expression into postfix .. !



#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
char infix[MAX], postfix[MAX], STACK[MAX], ch;
int i,j,pr,top=-1;
char pop();
void push(char elem);
int pre(char ch);

void main()
{
  printf("\n Enter the infix expression \n");
  scanf("%s",infix);
  // '#' is the identification element. if top reaches '#', that means the array postfix is empty.  
  push('#');                            
  while(ch==infix[i++]!='\0')
  {
    if(isalnum(ch))                             
    {
      postfix[j++]=ch;
    }
    else if(ch=='(')
    {
      push(ch);
    }
    // when ')' appears, the elements which is there inside '()' will be moved to   postfix array !
    else if(ch==')')                   
    {
      while(STACK[top]!='(')
      {
        postfix[j++]=pop();
      }
      pop();
    }
    else
    {
      pr=pre(ch);
      if(ch=='^')
      {
        pr++;
      }
      while(pre(STACK[top])>=pr)
      {
        postfix[j++]=pop();
      }
      push(ch);
    }
  }
  while(STACK[top]!='#')
  {
    postfix[j++]=pop();
  }
  postfix[j]='\0';
  printf("\n The postfix Expression is : \n ")
  printf("%s\n",postfix);
}

int pre(char ch)
{
  // returning values according to thier priority..!!
  switch(ch)                               
  {
    case '+' :
    case '-' : return 2;
    case '*' :
    case '/' : 
    case '%' : return 3;
    case '^' : return 4;
    case '#' : return 0;
    case '(' : return 1;
    default : printf("\n INVALID ENTRY !! \n");
              exit(0);
  }
}
void push(char ele)
{
  STACK[++top]=ele;
}
char pop()
{
  return(STACK[top--]);
}

    
/* OUTPUT :
   
1.   Enter the infix expression
     (a+b)
     The postfix Expression is :
     ab+
   
2.   Enter the infix expression
     a/b*c+e
     The postfix Expression is :
     ab/c*e+
     
3.   Enter the infix expression
     a$b
     INVALID ENTRY !!
*/
      
      
      
      
    
    
