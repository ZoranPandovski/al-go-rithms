#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Caesar cipher is an encryption technique
 *
 * Each letter in the plaintext is replaced by a letter some fixed number of positions down the alphabet
 *
 *
 * Test with abcde 3 -> defgh
 * Test with xyz 3 -> abc
 * Test with AMAZING -5 -> VHVUDIB
 * Test with abc123@xyz.com 53 -> bcd123@yza.dpn
 */

print "Enter a message to encrypt: ";

trim( fscanf( STDIN, "%s\n", $input ) ); // Get an input number to check

print "Enter key(a postive/negative number ): ";

trim( fscanf( STDIN, "%d\n", $encrypt_key ) ); // Get a key to apply - a positive/negative number


$encrypt_key %= 26; // Make sure that the encryption falls within the alphabet

$text_array = str_split( $input ); // Convert text to array of characters
// print_r( $text_array);

array_walk( $text_array, 'cc_encrypt', $encrypt_key); 

print( implode( "", $text_array ) ); // Convert encrypted array of characters back to text

/* Caesar Cipher encryption 
 *
 */
function cc_encrypt( &$character, $key, $encrypt_key ) {

	if( $character >= 'a' && $character <= 'z' ) {
		$newascii = ord( $character ) + $encrypt_key;
		$newascii = $newascii > ord( 'z' ) ? $newascii-26 : $newascii;
		$newascii = $newascii < ord( 'a' ) ? $newascii+26 : $newascii;
	} elseif ( $character >= 'A' && $character <= 'Z' ) {
		$newascii = ord( $character ) + $encrypt_key;
		$newascii = $newascii > ord( 'Z' ) ? $newascii-26 : $newascii;
		$newascii = $newascii < ord( 'A' ) ? $newascii+26 : $newascii;
	}
	else {
		$newascii = ord( $character );
	}
	$character = chr( $newascii );
}

?>
