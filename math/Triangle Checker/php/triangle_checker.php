<?php
// Triangle Checker
// Validates if a triangle is possible with 3 side lengths
//
// The sum of any 2 side lengths must be greater than the 3rd side

function isTriangle($a, $b, $c)
{
	
	if ($a + $b > $c ||
	    $a + $c > $b ||
	    $b + $c > $a)
		return true;
	else
		return false;
}

// Valid
// $a = 3;
// $b = 4;
// $c = 5;

// Invalid
// $a = 1;
// $b = 2;
// $c = 5;
	
	if (isTriangle($a, $b, $c))
		echo "This is a triangle";
	else
		echo "This is not a triangle";
		
?>

