import java.util.Scanner

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double num = sc.nextInt();
		if(Math.sqrt(num) % 1 == 0){
			System.out.println("This is a perfect square");
		} else {
			System.out.println("This is not a perfect square");
		}
	}
}