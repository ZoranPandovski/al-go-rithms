# Stooge Sort

Stooge sort is a recursive sorting algorithm. It is notable for its exceptional bad time complexity of O(nlog 3 / log 1.5 ) = O(n2.7095...). The running time of the algorithm is thus slower compared to reasonable sorting algorithms, and is slower than Bubble sort, a canonical example of a fairly inefficient sort. It is however more efficient than Slowsort. The name comes from The Three Stooges.[1]

The algorithm is defined as follows:

* If the value at the start is larger than the value at the end, swap them.
* If there are 3 or more elements in the list, then:
    * Stooge sort the initial 2/3 of the list
    * Stooge sort the final 2/3 of the list
    * Stooge sort the initial 2/3 of the list again

It is important to get the integer sort size used in the recursive calls by rounding the 2/3 upwards, e.g. rounding 2/3 of 5 should give 4 rather than 3, as otherwise the sort can fail on certain data. However, if the code is written to end on a base case of size 1, rather than terminating on either size 1 or size 2, rounding the 2/3 of 2 upwards gives an infinite number of calls.

![Stooge sort](https://upload.wikimedia.org/wikipedia/commons/f/f8/Sorting_stoogesort_anim.gif)