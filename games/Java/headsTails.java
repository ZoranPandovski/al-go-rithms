import java.util.Random; 
import java.util.Scanner; 
public class CoinToss {
    public static void main(String args[]) {
        Random rand = new Random();
        int num = rand.nextInt(2);
        Scanner sc = new Scanner(System.in);
        System.out.println("Heads or tails? (enter 0 for heads, 1 for tails): ");
        int answer = sc.nextInt();
        if (answer == num) {
            System.out.println("Correct!");
        } else {
            System.out.println("Try Again!");
        }
    }
}
