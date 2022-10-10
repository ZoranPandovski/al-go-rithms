import java.util.Scanner;
public class Prime {
	public static void main(String[]args) {
		int num,flag=0;
		Scanner sc = new Scanner(System.in);
		num=sc.nextInt();
		for(int i=2;i<=(num-1)/2;i++){
			if(num%i==0) {
				flag=1;
			}
		}
		if(flag==0) {
			System.out.println("Number is prime");
		}
		else {
				System.out.println("Number is not prime");
			}
		sc.close();
	}

}
