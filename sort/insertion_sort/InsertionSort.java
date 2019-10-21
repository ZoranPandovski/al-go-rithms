import java.util.Scanner;
public class Program
{
    static void sort(int arr[]){
        
        for(int i=1;i<arr.length;i++){
            int key=arr[i];
            int j=i-1;
            
            while(j>=0 && arr[j]>key){
                
                arr[j+1]=arr[j];
                j-=1;
                
            }
            arr[j+1]=key;
        }
    }
	public static void main(String[] args) {
	
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter size");
	    int size=s.nextInt();
	    
	    int arr[]=new int[size];
	    System.out.println("Enter numbers");
	    for(int i=0;i<arr.length;i+=)
	    arr[i]=s.nextInt();
	    
	    sort(arr);
	    
	    for(int i=0;i<arr.length;i++)
	    System.out.print(arrr[i]+" ");
	}
}
