#pragma once

#include <string>
#include <algorithm>

//Write a method to decide if two strings are anagrams or not.
//Following assumptions are taken below:
//1) Only alphabets are there in strings.
//Using XOR property A^A = 0

bool isAnagrams(std::string str1, std::string str2){

	if (str1.length() != str2.length())
		return false;

	int check1 = 0;

	//Transform characters to lowercase
	std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

	//collecting str1 alphabets ascii value in check1
	for (int i = 0; i < str1.length(); ++i){
		int asciiVal = static_cast<int>(str1[i]) - 'a';

		check1 |= (1 << asciiVal);
	}

	int check2 = 0;

	//collecting str2 alphabets value in check2
	std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	for (int i = 0; i < str2.length(); ++i){
		int asciiVal = static_cast<int>(str2[i]) - 'a';

		check2 |= (1 << asciiVal);
	}

	//if both strings has same characters then A ^ A will result 0
	if ((check1 ^ check2) == 0)
		return true;

	return false;
}
