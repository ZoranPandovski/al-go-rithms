<?php

/**
 * @param $number
 * @return int
 */
function sumOfDigits($number)
{
    $number = '' . $number;

    $sum = 0;
    for ($i = 0; $i < strlen($number); $i++) {
        $sum += $number[$i];
    }

    return $sum;
}
