public class IsSquare {

	public static void main(String[] args) {
		System.out.println("É " + isSquare(4));
	}

	public static boolean isSquare(int num) {
		if(num == 1 || num == 0)
			return true;
		double square = num / 2;
		double c = square;

		do {
			c = square;
			square = (c + (num / c)) / 2;
		} while ((c - square) != 0);

		if(square*square == num) 
			return true;
		return false;
	}
}
