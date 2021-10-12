<?php

function sumOfNumbers($num): int
{
    $sum = 0;
    for ($i = 1; $i <= $num; $i++) {
        $sum += $i;
    }
    return $sum;
}

echo sumOfNumbers(4); // 10
echo sumOfNumbers(5); // 15
echo sumOfNumbers(6); // 21
