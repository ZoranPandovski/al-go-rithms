 /*-----------------------------------------------------------------------------------
 * <p> Title: Dynamic Array  </p>
 *
 * <p> Description: A program that implements the Arraylist in Java Utils package </p>
 *
 * @author Venkatesh Bejjenki
 *------------------------------------------------------------------------------------
*/


class DynamicArrayImplementation {
	private int size,capacity;
	private int[] elements;
	public DynamicArrayImplementation(){
		size=0;
		capacity=1;
		elements=new int[capacity];
	}
	public void add(int e){
		if (size==capacity)
			increaseCapacity();
		elements[size++]=e;
	}
	public int get(int index){
		return elements[index];
	}
	private void increaseCapacity(){
		int[] temp = new int[++capacity];
		copyArray(temp,elements);
		elements=temp;
	}
	public void copyArray(int [] first,int [] second){
		for(int i=0;i<second.length;i++)
			first[i]=second[i];
	}
	public int size(){
		return elements.length;
	
	}
}
class DynamicArray{
	public static void main(String[] args) {
		DynamicArrayImplementation l =new DynamicArrayImplementation();
		l.add(1);
		l.add(2);
		int size=l.size();
		for (int k=0;k<size;k++)
		System.out.println(l.get(k));
	}
}
