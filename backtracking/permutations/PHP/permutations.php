<?php

# PHP 7.0.8+

/**
 * Print all permutations of a given string
 *
 * @param string $entry
 * @param int [$level]
 */
function permute(string $entry, int $level = 0)
{
    static $num = 0;
    $length = strlen($entry);

    if ($level === $length) {
        print(++$num.". $entry\n");
        return;
    }

    for($ix = $level; $ix < $length; $ix++) {
        $entry = swap($entry, $level, $ix);
        permute($entry, $level + 1);
    }
}

/**
 * Swaps char position of a given string
 *
 * @param string $input
 * @param int $fromIndex
 * @param int $toIndex
 * @return string
 */
function swap(string $input, int $fromIndex, int $toIndex) : string
{
    $swapFrom = $input[$fromIndex];
    $input[$fromIndex] = $input[$toIndex];
    $input[$toIndex] = $swapFrom;

    return $input;
}

/**
 * Example:
 *
 * permute('abc');
 *
 * Output:
 *  1. abc
 *  2. acb
 *  3. bac
 *  4. bca
 *  5. cab
 *  6. cba
 */

# Test

$expectedResult = <<<EOD
1. abc
2. acb
3. bac
4. bca
5. cab
6. cba

EOD;

ob_start();
permute('abc');
$result = ob_get_contents();
ob_end_clean();

if ($result === $expectedResult) {
    print('Success');
} else {
    print('fail');
}

print(" ==> \n\n$result");