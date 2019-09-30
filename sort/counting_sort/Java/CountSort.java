
public class CountSort {
	
	private int getMax(int [] A) {
		int max = A[0];
		for(int i = 0 ; i < A.length ; i ++)
			if(max< A[i])
				max = A[i];
		return max;
	}
	
	private void getFreq(int [] A , int [] freq) {
		for(int i = 0 ; i < A.length ; i ++)
			freq[A[i]] += 1 ;
	}
	
	public void sort(int [] A) {
		int [] freq = new int [getMax(A)+1];
		getFreq(A, freq);
		for(int i = 0 , j = 0 ; i < A.length ; i ++) {
			while(freq[j] == 0)
				j++;
			A[i] = j ;
			freq[j] -= 1;
		}
	}
	
	public static void main (String [] args) {
		int nosrt[] = {4,3,10,8,1,16,17,1,12,11,20};
		new CountSort().sort(nosrt);
		for(int i = 0 ; i < nosrt.length ; i ++)
			System.out.println(nosrt[i]);
	}
}
