import java.util.Scanner;

public class ArmstrongNumber {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int num = s.nextInt();
		int toCheck = num;
		int toCountDigits = num;
		int n = 0;
		while (toCountDigits > 0) {
			toCountDigits /= 10;
			n++;
		}
		int sum = 0;
		while (num > 0) {
			int r = num % 10;
			sum += Math.pow(r, n);
			num /= 10;
		}
		if (sum == toCheck) {
			System.out.println("It is an armstrong number");
		} else {
			System.out.println("It is an not armstrong number");
		}
		s.close();

	}
}
