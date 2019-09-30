# TIMSORT

Timsort is a hybrid stable sorting algorithm, derived from merge sort and insertion sort, designed to perform well on many kinds of real-world data. It uses techniques from Peter McIlroy's "Optimistic Sorting and Information Theoretic Complexity", in Proceedings of the Fourth Annual ACM-SIAM Symposium on Discrete Algorithms, pp. 467–474, January 1993.

It was implemented by Tim Peters in 2002 for use in the Python programming language. The algorithm finds subsequences of the data that are already ordered, and uses that knowledge to sort the remainder more efficiently. This is done by merging an identified subsequence, called a run, with existing runs until certain criteria are fulfilled.
Timsort has been Python's standard sorting algorithm since version 2.3.

## Operation

Basically, it works mixing Insertion Sort and Merge sort

1. A stable sorting algorithm works in O(n Log n) time
2. Used in Java’s Arrays.sort() as well as Python’s sorted() and sort().
3. First sort small pieces using Insertion Sort, then merges the pieces using merge of merge sort.

We divides the Array into blocks known as Run. We sort those runs using insertion sort one by one and then merge those runs using combine function used in merge sort. If size of Array is less than run, then Array get sorted just by using Insertion Sort. The size of run may vary from 32 to 64 depending upon size of array. Note that merge function performs well when sizes subarrays are powers of 2. The idea is based on the fact that insertion sort performs well for small arrays.

![Timsort](https://thumbs.gfycat.com/BruisedFrigidBlackrhino-size_restricted.gif)
