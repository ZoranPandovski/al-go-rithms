
public class SumOfDigits {
	public static void main(String [] args) {
		int sum = sumOfDigits(25114);
		System.out.println(sum);
	}

	private static int sumOfDigits(int i) {
		int res = 0 ;
		while(i != 0) {
			res += i%10 ;
			i /= 10 ;
		}
		return res;
	}
}
