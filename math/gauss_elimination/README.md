### Gaussian Elimination

Gaussian Elimination is a method used in linear algebra and analysis to find
solution(s) to a set of linear equations. The method is based on the fact that
elementary transformations change the system of equations but preserve the
solution.

For example, consider the following system of linear equations:

	 x + y -  z =  0
	2x - y -  z = -3
	4x + y - 2z = -2

The system can be equivalently written in matrix form as

	1  1 -1 |  0
	2 -1 -1 | -3
	4  1 -2 | -2 .

By subtracting the first row twice from the second row and the second row two
times from the third row, one obtains

	1  1 -1 |  0
	0 -3  1 | -3
	0  3  0 |  2 .
	
Adding the second row of the new matrix to the third row yields

	1  1 -1 |  0
	0 -3  1 | -3
	0  0  1 |  0 .
	
By subtracting the third row from the second row, multiplying the second row by
`-1/3` and adding the sum of the third row and new second row multiplied by
`-1`, the system's is given by the new matrix:

    1 0 0 | -1/3
    0 1 0 |    1
    0 0 1 |    0
    
Thus, the solution of the system of linear equations is given by `x=-1/3`,
`y=1` and `z=0`.
