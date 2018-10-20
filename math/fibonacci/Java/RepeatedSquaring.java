public class RepeatedSquaring {
	public static void main(String args[]) {
        long start = System.nanoTime();
        
		System.out.println(FibRepSq(2147483647));
        
        long time = System.nanoTime() - start;
        System.out.print("CPU time used (s): ");
		System.out.println((float) time / 1000000000);

	}

    public static int PRIME = 30011;
    static int f0 = 0, f1 = 1;

    public static int FibRepSq(int n) {
        if(n==0) return 0;
        int[][] magic_mat = {{1,1},{1,0}};
		int[][] power_mat = power(magic_mat,n-1);
        int[][] f1_f0 = {{f1},{f0}};
        return matmul(power_mat,f1_f0)[0][0];
	}
    
    public static int[][] power(int[][] X, int n){
        if(n<0) return X;
        if(n==0) return new int[][] {{1,0},{0,1}};
        if(n==1) return X;
        else if(n%2==0){
            return square(power(X,n/2));
        }
        else{
            return matmul(square(power(X,(n-1)/2)),X);
        }
    }
    
    public static int[][] square(int[][] A){
        return matmul(A,A);
    }
    
    public static int[][] matmul(int[][] A,int[][] B){
        int[][] result = new int[A.length][B[0].length];
        for(int i = 0; i < A.length; i++){
            for (int j = 0; j < B[0].length; j++){
                int[] B_column = get_col(B,j);
                result[i][j] = dot(A[i],B_column);
            }
        }
        return result;
    }
    
    public static int[] get_col(int[][] A,int j){
        int[] result = new int[A.length];
        for (int i = 0; i < A.length; i++){
            result[i] = A[i][j];
        }
        return result;
    }
    
    public static int dot(int[] x,int[] y){
        int result  = 0;
        for (int i = 0; i < x.length; i++){
            result += x[i]*y[i];
        }
        return result % PRIME;
    }
}
