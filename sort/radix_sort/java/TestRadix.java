package core;

public class TestRadix {

	public static void main(String[] args){
		int[] array = {2, 9, 20, 204, 42, 0, 11, 22, 99};
		Radix_Sort.sort(array);
		for(int i = 0; i < array.length; i++){
			System.out.print(array[i] + " ");
		}
	}
	
}
