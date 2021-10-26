import java.util.Scanner;  
public class SumOfAllDigits {  
    public static void main(String args[]) {  
        int number, digit, s = 0;  

        System.out.print("Enter a number: ");  
        Scanner sc = new Scanner(System.in);  
        number = sc.nextInt();

        while(number > 0) {  
            digit = number % 10;  
            s = s + digit;  
            number = number / 10;  
        }  
        System.out.println("Sum of all digits: " +s);  
    }  
}  