// C++ implementation of Atbash Cipher
#include<bits/stdc++.h>
using namespace std;

// Creating a array of upper case alphabets
char upper_case[]={'Z', 'Y', 'X', 'W', 'V', 'U',
 				   'T', 'S', 'R', 'Q', 'P', 'O',
				   'N', 'M', 'L', 'K', 'J', 'I', 
				   'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

// Creating a array of lower case alphabets				   
 char lower_case[]={'z', 'y', 'x', 'w', 'v', 'u',
  					't', 's', 'r', 'q', 'p', 'o',
					'n', 'm', 'l', 'k', 'j', 'i',
					'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};     

// Encryption and Decryption function
void atbash(string message)
{
	int len = message.size();                   // Calculating lenght of the string
	string cipher;
	int ascii_char;
	for(int i=0;i<len;i++)
	{
		
		ascii_char = message[i];                         // Storing ASCII value of alphabet
		if(ascii_char>='A' && ascii_char<='Z')
		cipher = cipher + upper_case[ascii_char-65];    // If character is in upper case(minus 65 from its ASCII value to get reversed character)
		else
		cipher = cipher + lower_case[ascii_char-97];    // If character is in upper case(minus 97 from its ASCII value to get reversed character)
			
	}
	cout<<"Atbash Cipher - "<<cipher<<endl;
}
// Driver program(Main function)
int main()
{
	atbash("Atbash Cipher");
	atbash("Cryptography");
	atbash("Github");
	cout<<endl;
	cout<<"Decrypted ciphers"<<endl;
	atbash("Zgyzhs Xrksvi");
	atbash("Xibkgltizksb");
	atbash("Trgsfy");
	return 0;
}
