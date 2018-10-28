### Cycle sort
Cycle sort is an in-place, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes to the original array, unlike any other in-place sorting algorithm. It is based on the idea that the permutation to be sorted can be factored into cycles, which can individually be rotated to give a sorted result.

Unlike nearly every other sort, items are never written elsewhere in the array simply to push them out of the way of the action. Each value is either written zero times, if it's already in its correct position, or written one time to its correct position. This matches the minimal number of overwrites required for a completed in-place sort.

To illustrate the idea of cycle sort, consider a list with distinct elements. Given an element a, we can find the index at which it will occur in the sorted list by simply counting the number of elements in the entire list that are smaller than a. Now

1. If the element is already at the correct position, do nothing.
2. If it is not, we will write it to its intended position. That position is inhabited by a different element b, which we then have to move to its correct position. This process of displacing elements to their correct positions continues until an element is moved to the original position of a. This completes a cycle.

Repeating this process for every element sorts the list, with a single writing operation if and only if an element is not already at its correct position. While computing the correct positions takes O(n) time for every single element, thus resulting in a quadratic time algorithm, the number of writing operations is minimized.