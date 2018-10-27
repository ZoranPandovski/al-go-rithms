### Quick sort

Quick sort is a highly efficient sorting algorithm and is based on partitioning of array of data into smaller arrays. A large array is partitioned into two arrays one of which holds values smaller than the specified value, say pivot, based on which the partition is made and another array holds values greater than the pivot value.Quick sort partitions an array and then calls itself recursively twice to sort the two resulting subarrays. This repeats until there are 2 or less numbers being sorted, then they are compared and returned to the array recursively.

The time complexity of Quick Sort is O n log(n).

#### A graphical example of quick sort

![](https://www.tutorialspoint.com/data_structures_algorithms/images/quick_sort_partition_animation.gif)
