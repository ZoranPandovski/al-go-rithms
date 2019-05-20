#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Check if an input number is odd or even using bit manipulation
 *
 *
 * Take an input number. Do a bitwise AND with 1. 
 *
 * If it is true, then it is odd.
 *
 * If it is false, then it is even
 *
 * Test with 1 - Odd
 * Test with 4 - Even
 * Test with 0 - 
 * Test with -16 - Automorphic
 * Test with -25 - Automorphic
 * Test with 9375 - Not automorphic
 */
print "Enter an integer to check if it is odd or even:";
trim( fscanf( STDIN, "%d\n", $input ) ); // Get an input number to check

if( $input & 1 ) {
	print $input . " is odd\n";
} else {
	print $input . " is even\n";
}
?>
