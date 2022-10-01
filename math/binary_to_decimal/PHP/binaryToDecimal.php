<?php

function binaryToDecimal($binaryNumber)
{
    $power = 0;
    $decimal = 0;
    foreach (array_reverse(str_split($binaryNumber)) as $bit) {
        if ((int) $bit === 1) {
            $decimal += pow(2, $power);
        }

        $power++;
    }

    return $decimal;
}

$testCases = [
    "11" => 3,
    "111" => 7,
    "1010" => 10,
    "1001001" => 73,
    "10000000" => 128,
    "10100100001001101100" => 672364,
    "1001011101010000101110000001110011011" => 81236788123
];

foreach ($testCases as $testCase => $expectedResult) {
    $decimal = binaryToDecimal($testCase);
    if ($decimal !== $expectedResult) {
        echo sprintf(
            "Algorithm is not working properly. It returns that binary \"%s\" is decimal \"%d\" but it should be \"%d\"\n",
            $testCase,
            $decimal,
            $expectedResult
        );
    }
}
