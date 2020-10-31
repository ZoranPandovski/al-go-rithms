<?php

function fahrenheitToCelsius($fahrenheit)
{
    $factor = 5/9;

    return round(($fahrenheit - 32.0) * $factor, 2);
}

$testCases = [
    32 => 0,
    -40 => -40,
    10 => -12.22,
    91 => 32.78,
    "-459.67" => -273.15,
    "98.6" => 37,
    212 => 100
];

foreach ($testCases as $testCase => $expectedResult) {
    $celsius = fahrenheitToCelsius(floatval($testCase));
    if (floatval($celsius) !== floatval($expectedResult)) {
        echo sprintf(
            "Algorithm is not working properly. It returns that \"%s\" fahrenheit degrees is %s celsius degrees while it is %s celsius degrees\n",
            $testCase,
            $celsius,
            $expectedResult
        );
    }
}
