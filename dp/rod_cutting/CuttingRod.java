import java.util.Scanner;

public class CuttingRod {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int length=in.nextInt();
		int[] length_price=new int[length-1];
		int[][] matrix=new int[length-1][length+1];
		
	
			for(int i=0;i<length-1;i++){
				length_price[i]=in.nextInt();
			}
			int price_of_whole_rod=in.nextInt();
			int ans=Math.max(price_of_whole_rod,findMaxPrice(length, length_price, matrix));
			System.out.println("Maximum price:"+ans);
			System.out.println("Parts to be made to achieve the price: ");
			if(ans==price_of_whole_rod) System.out.println("No need to cut the rod");
			else PartLength(length,matrix);
		}
	
		public static int findMaxPrice(int length,int[] length_price,int[][] matrix){
			for(int j=0;j<=length;j++){
			matrix[0][j]=j*length_price[0];
			}
		
			for(int i=1;i<length-1;i++){
				for(int j=1;j<=length;j++){
					if((j-i-1)>=0) matrix[i][j]=Math.max(matrix[i-1][j], length_price[i]+matrix[i][j-i-1]);
					else{
						matrix[i][j]=matrix[i-1][j];
					}
				}
			}
			/*for (int i = 0; i < length-1; i++) {
	            for (int j = 0; j <= length; j++)
	                System.out.printf(matrix[i][j]+"\t");
	            System.out.println();
	        }*/
			return matrix[length-2][length];
		}
		public static void PartLength(int length,int[][] matrix){
			int i=length-2;
			int j=length;
			while(i>=0 && j>=0 && matrix[i][j]!=0){
					if(i>0 && matrix[i][j]==matrix[i-1][j]){
						i=i-1;
					}
					else{
						j=j-i-1;
						System.out.print(i+1+" ");
					}
			}
		}	
}
