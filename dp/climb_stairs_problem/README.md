Problem Statement:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example:
	Input : 3
	Return : 3

	Steps : [1 1 1], [1 2], [2 1]


More info: https://www.interviewbit.com/problems/stairs/

Solution Approach:
The solution approach here is DP. We calculate the ways to reach a stair based on it's subproblems.
One can reach nth stair from n-1th stair and n-2th stair.
Hence the subproblem gives a generic equation:
	num_of_ways[n] = num_of_ways[n-1] + num_of_ways[n-2]

And the base statement becomes number_of_ways[1] = 1 and number_of_ways[2] = 2


