import java.io.*;
import java.util.*;

public class harshitmalik03_Word_Break {
        public static void main(String[] args)throws Exception{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Enter the number of words in the dictionary");
            int n = Integer.parseInt(br.readLine());
//            ArrayList<String> arr = new ArrayList<>();
            String[] words ;
            System.out.println("Enter the words seperated by a space");
            words = br.readLine().split(" ");
            List B = Arrays.asList(words);
            System.out.println("Enter the sentence");
            String A = br.readLine();
            int val = wordBreak(A, B);
            System.out.print(val);
        }

        public static int wordBreak(String A, List B){
            int[] dp = new int[A.length()];

            for(int i = 0 ; i < dp.length ; i++){
                for(int j = 0 ; j <= i ; j++){
                    String toCheck = A.substring(j,i+1);
                    if(B.contains(toCheck)){
                        if(j > 0){
                            dp[i] += dp[j-1];
                        }else{
                            dp[i] += 1;
                        }
                    }
                }
            }
            if(dp[A.length()-1] > 0){
                return 1;
            }else{
                return 0;
            }

        }

}
