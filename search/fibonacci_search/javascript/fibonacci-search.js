
function fibonacciSearch(arr, x, n)
{
	/* Initialize fibonacci numbers */
	let fibMMm2 = 0; // (m-2)'th Fibonacci No.
	let fibMMm1 = 1; // (m-1)'th Fibonacci No.
	let fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

	/* fibM is going to store the smallest Fibonacci
	Number greater than or equal to n */
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// Marks the eliminated range from front
	let offset = -1;

	/* while there are elements to be inspected. Note that
	we compare arr[fibMm2] with x. When fibM becomes 1,
	fibMm2 becomes 0 */

	while (fibM > 1)
	{
		// Check if fibMm2 is a valid location
		let i = Math.min(offset + fibMMm2, n-1);

		/* If x is greater than the value at index fibMm2,
		cut the subarray array from offset to i */
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		/* If x is less than the value at index fibMm2,
		cut the subarray after i+1 */
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		/* element found. return index */
		else return i;
	}

	/* comparing the last element with x */
	if(fibMMm1 && arr[n-1] == x){
	return n-1
	}

	/*element not found. return -1 */
	return -1;
}

module.exports = fibonacciSearch;
