public class Linked_List_Test {

	public static void main(String[] args) throws Exception {
		Linked_List<String> list = new Linked_List<>();
		
		list.display();
		
		list.addFirst("Universe");		
		list.addFirst("Code");
		list.addFirst("hey");
		list.display();
		
		list.addLast("Like");
		list.addLast("Heaven");
		list.addLast("Whole");
		list.display();

		System.out.println("first element: " +list.getFirst());
		System.out.println("last element: " +list.getLast());
		System.out.println("size of list: "+list.size());

		list.removeFirst();
		list.display();

		list.removeLast();
		list.display();

		System.out.println("is empty: "+list.isEmpty());

	}
}
