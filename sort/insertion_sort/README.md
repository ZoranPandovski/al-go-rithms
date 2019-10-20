### Insertion Sort
The insertion sort is a simple sorting algorithm. It iteratively builds the sorted output one element at a time.

While insertion sort's worst-case and average complexities are both O(_n_<sup>2</sup>), it is one of the fastest algorithms for sorting very small arrays, and as such is often used to complement other algorithms such as [quicksort](https://github.com/ZoranPandovski/al-go-rithms/tree/master/sort/quick_sort/) below a certain number of elements.

Insertion sort is useful for nearly-sorted arrays, as complexity is O(_nk_) when each element is no more than _k_ places away from its sorted position.

It is a stable in-place sort, requiring a constant amount of memory. Any items with identical keys in the input will remain in the same order when output. 

#### Visualization
![](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)
