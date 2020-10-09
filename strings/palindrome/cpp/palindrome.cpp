// C++ Program To Check Whether String is Palindrome or Not 
// Without using STL.

/*
	Test Cases :
		Input : radar
		Output : Palindrome

		Input : madam
		Output : Palindrome

		Input : classroom
		Output : Not a Palindrome
*/

#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str1[20], str2[20];
    
    int i, j, len = 0, flag = 0;
    
    cout << "Enter A String : ";
    gets(str1);
    
    len = strlen(str1) - 1;
    
    for (i = len,j = 0; i>=0; i--, j++)
        str2[j] = str1[i];
        
    if (strcmp(str1, str2))
        cout << str1 << " is Not a Palindrome";
    else
        cout << str1 << " is a Palindrome";
        
    return 0;
}
