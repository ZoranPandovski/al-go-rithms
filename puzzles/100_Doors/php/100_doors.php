#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Problem Statement: 
 *  There are 100 doors in a row, all doors are initially closed. A person walks through all doors multiple times and toggle (if open then close, if close then open) them in following way:
 *
 *  In first walk, the person toggles every door
 *
 *  In second walk, the person toggles every second door, i.e., 2nd, 4th, 6th, 8th, ...
 *
 *  In third walk, the person toggles every third door, i.e. 3rd, 6th, 9th, ...
 *     
 *      ...
 *       
 *  In 100th walk, the person toggles 100th door.
 *
 * -----------------------------------------
 *
 * Solution:
 *
 * Door 1 is toggled in every walk.
 * Door 2 is toggled only in first and second walk. In other words whichever numbers divide it (factors of it)
 * Door 3 is toggled in 1,3 walk
 * Foor 4 is toggled in 1,2,4 walk
 *
 * So, for every door, find the count of the unique factors. 
 *
 * If this count is odd, the door is open.
 * If this count is even, the door is closed.
 *
 * -----------------------------------------
 *
 * The open door numbers is a well-known series
 * Try to guess what this series is
 *
 * Hint: When does a number have odd number of factors?
 */


const NUMBER_OF_DOORS = 100;

printf( "Open door numbers are : " );
for( $i = 1; $i <= NUMBER_OF_DOORS; $i++ ) {
		if ( get_factors_count( $i ) & 1 ) {
				printf( "%d ", $i );
		}
}
print "\n";

/* Function to find factors of a number */

function get_factors_count( $n ) {
	$factors = array();
		for( $j = 1; $j <= $n/2; $j++ ) {
			if ( ! ( $n % $j ) ) {
				$factors[] = $j;
			}
		}
		$factors[] = $n;
	return count( $factors );
}

?>
