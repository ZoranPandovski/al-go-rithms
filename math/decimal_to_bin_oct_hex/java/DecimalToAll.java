import java.util.Scanner;

public class DecimalToAll {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int number = in.nextInt(); // get number
    System.out.println("The decimal value of " + number + " is:");
    System.out.println(Integer.toBinaryString(number) + " in binary.");
    System.out.println(Integer.toOctalString(number) + " in octal.");
    System.out.println(Integer.toHexString(number) + " in hexadecimal.");
  }
}
