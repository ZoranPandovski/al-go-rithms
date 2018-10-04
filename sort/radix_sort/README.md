### Radix Sort
Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value. Radix sort uses counting sort as a subroutine to sort.

##### Complexity Analysis:
The complexity is O((n+b)∗log<sub>b</sub>(maxx)) where b is the base for representing numbers and maxx is the maximum element of the input array. This is clearly visible as we make (n+b) iterations log<sub>b</sub>(maxx) times (number of digits in the maximum element). If maxx≤n<sup>c</sup>, then the complexity can be written as O(n∗log<sub>b</sub>(n)).

##### Graphical examples of Radix Sort
https://www.youtube.com/watch?v=nu4gDuFabIM

https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
