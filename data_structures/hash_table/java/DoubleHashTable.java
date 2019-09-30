import java.util.Arrays;

/**
 * Basic doubly-hashed table implementation
 * 0 is used to indicate an empty slot
 * Adjust hash functions hash1() and hash2() as desired, as well as 
 * when to rehash using MAX_LOAD
 * I recommend not changing hash1()'s equation because it improves the likelihood of finding open slots.
 * In general, try to create equations that will resolve to a wide variety of numbers
 * 
 * Math.abs() is used throughout to ensure any negative numbers passed through hash functions
 * resolve to a positive value
 * 
 * @author Abe Ramseyer
 */
public class DoubleHashTable {
	private int[] table;					// the table to store all the values in
	private int size;						// the current size of the table
	private int load;						// how full the table is
	private int rehashCount;				// how many times the table has rehashed while adding elements
	private final double MAX_LOAD = 0.5;	// maximum load ratio until table rehashes
	
	public DoubleHashTable(int size) {
		this.size = size;
		rehashCount = 0;
		load = 0;
		table = new int[size];
	}
	
	public void insert(int num) {
		if (num == 0) return;	// 0 is our indication that a cell is empty, so disallow it in this table (could be avoided if using a List for the table)
		int collisions = 0;
		if(table[Math.abs(hash1(num))] == 0) {
			table[Math.abs(hash1(num))] = num;
		}
		else {
			do {collisions++; }
			while(table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] != 0);	// find the correct position, resolving collisions via a second hash function
			table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] = num;			// INSERT
		}
		load++;
		
		if((double) load / size >= MAX_LOAD) rehash();
	}
	
	/*
	 * change at your own risk, this is the most optimized hash function in this scenario
	 */
	private int hash1(int x) {
		return x % size;
	}
	
	/*
	 * feel free to experiment
	 */
	private int hash2(int x) {
		return 7 - x % 7;
	}
	
	/**
	 * finds a number in the hash table
	 * @param num
	 * @return if the number was found or not
	 */																// this could be re-written to return the index at which the value was found (-1 for not found). It would 
		public boolean find(int num) {								// remove a lot of duplicate code that I have between here and the delete method
		if (num == 0) return false;
		int collisions = 0;
		if(table[Math.abs(hash1(num))] == num) { // the number is where it should be
			return true;
		}
		if(table[Math.abs(hash1(num))] == 0) {	// found 0 in the first place that number would be
			return false;
		}
		else {
			do {collisions++; }
			while(table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] != 0 &&
					table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] != num);	// search table until we find 0 or the number
			if(table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] == num)
				return true;
			else
				return false;
		}
	}
	
	/**
	 * deletes a number from the hash table
	 * @param num
	 * @return whether the number was successfully deleted or not
	 */
	public boolean delete(int num) {
		if (num == 0) return false;
		int collisions = 0;
		if(table[Math.abs(hash1(num))] == num) { // the number is where it should be
			table[Math.abs(hash1(num))] = 0; 	 // reset to 0, "freeing" the space
			load--;
			return true;
		}
		if(table[Math.abs(hash1(num))] == 0) {	// found 0 in the first place that number would be
			return false;
		}
		else {
			do {collisions++; }
			while(table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] != 0 &&
					table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] != num);	// search table until we find 0 or the number
			if(table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] == num) {
				table[Math.abs(hash1(hash1(num)+collisions*hash2(num)))] = num;
				load--;
				return true;
			}
			else
				return false;
		}
	}
	
	/*
	 * creates a new table of a size that is a prime number and
	 * at least twice as big as the previous table, then re-insert everything
	 */
	private void rehash() {
		int[] temp = table;
		size = nextPrime(size*2);
		table = new int[size];
		load = 0;
		for(int num : temp) {
			if(num != 0) insert(num);
		}
		rehashCount++;
	}

	/*
	 * gives the next prime number after initial value. There's probably a more efficient
	 * way to do this, but this is fairly straightforward to understand
	 * and not the focus of this data structure
	 */
	private int nextPrime(int start) {
		for(int i = start+1; true ;i++) {
			boolean isPrime = true;
			for(int j = 2; j < i/2; j++) {	// if this number is prime, the inner if
				if (i % j == 0) {			// statement will never fire and the method will return
					isPrime = false;
					break;
				}
			}
			if (isPrime) return i;
		}
	}
	
	public int getRehashCount() {
		return rehashCount;
	}
	
	public int getSize() {
		return size;
	}
	
	public int getLoad() {
		return load;
	}
	
	public String toString() {
		return Arrays.toString(table);
	}
	
}
