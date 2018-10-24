import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class SumOfDigitsTest {

	@Test
	void negativeNumbersForSumOfDigits() {
		assertEquals(8,SumOfDigits.sumOfDigits(-1234));
		assertEquals(16,SumOfDigits.sumOfDigits(-5678));
		assertEquals(-7,SumOfDigits.sumOfDigits(-9101));
		assertEquals(5,SumOfDigits.sumOfDigits(-1213));
		assertEquals(0,SumOfDigits.sumOfDigits(-9009));
	}
	@Test
	void negativeNumbersForSumOfDigitsForNegativeNumbers() {
		assertEquals(8,SumOfDigits.sumOfDigitsForNegativeNumbers(-1234));
		assertEquals(16,SumOfDigits.sumOfDigitsForNegativeNumbers(-5678));
		assertEquals(-7,SumOfDigits.sumOfDigitsForNegativeNumbers(-9101));
		assertEquals(5,SumOfDigits.sumOfDigitsForNegativeNumbers(-1213));
		assertEquals(0,SumOfDigits.sumOfDigitsForNegativeNumbers(-9009));
	}
	
	@Test
	void happyPathForSumOfDigits() {
		assertEquals(10,SumOfDigits.sumOfDigits(1234));
		assertEquals(26,SumOfDigits.sumOfDigits(5678));
		assertEquals(11,SumOfDigits.sumOfDigits(9101));
		assertEquals(7,SumOfDigits.sumOfDigits(1213));
		assertEquals(18,SumOfDigits.sumOfDigits(9009));
	}
	@Test
	void happyPathForSumOfDigitsForNegativeNumbers() {
		assertEquals(10,SumOfDigits.sumOfDigitsForNegativeNumbers(1234));
		assertEquals(26,SumOfDigits.sumOfDigitsForNegativeNumbers(5678));
		assertEquals(11,SumOfDigits.sumOfDigitsForNegativeNumbers(9101));
		assertEquals(7,SumOfDigits.sumOfDigitsForNegativeNumbers(1213));
		assertEquals(18,SumOfDigits.sumOfDigitsForNegativeNumbers(9009));
	}

}
