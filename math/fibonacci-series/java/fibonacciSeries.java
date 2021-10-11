import java.util.InputMismatchException;
import java.util.Scanner;

public class Fibonacci {
	
	static long memoization[] = new long [2048];
	
	static long fibonacci(int n) {
		if (n == 0 || n == 1 || memoization[n] != 0) {
			return memoization[n];
		} else {
			memoization[n] = fibonacci(n - 1) + fibonacci(n - 2);
		}
		return memoization[n];
	}
	
	public static void main(String args[]) {
		int upTo, ctr = 0;
		memoization[1] = 1;
		
		Scanner sc = new Scanner(System.in);
		System.out.print("How many Fibonacci numbers to display: ");
		try {
			upTo = sc.nextInt();
		} catch (InputMismatchException ex) {
			upTo = 10;
		}
		
		while (ctr < upTo) {
			System.out.print(fibonacci(ctr) + " ");
			++ctr;
		}
		
		sc.close();
	}
}
