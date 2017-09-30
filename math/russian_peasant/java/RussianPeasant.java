
public class RussianPeasant {
	
	public static int calculate(int a, int b) {
		int x = a;
	    int y = b;
	    int results = 0;
	    
	    while (x > 0) {
	    	if (x % 2 == 1) results = results + y;
	    	y = y << 1;
	    	x = x >> 1;
	    }

		return results;
	}
	
	public static void main(String[] args) {
		int x = RussianPeasant.calculate(3, 4);
		System.out.println(x);
	}
}
