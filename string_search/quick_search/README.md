## Quick Search

The algorithm is used to find a substring inside of a string.

### Description

The overall idea is to shift the search window to match the next character in the text with its last occurence in the pattern.

#### Preprocessing

Building the shifting table:
1. Fill with `m+1`, where `m` is the length of pattern
2. For each character `c` in pattern set `shift[c]=m-i`, where `i` is its index in the pattern, starting from 0, so `m-i` is greater by 1 than the index of its last occurence

##### Examples

Alphabet: {a, b, c, d}

Pattern: abc\
Shift: a=3, b=2, c=1, d=4

Pattern: abca\
Shift: a=1, b=3, c=2, d=5

Pattern: abcabc\
Shift: a=4, b=5, c=6, d=7

### Search

Put the search window at the beginning of the text. Check if it matches the pattern. Move search window by `shift[c]`, where `c` is the character next to the window in the text.
