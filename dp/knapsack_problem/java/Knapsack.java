public class Knapsack {

	public static void main(String[] args) {
		// Initialize the algorithm
		new Knapsack().begin();
	}

	void begin() {
		int values[] = { 20, 5, 10, 40, 15, 25 };
		int weights[] = { 1, 2, 3, 8, 7, 4 };

		int capacity = 10;
		int n = values.length;

		System.out.println(knapSack(values, weights, n, capacity));
	}

	/** 0/1 Knapsack method
	*@param values - Values stored in array
	*@param weights - Weights stored in array
	*@param n - number of distinct items
	*@param capacity - Knapsack capacity
	*@return max value
	*/

	int knapSack(int values[], int weights[], int n, int capacity) {

		// create a new matrix Items are row and weight are column
		int K[][] = new int[n + 1][capacity + 1];

		//initialize tha values of bag items and capacity
		for (int i = 0; i < n; i++) {
			K[i][0] = 0;
    }

    for (int w = 0; w < capacity; w++) {
			K[0][w] = 0;
    }

		for (int i = 1; i <= n; i++) {
			for (int w = 1; w <= capacity; w++) {
				if (weights[i - 1] <= w) {
					//Find maximum value get by excluding or including the item
					K[i][w] = Math.max(
							values[i - 1] + K[i - 1][w - weights[i - 1]],  //including the item
							K[i - 1][w] // excluding the item
			                             ); 
				} else {
					//If current item weight is more than the running weight, just keep going without the current item
					K[i][w] = K[i - 1][w];
				}
			}
		}
		//return the maximum value
		return K[n][capacity];
	}
}
