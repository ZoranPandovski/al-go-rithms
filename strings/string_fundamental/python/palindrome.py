"""
 A palindrome is a word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run.
"""

# Function to check if string is a palindrome
def check_palindrome(str):
    str = str.lower()
    rev = str[::-1]
    if (str == rev):
        return True
    else:
        return False

    

if __name__ == '__main__':
    string_one = input("Enter string to check if it's a palindrome:")
    is_p = check_palindrome(string_one)
    if is_p:
        print("The string is a palindrome")
    else:
        print("The string is not an palindrome.")
