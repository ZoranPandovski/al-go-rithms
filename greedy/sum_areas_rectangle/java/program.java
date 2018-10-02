// Java code to find sum of  
// all area rectangle possible 
import java.io.*; 
import java.util.Arrays; 
  
class Main  
{ 
    // Function to find  
    // area of rectangles 
    static int MaxTotalRectangleArea(int []a,  
                                     int n) 
    { 
   
        Arrays.sort(a); 

        int sum = 0; 
        boolean flag = false; 
      
        int len = 0; 
          
        for (int i = 0; i < n; i++)  
        { 
              
    
            if ((a[i] == a[i + 1] ||  
                 a[i] - a[i + 1] == 1) &&  
                               !flag)  
            { 
       
                flag = true; 
      
  
                len = a[i + 1]; 
      

                i++; 
            } 
      
      
            else if ((a[i] == a[i + 1] ||  
                      a[i] - a[i + 1] == 1) &&  
                                    (flag))  
                { 

                    sum = sum + a[i + 1] * len; 
      
                    flag = false; 
      
                    i++; 
                } 
        } 
      
        return sum; 
    } 
      
    // Driver code 
    public static void main (String args[]) 
    { 
    int []a = { 10, 10, 10, 10, 
                11, 10, 11, 10, 
                9, 9, 8, 8 }; 
    int n = a.length; 
      
    System.out.print(MaxTotalRectangleArea(a, n)); 
    } 
} 