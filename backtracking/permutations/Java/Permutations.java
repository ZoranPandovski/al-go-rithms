import java.util.*;

public class Permutations
{
	public static void main( String[] args )
	{
		String input = "abc";
		ArrayList<String> collection = new ArrayList<>( Arrays.asList( input.split( "" ) ) );
		String[] permutation = new String[collection.size()];

		constructPermutations( collection, permutation );
	}
	
	private static void constructPermutations( ArrayList<String> collection, String[] permutation )
	{
		// If is the solution
		if( collection.isEmpty() )
		{
			// Show it
			for( String s : permutation )
			{
				System.out.print( s + " " );
			}
			System.out.println();
		}
		else
		{
			int pos = permutation.length - collection.size();
			
			// The candidates are inside the collection, for each candidate...
			for( int i = 0; i < collection.size(); ++i )
			{
				// get the candidate from the collection
				String candidate = collection.get( i );
				collection.remove( i );
				
				// put the candidate inside the partial solution
				permutation[pos] = candidate;
				
				// resolve the rest of problems
				constructPermutations( collection, permutation );
			 
				// cleanup
				permutation[pos] = null;
				collection.add( i, candidate );
			}
		}
	}

}
