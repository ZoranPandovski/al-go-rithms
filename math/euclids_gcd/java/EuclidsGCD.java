import java.util.Scanner;

public class EuclidsGCD {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(sc.hasNextInt()){
            int a=sc.nextInt();
            int b=sc.nextInt();
            int gcd=gcd(a,b);
            System.out.println("GCD of "+a+" and "+b+" = "+gcd);
        }
    }

    private static int gcd(int a, int b) {
        if(a==0)return b;
        return gcd(b%a,a);
    }
}
