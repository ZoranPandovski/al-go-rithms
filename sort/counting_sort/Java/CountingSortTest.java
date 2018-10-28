
public class CountingSortTest {

	public static void main(String...args) {
		int arr[]= {10,8,9,10,8,7,6,4,4,10,3,2,1,5,4,6,7,9};
		new CountSort().sort(arr);
		for(int i=0;i<arr.length-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				System.out.println("Array is not sorted");
				System.exit(1);
			}
		}
		System.out.println("Array is sorted");
		
	}
}
