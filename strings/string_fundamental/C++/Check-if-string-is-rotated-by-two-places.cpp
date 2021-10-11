/*Input: string1 = “amazon”, string2 = “azonam” 
Output: Yes 
// rotated anti-clockwise
Input: string1 = “amazon”, string2 = “onamaz” 
Output: Yes 
// rotated clockwise*/

// C++ program to check if a string is two time
// rotation of another string.


//  Code


#include<bits/stdc++.h>
using namespace std;

// Function to check if string2 is obtained by
// string 1
bool isRotated(string str1, string str2){
	if (str1.length() != str2.length())
		return false;
	if(str1.length()<2){
	return str1.compare(str2) == 0;
	}
	string clock_rot = "";
	string anticlock_rot = "";
	int len = str2.length();

	// Initialize string as anti-clockwise rotation
	anticlock_rot = anticlock_rot +
					str2.substr(len-2, 2) +
					str2.substr(0, len-2) ;

	// Initialize string as clock wise rotation
	clock_rot = clock_rot +
				str2.substr(2) +
				str2.substr(0, 2) ;

	// check if any of them is equal to string1
	return (str1.compare(clock_rot) == 0 ||
			str1.compare(anticlock_rot) == 0);
}

int main(){
	string str1 = "geeks";
	string str2 = "eksge";

	isRotated(str1, str2) ? cout << "Yes" : cout << "No";
	
	return 0;
}
