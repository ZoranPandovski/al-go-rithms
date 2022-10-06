def longest_word_length(input_string):
    #spliting the sentence into words(word definition given below)
    words = input_string.split(" ") 
    #initializing the length with 0
    length = 0 

    for i in words:
        if(length < len(i)): #check for maximum length word
            length = len(i)
    return length

"""
Problem: In a given sentence(string) find the longest word.
(Word is any continuous stream of characters without spaces in between).

Example:
input: "This is the longest sentence"
**Here 'sentence' is longest word with length 8**
output: 8
"""

#drive code
input_string = input()
print(f"The length of the longest word in the given sentence is {longest_word_length(input_string)}")