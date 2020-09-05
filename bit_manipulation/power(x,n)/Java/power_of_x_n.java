//Finding power of x to the n, where n can be a positive or negative integer.
//As we already we know that negative exponent is equal to 1 by power(x,n)
//And this is a iterative approach

//Problem link: https://leetcode.com/problems/powx-n/

/**********************************
 * Dry Run of Program:
 * power(2.0,10)=(2*2)^5 = 4^5 =1024
 * 4^5 = 4*4^4 = 1024
 * 4^4 = (4*4)^2 = 16^2 = 256
 * 16^2 = (16*16) = 256^1 =256
 * 256^1 = 256*256^0 = 256
***********************************/


import java.util.*;

public class power_of_x_n{
    public static double power(double x, int n) {
        double ans=1.0;
        int nn=n;
        if(nn<0){
            nn=-1*nn;
        }
        while(nn>0){
            if(nn%2 == 1){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0){
            ans=(double)(1.0)/(double)(ans);
        }
        return ans;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        int exp = sc.nextInt();
        System.out.println(power(x, exp));
        sc.close();
    }
}