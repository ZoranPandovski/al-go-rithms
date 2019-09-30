
public class QueueArray<T> {

	private int first = -1;
	private int last = -1;
	private int size = 0;
	private int sizequeuee;
	public T[] x;

	queueArray(final int sizequeue) {
		x = (T[]) new Object[sizequeue];
		this.sizequeuee = sizequeue;
	}
	
	public boolean full() {
		return ((first == last && last != -1 && first != -1) || (first == -1 && last == (x.length - 1)));
	}

	public void enqueue(final T item) {
		if (this.full()) {
			throw null;
		}
		last = (last + 1) % x.length;
		x[last] = item;
		size++;

	}

	public T dequeue() {
		if (this.isEmpty()) {
			throw null;
		}
		first = (first + 1) % x.length;
		T z = x[first];
		if (first == last) {
			first = -1;
			last = -1;
		}
		size--;
		return z;
	}

	public boolean isEmpty() {
		return first == -1 && last == -1;
	}

	public int size() {
		return size;
	}

}
