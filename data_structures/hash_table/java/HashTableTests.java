import java.util.Random;

/**
 * tests the quadratic and double hash tables
 * @author Abe Ramseyer
 */
public class HashTableTests {
	public static void main(String args[]) {
		
		Random gen = new Random();
		DoubleHashTable hashed = new DoubleHashTable(11);
		QuadraticHashTable hashed2 = new QuadraticHashTable(11);

		// insert random values into first table, modify 20 to change amount
		int num=1;
		for(int i = 0; i < 20; i++) {
			num = gen.nextInt();
			hashed.insert(num);
		}
		System.out.println("---Doubly Hashed Table Tests---\n" + hashed);
		System.out.printf("rehashed: " + hashed.getRehashCount() + 
				"\nload: " + hashed.getLoad() + "/" + hashed.getSize() + ": %.2f%n",  ((double) hashed.getLoad()/hashed.getSize()));
		System.out.println("checking for " + (num+1) + " in the table: " + hashed.find(num+1));	// intentionally look for a value that is probably not in the table
		System.out.println("deleting " + (num+1) + " from table: " + hashed.delete(num+1) +			
				"\nnew load: " + hashed.getLoad());
		System.out.println(hashed);
		
		System.out.println("\n");

		// insert random values into second table, modify 20 to change amount
		for(int i = 0; i < 20; i++) {
			num = gen.nextInt();
			hashed2.insert(num);
		}
		
		System.out.println("---Quadraticly Hashed Table Tests---\n" + hashed2);
		System.out.printf("rehashed: " + hashed2.getRehashCount() + 
				"\nload: " + hashed2.getLoad() + "/" + hashed2.getSize() + ": %.2f%n",  ((double) hashed2.getLoad()/hashed2.getSize()));
		System.out.println("checking for " + num + " in the table: " + hashed2.find(num));	// this value will definitely be in the table
		System.out.println("deleting " + num + " from table: " + hashed2.delete(num) +
				"\nnew load: " + hashed2.getLoad());
		System.out.println(hashed2);
		
	}
}

