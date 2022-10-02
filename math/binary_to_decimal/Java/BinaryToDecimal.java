import java.util.Scanner;
public class BinaryToDecimal {
    public static void main(String[] args) 
    {
    long bn, dn = 0, j = 1, r;

    System.out.print("Enter a binary number: ");
    Scanner sc = new Scanner(System.in);
    bn = sc.nextLong();

    while (bn != 0) {
        r = bn % 10;
        dn = dn + r * j;
        j = j * 2;
        bn = bn / 10;
    }

    System.out.println("The decimal number is: " + dn);

    }
}