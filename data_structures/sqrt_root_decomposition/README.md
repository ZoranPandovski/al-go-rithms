## Sqrt (or Square Root) Decomposition Technique

Sqrt (or Square Root) Decomposition Technique is one of the most common query optimization technique used by competitive programmers. This technique helps us to reduce Time Complexity by a factor of sqrt(n).

The key concept of this technique is to decompose given array into small chunks specifically of size sqrt(n).

Let’s say we have an array of n elements and we decompose this array into small chunks of size sqrt(n). We will be having exactly sqrt(n) such chunks provided that n is a perfect square. Therefore, now our array on n elements is decomposed into sqrt(n) blocks, where each block contains sqrt(n) elements (assuming size of array is perfect square).

Let’s consider these chunks or blocks as an individual array each of which contains sqrt(n) elements and you have computed your desired answer(according to your problem) individually for all the chunks. Now, you need to answer certain queries asking you the answer for the elements in range l to r(l and r are starting and ending indices of the array) in the original n sized array.

The naive approach is simply to iterate over each element in range l to r and calculate its corresponding answer. Therefore, the Time Complexity per query will be O(n).

Sqrt Decomposition Trick : As we have already precomputed the answer for all individual chunks and now we need to answer the queries in range l to r. Now we can simply combine the answers of the chunks that lie in between the range l to r in the original array. So, if we see carefully here we are jumping sqrt(n) steps at a time instead of jumping 1 step at a time as done in naive approach.

### Range query of type 1(Given Range in Block Boundaries):
![](http://contribute.geeksforgeeks.org/wp-content/uploads/sqrt2.jpg)

In this type the query, the range may totally cover the continuous sqrt blocks. So we can easily answer the sum of values in this range as the sum of completely overlapped blocks.

Time Complexity: In the worst case our range can be 0 to n-1(where n is the size of array and assuming n to be a perfect square). In this case all the blocks are completely overlapped by our query range. Therefore,to answer this query we need to iterate over all the decomposed blocks for the array and we know that the number of blocks = sqrt(n). Hence, the complexity for this type of query will be O(sqrt(n)) in worst case.

### Range Query of type 2 (Given Range is NOT on boundaries):
![](http://contribute.geeksforgeeks.org/wp-content/uploads/sqrt31.jpg)

We can deal these type of queries by summing the data from the completely overlapped decomposed blocks lying in the query range and then summing elements one by one from the original array whose corresponding block is not completely overlapped by the query range.

Time Complexity: Let’s consider a query [l = 1 and r = n-2] (n is the size of the array and has a 0 based indexing). Therefore, for this query exactly ( sqrt(n) – 2 ) blocks will be completely overlapped where as the first and last block will be partially overlapped with just one element left outside the overlapping range. So, the completely overlapped blocks can be summed up in ( sqrt(n) – 2 ) ~ sqrt(n) iterations, whereas first and last block are needed to be traversed one by one separately. But as we know that the number of elements in each block is at max sqrt(n), to sum up last block individually we need to make,
(sqrt(n)-1) ~ sqrt(n) iterations and same for the last block.
So, the overall Complexity = O(sqrt(n)) + O(sqrt(n)) + O(sqrt(n)) = O(3*sqrt(N)) = O(sqrt(n))

### Update Queries(Point update):

In this query we simply find the block in which the given index lies, then subtract its previous value and add the new updated value as per the point update query.

Time Complexity : O(1)
