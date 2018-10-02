
### Z Algorithm String Search

Description given by http://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/


This algorithm finds all occurrences of a pattern in a text in linear time. Let length of text be n and of pattern be m, then total time taken is O(m + n) with linear space complexity.
Now we can see that both time and space complexity is same as KMP algorithm but this algorithm is simpler to understand.

### What is Z Array?

For a string str[0..n-1], Z array is of same length as string. An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1].
The first entry of Z array is meaning less as complete string is always prefix of itself.

Examples:

Pattern: a   a   a   a   a   a

Z array: 0   5   4   3   2   1

Pattern: a   a   b   a   a   c   d

Z array: 0   1   0   2   1   0   0

Pattern: a   b   a   b   a   b   a   b

Z array: 0   0   6   0   4   0   2   0

Pattern: a   a   b   c   a   a   b   x   a   a   a   z

Z array: 0   1   0   0   3   1   0   0   2   2   1   0

### How is Z array helpful in searching pattern in Linear time?

The idea is to concatenate pattern and text, and create a string “P$T” where P is pattern, $ is a special character should not be present in pattern and text, and T is text.
Build the Z array for concatenated string.
In Z array, if Z value at any point is equal to pattern length, then pattern is present at that point.

Example:
Pattern P = "aab",  Text T = "baabaa"

The concatenated string is = "aab$baabaa"

Z array for above concatenated string is

a   a   b   $   b   a   a   b   a   a

0   1   0   0   0   3   1   0   2   1

Since length of pattern is 3, the value 3 in Z array indicates presence of pattern.

The algorithm runs in linear time because we never compare character less than R and with matching we increase R by one so there are at most T comparisons.
In mismatch case, mismatch happen only once for each i (because of which R stops), that’s another at most T comparison making overall linear complexity.

### Animation

http://www.utdallas.edu/~besp/demo/John2010/z-algorithm.htm
