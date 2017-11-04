import java.util.Arrays;

/**
 * Basic quadratic hash table implementation
 * 0 is used to indicate an empty slot
 * 
 * Math.abs() is used throughout to ensure any negative numbers passed through hash functions
 * resolve to a positive value
 * 
 * @author Abe Ramseyer
 */
public class QuadraticHashTable {
	private int[] table;
	private int size;
	private int load;
	private int rehashCount;
	private final double MAX_LOAD = 0.5;
	
	public QuadraticHashTable(int size) {
		this.size = size;
		rehashCount = 0;
		load = 0;
		table = new int[size];
	}
	
	/**
	 * inserts a number into the hash table
	 * @param num
	 */
	public void insert(int num) {
		if (num == 0) return;	// 0 is our indication that a cell is empty, so disallow it in this table (could be avoided if using a List for the table)
		int collisions = 0;
		if(table[Math.abs(hash1(num))] == 0) {
			table[Math.abs(hash1(num))] = num;
		}
		else {
			do {collisions++; }
			while(table[Math.abs(hash1(hash1(num)+collisions*collisions))] != 0);	// find the correct position, resolving collisions quadratically
			table[Math.abs(hash1(hash1(num)+collisions*collisions))] = num;			// INSERT
		}
		load++;

		
		if((double) load / size >= MAX_LOAD) rehash();
	}
	
	/**
	 * finds a number in the hash table
	 * @param num
	 * @return if the number was found or not
	 */
	public boolean find(int num) {
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
			while(table[Math.abs(hash1(hash1(num)+collisions*collisions))] != 0 &&
					table[Math.abs(hash1(hash1(num)+collisions*collisions))] != num);	// search table until we find 0 or the number
			if(table[Math.abs(hash1(hash1(num)+collisions*collisions))] == num)
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
			table[Math.abs(hash1(num))] = 0;	 // reset to 0, "freeing" the space
			load--;
			return true;
		}
		if(table[Math.abs(hash1(num))] == 0) {	// found 0 in the first place that number would be
			return false;
		}
		else {
			do {collisions++; }
			while(table[Math.abs(hash1(hash1(num)+collisions*collisions))] != 0 &&
					table[Math.abs(hash1(hash1(num)+collisions*collisions))] != num);	// search table until we find 0 or the number
			if(table[Math.abs(hash1(hash1(num)+collisions*collisions))] == num) {
				table[Math.abs(hash1(hash1(num)+collisions*collisions))] = 0;
				load--;
				return true;
			}
			else
				return false;
		}
	}
	
	/*
	 * change at your own risk, this is the most optimized hash function in this scenario
	 */
	private int hash1(int x) {
		return x % size;
	}
	
	/*
	 * creates a new table of a size that is a prime number and
	 * at least twice as big as the previous table, then re-insert everything
	 */
	private void rehash() {
		int[] temp = table;
		size = nextPrime(size*2-1);
		table = new int[size];
		load = 0;
		for(int num : temp) {
			if(num != 0) insert(num);
		}
		rehashCount++;
	}
	
	/*
	 * Calculates the next prime number after initial value. There's probably a more efficient
	 * way to calculate this, but this is fairly straightforward to understand
	 * and not the focus of this data structure
	 */
	private int nextPrime(int start) {
		for(int i = start+1; true ;i++) {
			boolean isPrime = true;
			for(int j = 2; j < i/2; j++) { // if this number is prime, the inner if
				if (i % j == 0) {		   // statement will never fire and the method will return
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
