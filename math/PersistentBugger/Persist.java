import java.util.*;
class Persist {
    public static long prod(long n){
        long rem=1;
        while(n>0)
        {
            rem*=n%10;
            n=n/10;
        }
        return rem;
    }
    public static int persistence(long n) {
        int count=1;
        long x=prod(n);
        if(x>0&&x<9)
        return count=0;
        else{
        while(x>9)
        {
            x=prod(x);
            count++;
        }
        return count;
        } 
	}
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        System.out.println(persistence(x));
    }
}