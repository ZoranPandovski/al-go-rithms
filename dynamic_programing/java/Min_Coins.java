public class CoinChangeDyn {
	
	public static void main(String args[]) {
		int d[] = { 1, 5, 8, 10, 25 }; // Coins
		int n = d.length;
		int c = 33; // Change wanted
		int t[] = new int[c + 1];
		for (int i = 1; i <= c; i++) {
			t[i] = i;
			for (int j = 1; j < n; j++) {
				if (i >= d[j]) {
					t[i] = Math.min(t[i],  1 + t[i - d[j]]);
				}
			}
		}
		
		// Outputs the number of coins needed
		System.out.println(t[c]);
	}
}
