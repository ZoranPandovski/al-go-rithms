
### Knuth Morris Pratt String Search

The algorithm is used to find substrings or patterns inside a long string here's a short description
courtesy of https://www.nayuki.io/

### Description 
The key observation in the KMP algorithm is this: If currently we already matched the first k characters of the pattern (with 2 ≤ k < m) but the next character in the text mismatches the next character in the pattern, we don’t necessarily need to restart the match from the beginning of the pattern.

For example, if the pattern is abcabd and we partially matched abcab, if the next character isn’t d then we can shorten the partial match to ab (which is both a prefix and a suffix of abcab) instead of restarting from scratch.

Let s be the currently matched k-character prefix of the pattern. If t is some proper suffix of s that is also a prefix of s, then we already have a partial match for t. Compute the longest proper suffix t with this property, and now re-examine whether the next character in the text matches the character in the pattern that comes after the prefix t. If yes, we advance the pattern index and the text index. If no, we repeat this suffix/prefix process until the prefix is empty and we still fail to match the next character.

Let’s associate a number with each character in the pattern: If we matched the prefix s of the pattern up to and including the character at index i, what is the length of the longest proper suffix t of s such that t is also a prefix of s? We will call this the “longest suffix-prefix” (LSP) table. Note that with 0-based indexing, we have 0 ≤ LSP[i] ≤ i for each i.

Examples:

Pattern: a a a a a
LSP    : 0 1 2 3 4

Pattern: a b a b a b
LSP    : 0 0 1 2 3 4

Pattern: a b a c a b a b
LSP    : 0 0 1 0 1 2 3 2

Pattern: a a a b a a a a a b
LSP    : 0 1 2 0 1 2 3 3 3 4

How do we compute the LSP table? It can be done incrementally with an algorithm very similar to the search algorithm. At each iteration of the outer loop, all the values of lsp before index i need to be correctly computed.

### Animation

https://people.ok.ubc.ca/ylucet/DS/KnuthMorrisPratt.html
