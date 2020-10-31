<?php

function euclidsGcd($a, $b) {
    if ($a % $b === 0) {
        return $b;
    }

    return euclidsGcd($b, $a % $b);
}

$testCases = [
    ['a' => 2, 'b' => 4, 'expected' => 2],
    ['a' => 270, 'b' => 192, 'expected' => 6],
    ['a' => 738, 'b' => 523, 'expected' => 1],
    ['a' => 90, 'b' => 35, 'expected' => 5],
    ['a' => 123456, 'b' => 654321, 'expected' => 3]
];

foreach ($testCases as $testCase) {
    $euclidsGcd = euclidsGcd($testCase['a'], $testCase['b']);
    if ($euclidsGcd !== $testCase['expected']) {
        echo sprintf(
            "Algorithm is not working properly. It returns that GCD for \"%s\" and \"%s\" is %s while it is %s\n",
            $testCase['a'],
            $testCase['b'],
            $euclidsGcd,
            $testCase['expected']
        );
    }
}
