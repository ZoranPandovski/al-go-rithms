#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Sum of factorials of its digits is equal to the strong number
 *
 * First take each digit of the number from the ones position.
 * Divide by 10 and the modulo is the facevalue  of the digit.
 * The quotient is the remaining part.
 * Keep doing this for the number of digits in the number.
 *
 * Everytime a digit is got, find its factorial and add it to the sum.
 *
 * Finally check if the sum is equal to the input number
 *
 *
 * Test with -1 - Not a strong number
 * Test with 0 - Not a strong number
 * Test with 1 - A strong number
 * Test with 2 - A strong number
 * Test with 3 - Not a strong number
 * Test with 145 - A strong number
 */

print "Enter a positive integer to check if it is a strong number:";

trim( fscanf( STDIN, "%d\n", $input ) ); // Get an input number to check

if( 0 <= $input ) {
	$sum = 0;
	$number = $input;
	$num_digits = strlen( (string) $number ); // Find number of digits in the number
	for( $i=0; $i < $num_digits; $i++ ) {
		$digit = $number%10;
		$number = (int) $number/10;
		$sum += factorial( $digit );
	}
	// print $sum."\n";
	if( $sum === $input ) {
		print $input . " is a strong number\n";
	} else {
		print $input . " is not a strong number\n";
	}
} else {
	print $input . " is not a strong number\n";
}

/* Function to find factorial of a number */

function factorial( $n ) {
	if ( 1 >= $n ) {
		return 1;
	} else {
		return $n * factorial( $n-1 );
	}
}

?>
