import java.util.*;
public class isogram {
    public static boolean  isIsogram(String str) {
        str=str.toLowerCase();
        char[] arr=str.toCharArray();
        Arrays.sort(arr);
        for(int i=0;i<arr.length-1;i++)
        {
            if(arr[i]==arr[i+1])
            return false; 
        }
        return true;
    }
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        System.out.println(isIsogram(str));
    }
}