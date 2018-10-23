#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Check if an input number is automorphic
 *
 * An automorphic number's square ends with the number itself.
 *
 * Convert both the number and its square to string.
 *
 * Get the substring of the length of the input number string from the end of the square string.
 *
 * If this substring is equal to the input number then it is automorphic
 *
 * Test with 1 - Automorphic
 * Test with 4 - Not automorphic
 * Test with 5 - Automorphic
 * Test with 6 - Automorphic
 * Test with 25 - Automorphic
 * Test with 76 - Automorphic
 * Test with 9376 - Automorphic
 * Test with 10 - Not automorphic
 * Test with 50 - Not automorphic
 * Test with 75 - Not automorphic
 * Test with 9375 - Not automorphic
 */

print "Enter a positive integer to check if it is an automorphic number:";

trim( fscanf( STDIN, "%d\n", $input ) ); // Get an input number to check

$square = pow( $input, 2 );

$input_str = (string) $input;
$square_str = (string) $square;

if( substr( $square_str, strlen( $square_str ) - strlen( $input_str ), strlen( $input_str) ) == $input_str ) {
	print $input . " is an automorphic number\n";
} else {
	print $input . " is NOT an automorphic number\n";
}

?>
