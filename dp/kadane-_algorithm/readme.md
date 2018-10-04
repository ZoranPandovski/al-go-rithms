## Kadane 's Algorithm
This algorithm, an example of dynamic programming is used when given a sequence of n real numbers A(1) … A(n), we have to determine a
contiguous subsequence A(i) … A(j) for which the sum of elements in the subsequence is maximized.


Kadane's algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of
maximum sum contiguous segment among all positive segments (max_so_far is used for this). Each time we get a positive sum compare it 
with max_so_far and update max_so_far if it is greater than max_so_far.
