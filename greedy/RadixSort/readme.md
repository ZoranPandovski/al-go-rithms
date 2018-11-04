# Radix Sort

The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(nLogn), i.e., they cannot do better than nLogn.
Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in range from 1 to k.

>.
Example:
Original, unsorted list: 170, 45, 75, 90, 802, 24, 2, 66
>
Sorting by least significant digit (1s place) gives:

>.
170, 90, 802, 2, 24, 45, 75, 66

>.
>observe that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75