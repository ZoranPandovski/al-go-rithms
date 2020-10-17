import java.util.Scanner;

public class fibonacci {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter a value: ");
        int value = scan.nextInt();
        System.out.println("The result is " + recurseFib(value));
        scan.close();
    }

    static int recurseFib(int num) {
        if (num <= 1) {
            return num;
        } else {
            return recurseFib(num - 1) + recurseFib(num - 2);
        }
    }
}