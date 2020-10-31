<?php

function decimalToBinary($decimalNumber)
{
    $binary = "";
    while ($decimalNumber > 0) {
        $binary = ($decimalNumber % 2) . $binary;
        $decimalNumber = (int) ($decimalNumber / 2);
    }

    return $binary;
}

$testCases = [
    3 => "11",
    7 => "111",
    10 => "1010",
    73 => "1001001",
    128 => "10000000",
    672364 => "10100100001001101100",
    81236788123 => "1001011101010000101110000001110011011"
];

foreach ($testCases as $testCase => $expectedResult) {
    $binary = decimalToBinary($testCase);
    if ($binary !== $expectedResult) {
        echo sprintf(
            "Algorithm is not working properly. It returns that decimal \"%d\" is binary \"%s\" but it should be \"%s\"\n",
            $testCase,
            $binary,
            $expectedResult
        );
    }
}
