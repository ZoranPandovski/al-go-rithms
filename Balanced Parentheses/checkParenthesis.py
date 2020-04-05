#include<iostream>

#include<string>

#include<stack>

using namespace std;


int braces(char open ,char clos){

if (open =='(' && clos ==')') return true;

else if (open =='[' && clos ==']') return true;

else if (open =='{' && clos =='}') return true;

else if (open =='<' && clos =='>') return true;

return false;

}

int bal_para(string b){

stack<char>a;

for(int i=0;i<b.length();i++)

{

	if (b[i]=='('||b[i]=='{'||b[i]=='['||b[i]=='<') 

		a.push(b[i]);

	else if(b[i]==')'||b[i]=='}'||b[i]==']'||b[i]=='>')

	{

		if (a.empty()||!braces(a.top(),b[i]))

	return false;

		else 

			a.pop();

	}

}

return a.empty();

}


int main()

{

	string c;

	cout<<"\n Enter an string ::\n";

	cin>>c;


	if (bal_para(c)) 

		cout<<"\n String is well parenthesised!!!  :)   \n";

	else 

		cout<<"\n String is Not well Parenthesised!!  :(";

	

	return 0;


}


