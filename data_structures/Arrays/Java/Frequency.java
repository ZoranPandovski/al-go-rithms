public class Frequency {

	public static void main(String[] args) {
		int arr[] = {1,1,1,1,1,1,3,3,3,6,6,9};
		int n=arr.length;
		System.out.println("Array : ");
		for(int i=0;i<n;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
		frequency(arr);
	}
	static void frequency(int arr[]) {
		int n=arr.length,f=1;
		for(int i=1;i<n;i++) 
		{	if(arr[i-1] != arr[i]) {
				System.out.println(arr[i-1]+" : "+f);
				f=1;
				}
			else
				f++;
		}	
		System.out.println(arr[n-1]+" : "+f);
	}

}
