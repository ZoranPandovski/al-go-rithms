# Bozo Sort

The idea is very simple: take the list, check if it's sorted, and of it's not, swap two random elements of the list. Proceed like that until the list becomes sorted.

> ## Pseudocode
PseudoCode to bozosort an array - 
    
    To bozo sort an array:
 
	    While the array is unsorted,
    
		    Swap two randomly selected entries.
       
	     end
    
    end
  
 > ## Complexity
 
 In the very worst case, Bozosort runs forever -- we could get really unlucky, and keep swapping elements 0 and 1 forever, for example.

We can talk instead about how long Bozosort will take on average. The analysis is not actually easy, but roughly speaking, we can hope that we'll go through every permutation of the list once, on average (we'll come back to some permutations many times, and we will sort the list before getting to some other permutations). There are n! permutations of a list of length n in total, so we can estimate that on average, Bozosort takes O(n!) time.

(Note that actually, is_sorted_nondecreasing() takes O(n) time every time, so saying the runtime is O(n×n!)≈O((n+1)!) is more correct, but it doesn't really make a difference since n! is so large.)
