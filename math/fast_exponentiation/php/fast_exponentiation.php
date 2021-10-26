<?php

/**
 * Part of Cosmos by OpenGenus Foundation
 */

/**
 * This functions computes an exponent by doing repeated squares
 *
 * @param Integer $base the base
 * @param Integer $exponent the exponent (ie the number of times that the base is multiplied by itself)
 * @return Integer
 */
function fast_exponentiation(int $base, int $exponent)
{
    if ($exponent == 0) {
		return 1;
	}   

	if ($exponent == 1) {
		return $base;
	}

	if ($exponent % 2 == 0) {
		return fast_exponentiation($base*$base, $exponent/2);
	} else {
		return $base * fast_exponentiation($base*$base, ($exponent-1)/2);
	}
}

echo "Perform Fast Exponentiation\n";
$test_data = [
    [10, 0, 1],
    [10, 1, 10],
    [10, 3, 1000],
    [20, 5, 3200000],
];
foreach ($test_data as $test_case) {
    $base = $test_case[0];
    $exponent = $test_case[1];
    $expected = $test_case[2];
    $result = fast_exponentiation($base, $exponent);
    printf(
        "  input: %d to the %d power, expected %d, got %d: %s\n",
        $base,
        $exponent,
        $expected,
        $result,
        ($expected === $result) ? 'OK' : 'FAIL'
    );
}