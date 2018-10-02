"""
 An anagram of a string is another string that contains same characters, only the order of characters can be different.
 For example "qwerty" and "werqty" are anagrams of each other.
 Below methods uses two lists to store the count of every character in respective strings which will be used to determine whether provided strings 
 are anagram or not.

"""

#Function to count of each character in string
def count_chars(string_to_be_evaluated):
    count=[0]*26
    string_to_be_evaluated=string_to_be_evaluated.lower()
    for char in string_to_be_evaluated:
        value=97-ord(char)
        count[value]=count[value]+1
    return count

#Function to check anagram of a string
def check_anagram(string_one,string_two):
    count1=count_chars(string_one)
    count2=count_chars(string_two)
    if count1==count2:
        return True
    return False

if __name__ == '__main__':
    string_one=input("Enter first string:")
    string_two=input("Enter second string:")
    is_anagram=check_anagram(string_one,string_two)
    if is_anagram:
        print("Provided strings are anagram.")
    else:
        print("Provided strings are not anagram.")

