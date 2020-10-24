"""
 AAn isogram is a word that has no repeating letters, consecutive or non-consecutive. 
 For example "something" and "brother" are isograms, where as "nothing" and "sister" are not.
 Below method compares the length of the string with the length (or size) of the set of the same string.
 The set of the string removes all duplicates, therefore if it is equal to the original string, then its an isogram
"""

# Function to check if string is an isogram
def check_isogram(string_to_be_evaluated):
    if len(string_to_be_evaluated) == len(set(string_to_be_evaluated.lower())):
        return True
    return False

if __name__ == '__main__':
    string_one = input("Enter string to check if it's an isogram:")
    is_isogram = check_isogram(string_one)
    if check_isogram:
        print("The string has no repeated letters and is therefore an Isogram.")
    else:
        print("The string is not an Isogram.")
