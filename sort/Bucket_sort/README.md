## Bucketsort ##

Bucketsort is a good sort when your input is unifomily distributed across the range.
All of the elements have to be in range from 0.0 to 1.0.

The main idea of the algorithm is :

1) Create n empty buckets
2) Set all buckets to NULL.
3) Insert the element into bucket array at the position n * array[idx].
4) Sort individual buckets.
5) Concatenate the sorted buckets.

## An example of operation ##

![Bucketsort example](BucketSort.png)