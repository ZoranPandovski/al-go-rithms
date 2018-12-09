#!/usr/local/bin/php
<?php
/* 
 * @Author: Menaka S.
 * @Email: menakas.menakas@gmail.com
 *
 * Problem Statement: 
 * Write a program that randomly chooses and displays four digits, each from 1 ──► 9 (inclusive) with repetitions allowed.
 *
 * The program should prompt for the player to enter an arithmetic expression using just those, and all of those four digits, used exactly once each. The program should check then evaluate the expression.
 *
 * The goal is for the player to enter an expression that (numerically) evaluates to 24.
 *
 * Only the following operators/functions are allowed: multiplication, division, addition, subtraction
 * Division should use floating point or rational arithmetic, etc, to preserve remainders.
 * Brackets are allowed, if using an infix expression evaluator.
 * Forming multiple digit numbers from the supplied digits is disallowed. (So an answer of 12+12 when given 1, 2, 2, and 1 is wrong).
 * The order of the digits when given does not have to be preserved.
 *	
 *
 * Solution:
 *
 * Generate four digits at random and sort them
 * Get the expression from the user
 *
 * Squeeze out all the whitespace
 *
 * Parse through the expression. Use a stack to push the first operand and the operator in.
 * Whenever there is a second operand, pop out the operator and operand from the stack and perform the operation. Push the result back into the stack.
 *
 * When there is an open bracket, push it in.
 * When there is a closed bracket, calculate the expression up to the open bracket, by popping from the stack
 *
 * Keep a count of the number of digits encountered.
 * Also, ensure that the digits are those from the generated numbers
 *
 */


for ( $i=0; $i < 4; $i++ ) {
	$numbers[$i] = rand(1,9);
	//$numbers = array( 7, 9, 8, 4 );
}

printf("Your numbers are:\n" . implode( " ", $numbers ) . "\n");
	
sort($numbers);

while ( $expr = readline("Enter expression (Use only + - * / and parens; Ctrl+D to exit):") ) { // Get an input expression

	$expr = preg_replace('/\s+/', '', $expr); // Squeeze out all whitespace
	if ( check_24( $numbers, $expr ) ) {
		print( "You did a great job!\n");
		exit(0);
	}
	printf("Try again:");
}

function is_operator( $char ) {
	if ( '+' === $char || ( '-' === $char ) || ( '*' === $char ) || ( '/' === $char ) ) {
		return 1;
	}
	return 0;

}

function is_digit( $char ) {
	if ( $char >= '1' && $char <= '9' ) { 
		return 1;
	}
	return 0;

}

function calculate_result( &$stack, $operand) {

	if ( empty( $stack ) ) {
		array_push($stack, $operand);
	} elseif (  '(' === end($stack) ) {
		array_push($stack, $operand);
	} else {
		$operator = array_pop($stack);
		$digit = array_pop($stack);
		switch( $operator ) {
			case '+': array_push($stack, $digit + $operand);
						break;
			case '-': array_push($stack, $digit - $operand);
						break;
			case '*': array_push($stack, $digit * $operand);
						break;
			case '/': array_push($stack, $digit / $operand);
						break;
			default: return 0;
		}
	}
	return 1;
}

function check_24( $numbers, $expr ) {

	$counter = 0;
	$stack = array();

	for( $i=0; $i< strlen( $expr ); $i++) {

		if ( is_digit( $expr[ $i ] ) ) {
	
			// Is it one of the four digits?
			if ( ( $key = array_search( intval( $expr[ $i ] ), $numbers ) ) !== false ) {
				unset( $numbers[$key] );
				$counter++;
				calculate_result( $stack, intval( $expr[ $i ] ) );
			}
		} elseif ( is_operator( $expr[ $i ] ) || ( '(' === $expr[ $i ] ) ) {
				array_push( $stack, $expr[ $i ] );

		} elseif ( ')' === $expr[ $i ] ) {
				$value = array_pop( $stack );
				if( '(' === end( $stack) ) {
					array_pop( $stack ); // pop out the open bracket
				}
				calculate_result( $stack, $value );

		}
		print_r( $stack );
		print("=============\n\n");

	}


	if ( ( 4 !== $counter ) || ( 1 !== count( $stack ) ) || ( 24 !== array_pop( $stack ) ) ) {
		return 0;
	}
	return 1;

}
