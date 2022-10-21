<?php
// Iterative function to
// reverse digits of num
function reverseDigits($num)
{
	$rev_num = 0;
	while($num > 1)
	{
		$rev_num = $rev_num * 10 +
						$num % 10;
		$num = (int)$num / 10;
	}
	return $rev_num;
}

// Driver Code
$num = 4562;
echo "Reverse of no. is ",
	reverseDigits($num);

// This code is contributed by aj_36
?>
