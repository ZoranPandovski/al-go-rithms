import java.util.LinkedList;

public class queueLinkedList {

	LinkedList<Object> list = new LinkedList<Object>();

	public void enqueue(final Object item) {
		if (item == null) {
			return;
		}
		list.addLast(item);
	}

	public Object dequeue() {
		if (list.isEmpty()) {
			throw null;
		}
		Object x;
		x = list.getFirst();
		list.removeFirst();
		return x;
	}

	public boolean isEmpty() {
		int z = list.size();
		return z == 0;
	}

	public int size() {
		return list.size();
	}

}
