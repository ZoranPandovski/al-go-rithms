import java.util.*;

public class harshitmalik03_NQueens{                                                                                    

    public static void main(String[] args) throws Exception{
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();                                                                                          //Taking input n where n represents an n*n chessboard
        boolean vis[][] = new boolean[n][n];                                                                            //And n Queens needs to be placed in the given chess board so that no Queen can attack each other.
        ans.clear();
        backtracking(0,n,vis);
    }
    static ArrayList<ArrayList<Integer>> ans = new ArrayList<>();                                                       //Creating an arraylist of arraylist that stores all the arraylists of answers
        static void backtracking(int i, int n, boolean vis[][]){
            if(i == n){
                ArrayList<Integer> temp = new ArrayList<>();                                                            //temp is the list of answer
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        if(vis[j][k]) temp.add(k+1);
                ans.add(temp);
                System.out.print(temp);                                                                                 //Printing temp as each answer is generated. We can also add it in the given ans arraylist as done and then print the ans at the end.
                return;
            }
            for(int j=0;j<n;j++)                                                                                        //For each row we will traverse all the columns and see if we can place the queen there.
                if(isSafe(i,j,vis)){
                    vis[i][j] = true;                                                                                   //Marking the spot visited
                    backtracking(i+1,n,vis);
                    vis[i][j] = false;                                                                                  //Unvisiting the spot so we can find all the distinct solutions.
                }
        }
        static boolean isSafe(int row, int col, boolean vis[][]){                                                       //Checking if it is safe to place the queen at this given spot.
            for(int i=row-1,j=col;i>=0;i--)
                if(vis[i][j]) return false;
            for(int i=row-1,j=col-1;i>=0 && j >=0;i--,j--)
                if(vis[i][j]) return false;
            for(int i=row-1,j=col+1;i>=0 && j<vis[0].length;i--,j++)
                if(vis[i][j]) return false;
            return true;
        }





}
