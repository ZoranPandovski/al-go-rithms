import java.util.Scanner;

public class StrongNumber {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(sc.hasNextInt()){
            int a=sc.nextInt();
            System.out.println(strongNumber(a)?a+" is a strong number":a+" is NOT a strong number");

        }
    }

    private static boolean strongNumber(int number) {
        int sum=0,temp,num=number;
        while(num>0){
            temp=num%10;
            num/=10;
            sum+=factorial(temp);
        }
        return sum==number;
    }

    private static int factorial(int num) {
        for (int i = num-1; i >1; i--) {
            num*=i;
        }
        return num;
    }
}
