
public class SumOfDigits {
	public static void main(String [] args) {
		if (happyPathForSumOfDigitsForNegativeNumbers()) {
			System.out.println("happyPathForSumOfDigitsForNegativeNumbers are OK");
		} else {
			System.out.println("happyPathForSumOfDigitsForNegativeNumbers are NOT OK");
		}
		
		if (negativeNumbersForSumOfDigitsForNegativeNumbersTest()) {
			System.out.println("negativeNumbersForSumOfDigitsForNegativeNumbersTest are OK");
		} else {
			System.out.println("negativeNumbersForSumOfDigitsForNegativeNumbersTest are NOT OK");
		}
		
		if (happyPathForSumOfDigitsTest()) {
			System.out.println("happyPathForSumOfDigitsTest are OK");
		} else {
			System.out.println("happyPathForSumOfDigitsTest are not OK");
		}
		
		if (negativeNumbersForSumOfDigitsTest()) {
			System.out.println("negativeNumbersForSumOfDigitsTest are OK");
		} else {
			System.out.println("negativeNumbersForSumOfDigitsTest are not OK");
		}
	}

	public static int sumOfDigits(int i) {
		if (i >= 0) {
			int res = 0 ;
			while(i != 0) {
				res += i%10 ;
				i /= 10 ;
			}
			return res;
		} else {
			throw new IllegalArgumentException("This method does not return the right result with negative inputs");
		}
	}
	
	public static int sumOfDigitsForNegativeNumbers(int number) {
		int res = 0 ;
		while(number != 0) {
			if (number < 0 && number > -10) { // Means that the input was a negative number
				res *= -1;	
			}
			res += number%10 ;
			number /= 10 ;
		}
		return res;
	}
	
	public static boolean happyPathForSumOfDigitsForNegativeNumbers() {
		return (10 == SumOfDigits.sumOfDigitsForNegativeNumbers(1234)
				&& 26 == SumOfDigits.sumOfDigitsForNegativeNumbers(5678)
				&& 11 == SumOfDigits.sumOfDigitsForNegativeNumbers(9101)
				&& 7 == SumOfDigits.sumOfDigitsForNegativeNumbers(1213)
				&& 18 == SumOfDigits.sumOfDigitsForNegativeNumbers(9009));
	}
	
	public static boolean negativeNumbersForSumOfDigitsForNegativeNumbersTest() {
		return (8 == SumOfDigits.sumOfDigitsForNegativeNumbers(-1234)
				&& 16 == SumOfDigits.sumOfDigitsForNegativeNumbers(-5678)
				&& -7 == SumOfDigits.sumOfDigitsForNegativeNumbers(-9101)
				&& 5 == SumOfDigits.sumOfDigitsForNegativeNumbers(-1213)
				&& 0 == SumOfDigits.sumOfDigitsForNegativeNumbers(-9009));
	}
	
	public static boolean happyPathForSumOfDigitsTest() {
		try {
			return (10 == SumOfDigits.sumOfDigits(1234)
					&& 26 == SumOfDigits.sumOfDigits(5678)
					&& 11 == SumOfDigits.sumOfDigits(9101)
					&& 7 == SumOfDigits.sumOfDigits(1213)
					&& 18 == SumOfDigits.sumOfDigits(9009));			
		} catch(Exception e) {
			return false;
		}
	}
	
	public static boolean negativeNumbersForSumOfDigitsTest() {
		try {
			return (8 == SumOfDigits.sumOfDigits(-1234)
					&& 16 == SumOfDigits.sumOfDigits(-5678)
					&& -7 == SumOfDigits.sumOfDigits(-9101)
					&& 5 == SumOfDigits.sumOfDigits(-1213)
					&& 0 == SumOfDigits.sumOfDigits(-9009));
		} catch(Exception e) {
			return false;
		}
	}	
}