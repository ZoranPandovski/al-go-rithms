# Aho Corasick  
Aho Corasick is a string searching algorithm very similar to [KMP](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm) but allows to match multiple patterns at the same time. The idea is the same as in KMP, calculate a fail function for a position of the current matching process, but in this case, we use a Trie instead of an array to store this function.

The implementation is divided into three parts:  
1. Create a Trie with the patterns  
2. Do a BFS to find the fail function  
3. Search for pattern matching in a text  

## Complexity
The complexity of the algorithm is linear in the sum of lengths of the patterns, plus the length of the text plus the number of matches.

## Implementation
The implementation follows the following format  

k  
pattern1  
pattern2  
...  
patternk  
text

Where k is the number of patterns, and the 
 text and patterns are strings composed of English lowercase letters.

## Sample input
5  
abc  
aa  
zaa  
zaabc  
bc  
aazaabcaaaaaaabdbcabczaabc  

## Sample output
Pattern aa find in range [0-1]  
Pattern zaa find in range [2-4]  
Pattern aa find in range [3-4]  
Pattern zaabc find in range [2-6]  
Pattern abc find in range [4-6]  
Pattern bc find in range [5-6]  
Pattern aa find in range [7-8]  
Pattern aa find in range [8-9]  
Pattern aa find in range [9-10]  
Pattern aa find in range [10-11]  
Pattern aa find in range [11-12]  
Pattern aa find in range [12-13]  
Pattern bc find in range [16-17]  
Pattern abc find in range [18-20]  
Pattern bc find in range [19-20]  
Pattern zaa find in range [21-23]  
Pattern aa find in range [22-23]  
Pattern zaabc find in range [21-25]  
Pattern abc find in range [23-25]  
Pattern bc find in range [24-25]  

## More Info
[Aho-Corasick](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm)
