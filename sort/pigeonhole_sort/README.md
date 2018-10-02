### Pigeonhole sort
Pigeonhole sort is a sorting algorithm that is suitable for sorting lists of elements where the number of elements (n) and the length of the range of possible key values (N) are approximately the same. It requires O(n + N) time. It is similar to counting sort, but differs in that it "moves items twice: once to the bucket array and again to the final destination whereas counting sort builds an auxiliary array then uses the array to compute each item's final destination and move the item there.

The pigeonhole algorithm works as follows:
1. Given an array of values to be sorted, set up an auxiliary array of initially empty "pigeonholes," one pigeonhole for each key through the range of the original array.
2. Going over the original array, put each value into the pigeonhole corresponding to its key, such that each pigeonhole eventually contains a list of all values with that key.
3. Iterate over the pigeonhole array in order, and put elements from non-empty pigeonholes back into the original array.