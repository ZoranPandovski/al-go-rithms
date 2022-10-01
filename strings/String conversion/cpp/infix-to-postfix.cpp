// C++ Program To Convert Infix to Postfix using Stack

/*
	Test Case : 
		Input : a*(5+(c+7)*(e+f)/2)*h
		Output : a5c7+ef+*2/+*h*
*/

#include<bits/stdc++.h>

using namespace std;

const int size = 50;
char infix[size], postfix[size], STACK[size];
int top = -1;

// Function to Get Precedence of Operator
int precedence(char ch)
{
	switch(ch)
	{
		case '^': return 5;
		case '/': return 4;
		case '*': return 4;
		case '+': return 3;
		case '-': return 3;
		default: return 0;
	}
}

// Function to Pop an Element from the Stack
char pop()
{
	char ret;
	if(top != -1)
	{
		ret = STACK[top];
		top--;
		return ret;
	}
	else
		return '#';
}

// Function to Return Top Element from Stack Without Popping
char topElement() 
{
	char ch;
	if(top != -1)	
		ch = STACK[top];
	else
		ch = '#';
		
	return ch;
}

// Function to Push an Element into the Stack
void push(char ch)
{
	if(top != size-1)
	{
		top++;
		STACK[top] = ch;
	}
}

// Function to Match The Number of Braces
int braces(char *s)
{
	int left=0, right=0;
	
	for(int i=0; s[i]; ++i)
	{
		if(s[i] == '(')
			left++;
		else if(s[i] == ')')
			right++;
	}
	if(left == right)
		return 0;
	else if(left < right)
		return 1;
	else
		return -1;
}

// Driver's Code
int main()
{
	char ele, elem, st[2];
	int prep, pre, popped, j=0, chk=0;
	strcpy(postfix, " ");
	system("cls");
	cout << "ASSUMPTION \nThe Infix Expression contains Single Letter variables\nand Single Digit Constants only.\n\n";
	cout << "Enter Infix Expression : ";
	gets(infix);
	
	chk = braces(infix);
	
	if(chk != 0)
	{
		cout << "Unbalanced Number of Braces.\n Extra ";
		cout << ( chk == 1 ? "right braces" : "left braces" ) << endl;
		system("pause");
		exit(1);
	}
	
	for(int i=0; infix[i] != '\0'; ++i)
	{
		if( infix[i] != '(' && infix[i] != ')' && infix[i] != '^' && infix[i] != '*' && infix[i] != '/' 
			&& infix[i] != '+' && infix[i] != '-')
			postfix[j++] = infix[i];
		else if( infix[i] == '(')
		{
			elem = infix[i];
			push(elem);
		}
		else if( infix[i] == ')')
		{
			while( (popped = pop()) != '(')
			{
				postfix[j++] = popped;
			}
		}
		else
		{
			elem = infix[i];
			pre = precedence(elem);
			ele = topElement();
			prep = precedence(ele);
			
			if(pre > prep)
				push(elem);
			else
			{
				while(prep >= pre)
				{
					if(ele == '#')
						break;
					popped = pop();
					ele = topElement();
					postfix[j++] = popped;
					prep = precedence(ele);
				}
				push(elem);
			}
		}
	}
	
	while( (popped = pop()) != '#')
	{
		postfix[j++] = popped;
	}
	postfix[j] = '\0';
	
	cout << "Postfix : " << postfix << endl;
	system("pause");
	
	return 0;
}
