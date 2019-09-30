#pragma once

#include <string>
#include <algorithm>
#include <assert.h>

// Write a method to decide if two strings are anagrams or not.
// Following assumptions are taken below:
// 1- Only alphabets are there in strings.
// 2- The alphabet consists of 26 letters, starting from 'a' to 'z'.
// if a non-alphabet character is used the function throws an exception.

static const int ALPHABET_SIZE = 26;

bool isAnagrams(std::string str1, std::string str2) {

	if (str1.length() != str2.length())
		return false;
	
	int strLength = str1.length();

	// Transform characters to lowercase
	std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	// The difference between frequency of each letter in str1 and str2
	int frequencyDiff[ALPHABET_SIZE] = {0};
	
	// Calculating the frequency of letters for str1 and str2
	for (int i = 0; i < strLength; ++i) {
		// str1
		int charValue = static_cast<int>(str1[i]) - 'a';
		assert(charValue >= 0 && charValue < ALPHABET_SIZE);
		frequencyDiff[charValue]++;

		// str2
		charValue = static_cast<int>(str2[i]) - 'a';
		assert(charValue >= 0 && charValue < ALPHABET_SIZE);
		frequencyDiff[charValue]--;
	}

	for (int i = 0; i < ALPHABET_SIZE; ++i) {
		if (ALPHABET_SIZE[i] != 0) {
			return false;
		}
	}
	return true;
}
