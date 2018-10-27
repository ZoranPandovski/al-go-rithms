import java.io.*;
import java.util.*;


public class Nqueens
{
    static HashSet<Integer> ldia  = new HashSet<Integer>();
    static HashSet<Integer> rdia = new HashSet<Integer>();
    public static void find(int count,int ro,HashSet<Integer> row,HashSet<Integer> col,int A,ArrayList<String> temp,StringBuilder build,StringBuilder dummy,ArrayList<ArrayList<String>> ans)
    {
        if(count == A)
        {
            ans.add(new ArrayList<String>(temp));
            return;
        }
        for(int i=0;i<A;i++)
        {
            if(!row.contains(ro) && !col.contains(i) && !ldia.contains(ro + i) && !rdia.contains(A - i - 1 + ro))
            {
                build = new StringBuilder(dummy);
                build.setCharAt(i,'Q');
                temp.add(new String(build.toString()));
                row.add(ro);col.add(i);ldia.add(ro + i);rdia.add(A - i - 1 + ro);
                find(count+1,ro+1,row,col,A,temp,build,dummy,ans);
                row.remove(ro);col.remove(i);ldia.remove(ro+i);rdia.remove(A - i - 1 + ro);
                build = new StringBuilder(dummy);
                temp.remove(temp.size() - 1);
            }
        }
    }
    public static ArrayList<ArrayList<String>> solveNQueens(int A) 
    {
        StringBuilder build = new StringBuilder();
        StringBuilder dummy = new StringBuilder();
        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        for(int i=0;i<A;i++)
        {
            build.append(".");
            dummy.append(".");
        }
        HashSet<Integer> row = new HashSet<>();
        HashSet<Integer> col = new HashSet<>();
        ArrayList<String> temp = new ArrayList<>();
        find(0,0,row,col,A,temp,build,dummy,ans);
        return ans;
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the size of chessboard : ");
        int n = in.nextInt();
        ArrayList<ArrayList<String>> ans = solveNQueens(n);
        int size = ans.size();
        for(int i=0;i<size;i++)
        {
            ArrayList<String> temp = ans.get(i);
            System.out.println("Solution : " + (i+1));
            for(int j=0;j<temp.size();j++)
            {
                System.out.println(temp.get(j));
            }
        }
    }
}
