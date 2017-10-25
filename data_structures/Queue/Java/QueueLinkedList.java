import java.util.LinkedList;

public class QueueLinkedList<T> {

	LinkedList<T> list = new LinkedList<T>();

	public void enqueue(final T item) {
		if (item == null) {
			return;
		}
		list.addLast(item);
	}

	public T dequeue() {
		if (list.isEmpty()) {
			throw null;
		}
		T x;
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
