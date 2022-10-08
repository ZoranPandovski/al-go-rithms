# Suffix array is widely used in areas dealing with string matching such as bioinformatics.

# Suffix array is an array of starting indexes of all substrings of a given string sorted lexicographically.
# Example:
# For a string 'ababba', all substrings are:
#  'ababba', 'babba', 'abba', 'bba', 'ba', 'a'
# 
# In lexicographically sorted order we get: 
#  'a', 'ababba', 'abba', 'ba', 'babba', 'bba'

# Which corresponds to an array of starting indexes: 
#  5, 0, 2, 4, 1, 3

# '$', a special character (or any other that is Lexicographically smaller than all the characters in a string) is added to the end of the string to indicate the end of the string and to allow then making length of all substrings the same, which account for sorting optimization in this implementation. It is a part of implementation and does not affect the eventual use cases for the resulting array.
#  Our string becomes 'ababba$', that's why we see 6 as the first element of our suffix array for given example string.
#  [6, 5, 0, 2, 4, 1, 3]

# In some implementations of function that builds suffix array, however, special character is not used (as explained in GeeksForGeeks Suffix Array article, for example).

#  Building suffix array is useful in coding problems where preprocessing of a given string by building a suffix array allows to answer queries in O(1) time and not to traverse the string linearly to answer each query.
# Benefit is that once it keeps starting indexes of all substrings sorted, one can use Binary search on a suffix array and get O(log(n)) complexity instead of O(n) 
# Problems like : Finding the smallest cyclic shift, Longest common prefix, Lexicographical substring search are example problems that can be solved effectively using suffix array.

class suffix:
    def __init__(self):
        self.index = 0
        self.rank = [0, 0]

def buildSuffixArray(s):
    s = s + '$'
    suffixes = [suffix() for _ in range(len(s))]
    for i in range(len(s)):
        suffixes[i].index = i
        suffixes[i].rank[0] = ord(s[i]) - ord('a')
        suffixes[i].rank[1] = ord(s[i+1]) - ord('a') if i+1<len(s) else -1
    suffixes = sorted(suffixes, key = lambda x : (x.rank[0], x.rank[1]))
    ind = [0]*len(s)
    k = 4
    while(k < 2*len(s)):
        rank = 0
        prevRank = suffixes[0].rank[0]
        ind[suffixes[0].index] = 0
        for i in range(1, len(s)):
            if (suffixes[i].rank[0] == prevRank and suffixes[i].rank[1] == suffixes[i-1].rank[1]):
                prevRank = suffixes[i].rank[0]
                suffixes[i].rank[0] = rank
            else:
                prevRank = suffixes[i].rank[0]
                rank+=1
                suffixes[i].rank[0] = rank
            ind[suffixes[i].index] = i
        for i in range(len(s)):
            nextIndex = suffixes[i].index + k//2
            suffixes[i].rank[1] = suffixes[ind[nextIndex]].rank[0] if (nextIndex < len(s)) else -1
        suffixes = sorted(suffixes, key = lambda x : (x.rank[0], x.rank[1]))
        k*=2
    suffixArr = [0]*len(s)
    for i in range(len(s)):
        suffixArr[i] = suffixes[i].index
    return suffixArr

# Tests
def testbuildSuffixArray():
    suffixArrayTestData = {
        'ababba': [6, 5, 0, 2, 4, 1, 3],
        'aaaa': [4, 3, 2, 1, 0],
        'ppppplppp': [9, 5, 8, 4, 7, 3, 6, 2, 1, 0],
        'nn': [2, 1, 0]
    }
    for testInput in suffixArrayTestData:
        testOutput = suffixArrayTestData[testInput]
        assert buildSuffixArray(testInput) == testOutput, f"Test failed: for string {testInput}. Expected output is {' '.join(str(e) for e in testOutput)}, got: {' '.join(str(e) for e in buildSuffixArray(testInput))}"

testbuildSuffixArray() # all tests pass: no exception raised

# Driver code for reading from stdin that outputs constructed suffix array: 
# s = input()
# print(buildSuffixArray(s))

