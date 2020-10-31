<?php

function sumOfDigits($number)
{
    return array_sum(str_split((string) $number));
}

$testCases = [
    123456 => 21,
    222 => 6,
    999 => 27,
    9723849 => 42,
    1 => 1
];

foreach ($testCases as $testCase => $expectedResult) {
    $sum = sumOfDigits($testCase);
    if ($sum !== $expectedResult) {
        echo sprintf(
            "Algorithm is not working properly. It returns that sum of digits in number \"%d\" is %d while it should be %d\n",
            $testCase,
            $sum,
            $expectedResult
        );
    }
}
