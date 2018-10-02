/**
 * Imagine a machine that gives you a quarter once you put in 25 cents. I suppose if you really like
 * gumballs that is in someway useful. The machine will wait until it has reached a state of 25 cents, 
 * then it will spit out a quarter. The machine is totally oblivious to what coins were added to reach
 * its current state, all it knows is the state it is in, which is how it achieves the "no memory" standard.
 * (at least conceptually)
 */
import java.util.Scanner;

public class coin_state_machine {
	
	public static Scanner sc = new Scanner(System.in);
	public static int state = 0;

	public static void main(String args[]){
		
		while(state != 25){
			
			System.out.println("Balance: " + state);

			System.out.println("Please insert a coin (penny, nickel, dime, quarter)");
			String coin = sc.nextLine();

			if(coin == "penny"){
				state += 1;
			} else if(coin == "nickel") {
				state += 5;
			} else if(coin == "dime") {
				state += 10;
			} else if(coin == "quarter") {
				state += 25;
			} else {
				System.out.println("Sorry, that's not a coin.");
			}

		}
		
		System.out.println("Thanks, here's your quarter.");
		return;
	
	}

}
