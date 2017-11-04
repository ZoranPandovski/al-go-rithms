
public class Catalan {
	public static void main(String [] args) {
		System.out.println(cat(3));
	}

	private static double cat(double m) {
		if(m == 0) return 1 ;
		return (2*m*(2*m-1)/((m+1)*m)) * cat(m-1);
	}
}
