import java.util.*;
public class is_prime {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int n;

		do
		{
			System.out.print("Input number to check if it is prime: ");
			n = kb.nextInt();
			System.out.print("\n");
			if(n<1)
				System.out.println("Please Input a positive number\n");
		}while(n<1);

		kb.close(); //Scanner is no longer needed		
		
		if(n==1){
			System.out.println("1 is not prime");
		}

		for(int i = 2; i<n/2; i++){
			if(n%i==0){
				System.out.println(n + " is not prime");
				return;
			}
		}

		System.out.println(n + " is prime");
	}

}
