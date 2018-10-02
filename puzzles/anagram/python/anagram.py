def isAnagram(string1, string2):
    """Checks if two strings are an anagram

    An anagram is a word or phrase formed by rearranging the letters
    of a different word or phrase.

    This implementation ignores spaces and case.

    @param string1 The first word or phrase
    @param string2 The second word or phrase
    @return A boolean representing if the strings are an anagram or not
    """
   
    # Remove spaces
    str1_nospace = string1.replace(" ", "")
    str2_nospace = string2.replace(" ", "")

    # Convert to lowercase and sort
    list1 = list(str1_nospace.lower())
    list1.sort()
    list2 = list(str2_nospace.lower())
    list2.sort()

    # Check for equality
    return (list1 == list2)

# Test cases
assert isAnagram('chair', 'archi') == True
assert isAnagram('Elbow', 'Below') == True
assert isAnagram('More', 'Moore')  == False
assert isAnagram('Johnathan', 'Jonathan')   == False
assert isAnagram('Dormitory', 'Dirty Room') == True
assert isAnagram('Conversation', 'Voices rant on') == True
