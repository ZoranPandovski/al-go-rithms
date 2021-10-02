import java.util.Random;
import java.util.Scanner;

/*
 * Guess the number game in Java
 */
public class GuessTheNumber {
	public static void main(String[] args) {
	    Scanner in = new Scanner(System.in); // Import scanner
	    // Generate a random answer
	    Random r = new Random(); 
	    int ans = r.nextInt(100) + 1;
	    // Initialize attempts and guess value
	    int attempts = 1; 
	    int guess = -1; 
	    System.out.println("I am thinking of a number between 0 and 100.");
	    // Keep looping until user has guessed the number
	    while (true) {
	    	System.out.println("Enter a guess: ");
	    	guess = in.nextInt(); // Get the user's guess 
	    	if (ans > guess) { // If the guess is too high
	            System.out.println("Your number is too low!");
	            attempts += 1; 
	        }
	        else if (ans < guess){ // If the guess is too low
	            System.out.println("Your number is too high!");
	            attempts += 1;
	        } 
	        else { // If the user has guessed the answer
	        	break;
	        }
	    }
	    // Return answer and number of attempts
	    System.out.println(ans + " is the correct answer! You took " + attempts + " tries to guess the number!"); 
	}
}
