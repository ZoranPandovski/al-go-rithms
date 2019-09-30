# Bubble sort

*Note:- Files **bubble_sort_nonOptimized.cpp** and **bubble_sort_optimized.cpp** contains both the version of Bubble sort optimized and non-optimized version. 
You will see that the number of swaps in optimized algorithm are less than non-optimized version.*
### Introduction :
**Bubble sort**, sometimes referred to as **sinking sort**, is a simple [Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) that repeatedly steps through the list to be sorted, compares each pair of adjacent items and [swaps](https://en.wikipedia.org/wiki/Swap_(computer_science)) them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted. The algorithm, which is a [comparison sort](https://en.wikipedia.org/wiki/Comparison_sort), is named for the way smaller or larger elements "bubble" to the top of the list. Although the algorithm is simple, it is too slow and impractical for most problems even when compared to  [insertion sort](https://en.wikipedia.org/wiki/Comparison_sort).Bubble sort can be practical if the input is in mostly sorted order with some out-of-order elements nearly in position.
#### Performance :

Bubble sort has a **worst-case and average complexity of _[О](https://en.wikipedia.org/wiki/Big_o_notation)_(_n^2),where _n_ is the number of items being sorted.** Most practical sorting algorithms have substantially better worst-case or average complexity, often _O_(_n_ log _n_). Even other _О_(n^2) sorting algorithms, such as [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort), generally run faster than bubble sort, and are no more complex. Therefore, bubble sort is not a practical sorting algorithm.

The only significant advantage that bubble sort has over most other algorithms, even [quicksort](https://en.wikipedia.org/wiki/Quicksort), but not [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort), is that the ability to detect that the list is sorted efficiently is built into the algorithm. When the list is already sorted (best-case), the complexity of bubble sort is only _O_(_n_). By contrast, most other algorithms, even those with better [average-case complexity](https://en.wikipedia.org/wiki/Average-case_complexity), perform their entire sorting process on the set and thus are more complex. However, not only does [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) share this advantage, but it also performs better on a list that is substantially sorted (having a small number of [inversions](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)).

Bubble sort should be avoided in the case of large collections. It will not be efficient in the case of a reverse-ordered collection.
#### 

Following are the Time and Space complexity for the Bubble Sort algorithm.


- Worst Case Time Complexity [ Big-O ]: **O(n2)**
- Best Case Time Complexity [Big-omega]: **O(n)**
- Average Time Complexity [Big-theta]: **O(n2)**
- Space Complexity: **O(1)**



Here is a Gif presentation for Bubble sort Algorithm.

![Alt Text](https://upload.wikimedia.org/wikipedia/commons/0/06/Bubble-sort.gif)




