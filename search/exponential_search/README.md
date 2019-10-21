### Exponential search

Exponential search allows for searching through a sorted, unbounded list for a specified input value (the search "key"). The algorithm consists of two stages. The first stage determines a range in which the search key would reside if it were in the list. In the second stage, a binary search is performed on this range. In the first stage, assuming that the list is sorted in ascending order, the algorithm looks for the first exponent, j, where the value 2j is greater than the search key. This value, 2j becomes the upper bound for the binary search with the previous power of 2, 2j - 1, being the lower bound for the binary search.

![](https://upload.wikimedia.org/wikipedia/commons/4/45/Exponential_search.svg)
