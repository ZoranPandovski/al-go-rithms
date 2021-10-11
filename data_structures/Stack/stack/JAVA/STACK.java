import java.util.ArrayList;

/**
 * @author avcbcoder last modified @29-Oct-2018 @4:39:00 PM Code Library - TODO
 */

/**
 * <========================================= About Genric stack class =============================================>
 * 
 * DESCRIPTION of all the methods in stack class --------------------------------------------------------------------
 * 1.push(x) -> push x to the stack ---------------------------------------------------------------------------------
 * 2.pop(x) -> pop x from the stack ---------------------------------------------------------------------------------
 * 3.top(x) -> peeks the top of stack but doesn't removes -----------------------------------------------------------
 * 4.display() -> prints all the elements in stack from top to bottom -----------------------------------------------
 * 5.isEmpty() -> returns true if stack is empty --------------------------------------------------------------------
 */

/** 
 */

public class STACK<T> {

	/**
	 * For Debugging
	 */
	public static void main(String[] args) throws Exception {
		STACK<Integer> st = new STACK<Integer>();
		st.push(1);
		st.push(10);
		st.push(5);
		st.push(8);
		st.display();
		System.out.println("Removed " + st.pop());
		st.display();
	}

	protected ArrayList<T> data = new ArrayList<>();
	protected int tos = -1;
	protected T defaultValue = null;

	public STACK() {
		this(10);
	}

	public STACK(int initialCapacity) {
		this.data = new ArrayList<>();
	}

	public void push(T value) throws Exception {
		this.tos++;
		if (this.tos < data.size())
			data.set(this.tos, value);
		else
			data.add(value);
	}

	public T top() throws Exception {
		if (tos == -1)
			throw new Exception("stack is empty");
		return data.get(this.tos);
	}

	public T pop() throws Exception {
		if (tos == -1)
			throw new Exception("stack is empty");
		else {
			T rv = this.data.get(this.tos);
			this.data.set(this.tos, defaultValue);
			this.tos--;
			return (rv);
		}
	}

	public int size() {
		return this.tos + 1;
	}

	public boolean isEmpty() {
		if (this.tos == -1)
			return true;
		return false;
	}

	public void display() {
		System.out.println("---------------------------");
		System.out.print("top-> ");
		for (int i = this.tos; i >= 0; i--)
			System.out.print(this.data.get(i) + "  ");
		System.out.print("<-bottom");
		System.out.println("\n---------------------------");
	}
}
