import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;
/*
 * Performs 10 times multiplication of the number entered by a random number of no more than 100.
 */

public class TenTimesRandomMultiplication
{
	public static void main(String[] args) 
	{
		try 
		{
			BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Enter the number: ");
			double a = Double.parseDouble(scan.readLine());
			Random number = new Random();
			
			for(int i = 0; i<=10; i++)
			{
				
				double b = Math.round(100*(number.nextDouble()));
				double multi = a*b;
				System.out.println(multi + " Randonm number is: " + b);
			}

		} 
		catch (Exception e) 
		{
			System.out.println("Enter the number!");
			main(args);
		}
	}
	

}


