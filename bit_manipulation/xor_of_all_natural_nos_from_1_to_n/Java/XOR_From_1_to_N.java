import java.util.Scanner;
 
class algo{
	public static int XOR_From_1_to_N(int n){
		if(n%4==0)
			return n;
		if(n%4==1)
			return 1;
		if(n%4==2)
			return n+1;
		return 0;
	}
 
	public static void main (String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ans=XOR_From_1_to_N(n);
		System.out.println(ans);
	}
}