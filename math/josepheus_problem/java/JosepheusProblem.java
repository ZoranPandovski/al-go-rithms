
package josephiusproblem;
    import java.util.Scanner;

public class JosepheusProblem {
    
    public static int problem(int n, int k){
        if(n==1) return 1;

	return (((problem(n-1, k) + k - 1) % n) + 1);
    }
    
    public static void main(String[] args) {
        Scanner l = new Scanner(System.in);
        int n, k;
        
        System.out.println("Enter the number of people:");
        n = l.nextInt();
        System.out.println("Enter the step:");
        k = l.nextInt();
        
        System.out.println("Survivor: "+problem(n,k));

    }
    
}
