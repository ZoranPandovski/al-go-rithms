<?php
// FizzBuzz
// Count up between two given numbers
// For multiples of 3, print "Fizz"
// For multiples of 5, print "Buzz"
// For multiples of both 3 and 5, print "FizzBuzz"

function fizzbuzz($lower, $upper)
{
	for ($i = $lower; $i = $upper; $i++){
		if ($i % 3 == 0 && $i % 5 == 0){
			echo $i . ' - FizzBuzz<br />';
		}
		else if ($i % 3 == 0){
			echo $i . ' - Fizz<br />';
		}
		else if ($i % 5 == 0){
			echo $i . ' -  Buzz<br />';
		}
		else {
			echo $i . '<br />';
		}
	}
}
