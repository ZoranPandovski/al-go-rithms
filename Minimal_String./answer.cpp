/*
  The problem is:
  given a l and r, length of the input and number of repetitions requerides, respectively, print the minimal string whose have the input as substring.
  exemple:
  3 4
  aba
  ababababa
*/
#include <bits/stdc++.h>
using namespace std;
string frase;
int av = 0,t,n,fim;
int main(){
	cin>>t>>n>>frase;
	for(int a = 1; a < frase.length(); a++){
		for(int b = 0; b < frase.length() && !fim ; b++){
			if(a+b > frase.length()-1)
				break;
			else if(!(frase[a+b] == frase [b%(frase.length())]))
				fim = 1;
		}
	if(!fim){
		av = a;
		break;	
	}else fim = 0;
	}
	cout<<frase;
	if(!av)
		for(int a = 1; a < n; a++)cout<<frase;
	else
		for(int a = 1; a < n; a++)
			for(int b = 0; b < av; b++)
				cout<<frase[frase.length()-av+b];
	cout<<endl;	
}
