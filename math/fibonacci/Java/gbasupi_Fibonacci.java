import java.util.*;
/**
 * Write a description of class Fibonacci here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class gbasupi_Fibonacci
{
    static int fib(int n) 
    { 
        if (n <= 1) 
            return n; 
        return fib(n-1) + fib(n-2); 
    } 

    public static void main (String args[]) 
    { 
        Scanner myObj = new Scanner(System.in);  // Create a Scanner object
        System.out.println("Enter number to get Fibonacci");
        int number = myObj.nextInt();   
        System.out.println(fib(number)); 
    } 
}
