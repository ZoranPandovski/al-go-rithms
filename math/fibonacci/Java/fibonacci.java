import java.util.Scanner;
public class fibonacci {

	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		int n;
		do
		{
			System.out.print("Input the nth fibonacci number you'd like to compute: ");
			n = kb.nextInt();
			System.out.print("\n");
			if(n<1)
				System.out.println("Please Input a positive number\n");
		}while(n<1);
		kb.close(); //Scanner is no longer needed		
		if(n>2)
		{
			int[] valueStore = new int[n];
			//Base Cases
			valueStore[0] = 0;
			valueStore[1] = 1;
			//Calculating Numbers 2 to n
			for(int i = 2;i<n;i++)
				valueStore[i] = valueStore[i-1] + valueStore[i-2];
				
			System.out.println("Fibonacci number "+n+" is: "+valueStore[n-1]);//Subtract 1 from n to get the last value in the array (the nth number)
		}
		else
			System.out.println("Fibonacci number "+n+" is: "+(n-1));//In this n will be either a 1 or 2 which will result in a 0 or 1
	}

}
