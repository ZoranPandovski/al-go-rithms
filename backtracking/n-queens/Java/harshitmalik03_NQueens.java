import java.util.*;

public class harshitmalik03_NQueens{

    public static void main(String[] args) throws Exception{
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
//        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        boolean vis[][] = new boolean[n][n];
        ans.clear();
        backtracking(0,n,vis);
    }
    static ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        static void backtracking(int i, int n, boolean vis[][]){
            if(i == n){
                ArrayList<Integer> temp = new ArrayList<>();
                for(int j=0;j<n;j++)
                    for(int k=0;k<n;k++)
                        if(vis[j][k]) temp.add(k+1);
                ans.add(temp);
                System.out.print(temp);
                return;
            }
            for(int j=0;j<n;j++)
                if(isSafe(i,j,vis)){
                    vis[i][j] = true;
                    backtracking(i+1,n,vis);
                    vis[i][j] = false;
                }
        }
        static boolean isSafe(int row, int col, boolean vis[][]){
            for(int i=row-1,j=col;i>=0;i--)
                if(vis[i][j]) return false;
            for(int i=row-1,j=col-1;i>=0 && j >=0;i--,j--)
                if(vis[i][j]) return false;
            for(int i=row-1,j=col+1;i>=0 && j<vis[0].length;i--,j++)
                if(vis[i][j]) return false;
            return true;
        }





}