import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
/*
 * The program calculates the volume of the ball.
 */
public class BulletVolume 
{
	
	private static double r, v;
	public static void main(String[] args) 
	{
		
		
		System.out.println("the program calculates the volume of the ball.." + "\n" + "Displays the result with two decimal places." +
		"\n" + "Enter the length of the radius r.");
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		
		try 
		{
			r = Double.parseDouble(scan.readLine());
			
			//Calculation of the volume of the sphere.
			v = 4*Math.PI*r*r*r/3;
		} 
		catch (NumberFormatException e) 
		{
			System.out.println("It's not a number. Give me a number.");
			main(args);
		} 
		catch (IOException e) 
		{
			System.out.println("Give me a number.");
			main(args);
		}
		System.out.print("Radius length: " + r + "\n" + "The volume of the ball is: ");
		System.out.printf("%3.2f\n", v);
		
	}

}
