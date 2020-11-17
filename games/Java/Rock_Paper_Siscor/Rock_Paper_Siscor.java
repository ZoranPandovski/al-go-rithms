import java.util.Random;
import java.util.Scanner;

public class Rock_Paper_Siscor {

	public static void main(String[] args) {
               
                String playerWhichMoves = "";
                String computerWhichMoves = "";
                
                // Storing scores
                int playerScore = 0;
                int computerScore = 0;

                //Storing winner
                String winner = "";
		
		// Generating Random number for computer moves
		Random randomNumber = new Random();
		
		// Making scanner number for user input
      Scanner sc = new Scanner(System.in);

      // Some Line To Display First
      System.out.println("Welcome to Rock-Paper-Siscor");
      System.out.println("This game is repeat for five time");
      System.out.println("Select your moves as per option");
      System.out.println("0: Rock");
      System.out.println("1: Paper");
      System.out.println("2: Siscor");
      System.out.println("Enter Your Move");
      
      //Repeating Game For Five Time So Winner Is Clear
		for(int i = 0; i <= 5; i++) {
			
			// Taking user input in playerMoves
			int playerMoves = sc.nextInt();
                        
                        // Checking input is valid or not
                        if(playerMoves > 2 || playerMoves < 0){
                         System.out.println("invalid move");
                           return;
                        }          

                        // Taking random number in computerMoves
                        int computerMoves = randomNumber.nextInt(2);

                        // Showing which moves taken by Player and Computer

                        if(playerMoves == 0){
                          playerWhichMoves = "Your move is Rock";      
                        }
                        else if(playerMoves == 1){
                          playerWhichMoves = "Your move is Paper";                       
                          }
                        else if(playerMoves == 2){
                          playerWhichMoves = "Your move is Siscor";                           
                          }
                          
			
                          if(computerMoves == 0){
                          computerWhichMoves = "Computer move is Rock"; 
                          }
                        else if(computerMoves == 1){
                          computerWhichMoves = "Computer move is Paper";                           
                          }
                        else if(computerMoves == 2){
                          computerWhichMoves = "Computer move is Siscor";
                          }
                          

                       
                       // Checking Winner
                      
                     if(playerMoves == computerMoves){
                      winner = "Tie";
                      }
                     else  if(playerMoves == 0 && computerMoves == 2 || playerMoves == 2 && computerMoves == 1 || playerMoves == 1 && computerMoves == 0){
                        winner = "You are winner";
                        playerScore += 1;
                       }else {
                        winner = "Computer is winner";
                        computerScore += 1;
                       }
                     
                      System.out.println(playerWhichMoves);
                      System.out.println(computerWhichMoves);
                      System.out.println(winner);
                      System.out.println(playerScore);
                      System.out.println(computerScore);
                     
                      
		}

              // checking final winner

             if(playerScore == computerScore){
               System.out.println("The game is tie between computer and you");
             }

             if(playerScore > computerScore){
             System.out.println("Final Winner is you");
             }else{
             System.out.println("Final Winner is you");
             }       

		
	}

}
