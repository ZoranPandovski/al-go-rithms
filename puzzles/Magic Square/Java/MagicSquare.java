public class MagicSquare {

	/**
	 * Verifies if a 2d array is a magic square.
	 */
	public boolean verify(int[][] square) {
		int sum;
		// diagonal sum 
		for(int i = 0; i < square.length; i++) {
			sum += square[i][i];
		}
		
		int reverseSum;
		// reverse diagonal sum 
		for(int i = 0, j = square.length - 1; i < square.length || j >= 0; i++, j--) {
			reverseSum += square[i][j];
		}
		
		if(sum != reverseSum) {
			return false;
		}
		
		// row sums
		for(int i = 0; i <square.length; i++) {
			int sumRow;
			for(int j = 0; i < square.length; j++) {
				sumRow += square[i][j];
			}
			if(sum != sumRow) {
				return false;
			}
		}
		
		// col sums
		for(int i = 0; i <square.length; i++) {
			int sumCol;
			for(int j = 0; i < square.length; j++) {
				sumCol += square[j][i];
			}
			if(sum != sumCol) {
				return false;
			}
		}
		
		return true;
		
	}
}