<?php

function isPalindrome($string)
{
    if (!is_string($string)) {
        throw new Exception("Invalid input");
    }

    $normalizedString = strtolower(preg_replace("/[^\da-z]/i", "", $string));

    return $normalizedString === strrev($normalizedString);
}

// All test cases from the README.md
$testCases = [
    'mam' => true,
    'man' => false,
    'a man a plan a canal panama' => true,
    'Able was I, ere I saw elba' => true,
    'Straw warts' => true,
    "A Toyota's a Toyota." => true,
    'Cigar? Toss it in a can. It is so tragic.' => true,
    'Chandoo.org makes you awesome' => false,
    "Dammit, I'm mad!" => true
];

foreach ($testCases as $testCase => $expectedResult) {
    $isPalindrome = isPalindrome($testCase);
    if ($isPalindrome !== $expectedResult) {
        echo sprintf(
            "Algorithm is not working properly. It returns that string \"%s\" is %s while it is %s\n",
            $testCase,
            $isPalindrome ? "a palindrome" : "not a palindrome",
            $expectedResult ? "a palindrome" : "not a palindrome"
        );
    }
}
