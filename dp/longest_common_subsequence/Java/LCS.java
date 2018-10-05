
public class LCS {
    public static void main(String args[]){
        String w1="adfgdh";
        String w2="dfdgfdd";
        int [][]array=new int[w1.length()+1][w2.length()+1];
        int i=0;
        for (i=1;i<array.length;i++){
            for (int j=1;j<array[0].length;j++){
                if (w1.charAt(i-1)==w2.charAt(j-1)){
                    array[i][j]=1+array[i-1][j-1];
                }
                else {
                    array[i][j]=Math.max(array[i-1][j],array[i][j-1]);
                }
            }
        }
        System.out.println(array[array.length-1][array[0].length-1]);
    }
}
