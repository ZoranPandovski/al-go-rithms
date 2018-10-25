import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Random;
/*
 * The program draws a number from 1 to 10. Guess the number.
 */
public class Quiz 
{

	public static void main(String[] args) 
	{
		try 
		{
			double lottery_number, choose_number;
			BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
			
			printText("The program draws a number from 0 to 9. Guess the number.");
			Random number = new Random();
			lottery_number = Math.round(10*(number.nextDouble()));
			choose_number = Double.parseDouble(scan.readLine());
			
			if(lottery_number==choose_number)
			{
				printText("Congratulations!");
			}
			else
			{
				printText("Unfortunately, try again!");
				main(args);
			}
			
		} 
		catch (Exception e) 
		{
			
		}
	}
	
	public static void printText(String s)
	{
		System.out.println(s);
	}

}