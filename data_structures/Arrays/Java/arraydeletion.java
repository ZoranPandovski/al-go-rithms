import java.util.Scanner;

public class JavaProgram
{
   public static void main(String args[])
   {
       int size, i, del, count=0;
       int arr[] = new int[50];
       Scanner scan = new Scanner(System.in);
	   
       System.out.print("Enter Array Size : ");
       size = scan.nextInt();
	   
       System.out.print("Enter Array Elements : ");
       for(i=0; i<size; i++)
       {
           arr[i] = scan.nextInt();
       }
	   
       System.out.print("Enter Element to be Delete : ");
       del = scan.nextInt();
       for(i=0; i<size; i++)
       {
           if(arr[i] == del)
           {
               for(int j=i; j<(size-1); j++)
               {
                   arr[j] = arr[j+1];
               }
               count++;
               break;
           }
       }
       if(count==0)
       {
           System.out.print("Element Not Found..!!");
       }
       else
       {
           System.out.print("Element Deleted Successfully..!!");
           System.out.print("\nNow the New Array is :\n");
           for(i=0; i<(size-1); i++)
           {
               System.out.print(arr[i]+ " ");
           }
       }
   }
}
