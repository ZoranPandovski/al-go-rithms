"""
What is Anagram?
	An anagram of a string is another string that contains same characters,
	only the order of characters can be different.
		For example, “abcd” and “dabc” are anagram of each other.

Method #Bit Manipulation:
If we start at a value of 0 and XOR all the characters of both strings, we should return an end value of 0 if they are anagrams because there would be an even occurrence of all characters in the anagram.
Done forget to defend the code by validating inputs.

Time Complexity: O(n)
Space Complexity: O(1)
"""

str1 = input(); #abcd
str2 = input(); #dabc

def isAnagram(srt1,str2):

	if len(str1)!=len(str2):
		return False
	else:
		value=0
		for i in range(len(str1)):
			value^=ord(str1[i])^ord(str2[i])   #ord() return Ascii value of character like 'a'->97,'A'->65 etc.
		if value==0:
			return True
		else:
			return False


result=isAnagram(str1,str2)
print(result)




