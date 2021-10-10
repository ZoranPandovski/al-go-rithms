/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Solution {
    public static void main(String[] args)
     {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter num of rows: ");
        int rows = input.nextInt();
       
        System.out.print("Enter num of cols: ");
        int cols = input.nextInt();
       
        int[][] matrix = new int[rows][cols];
       
        for (int i=0; i < rows; i++){
            System.out.print("Enter elements in row "+(i+1)+": ");
            for (int j=0; j < cols; j++) 
            {
                matrix[i][j] = input.nextInt();
            }
        }
       
        System.out.println("Max wealth: "+ spiralOrder(matrix));

    }
    public static List<Integer> spiralOrder(int[][] matrix) 
    {
        List<Integer> res = new ArrayList<>();
        int minR = 0, minC = 0, maxR = matrix.length-1;
        int maxC = matrix[0].length-1, count = (maxR+1)*(maxC+1);

        while (count > 0)
        {
            for (int i = minR, j = minC; j <= maxC && count > 0; j++)
            {
                res.add(matrix[i][j]);
                count --;
            }
            minR++;
            
            for (int i = minR, j = maxC; i <= maxR && count > 0; i++){
                res.add(matrix[i][j]);
                count --;
            }
            maxC--;
           
            for (int i = maxR, j = maxC; j >= minC && count > 0; j--){
                res.add(matrix[i][j]);
                count --;
            }
           
            maxR--;
                for (int i = maxR, j = minC; i >= minR && count > 0; i--){
                res.add(matrix[i][j]);
                count --;
            }
            minC++;
        
        }
        return res;
    }
}

 /*
    Constraints:
      m == matrix.length
      n == matrix[i].length
      1 <= m, n <= 10
      -100 <= matrix[i][j] <= 100
      
      
     Test Case :
      Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
      Output: [1,2,3,6,9,8,7,4,5]
     
    */  
      
      
       


