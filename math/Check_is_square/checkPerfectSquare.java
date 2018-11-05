// Java program to find if x is a 
// perfect square. 

import java.util.*;
import java.lang.*;
import java.io.*;
class checkSquare 
{ 
     static boolean isPerfectSquare(double x)  
     { 
          
        // Find floating point value of 
        // square root of x. 
        double sr = Math.sqrt(x); 
      
        // If square root is an integer 
        return ((sr - Math.floor(sr)) == 0); 
     } 
      
    // Driver code 
    public static void main(String[] args)  
    { 
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble(); 
          
        if (isPerfectSquare(x)) 
            System.out.print("Yes"); 
        else
            System.out.print("No"); 
    } 
} 
