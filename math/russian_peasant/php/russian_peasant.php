<?php

function russianPeasant($a, $b)
{
    $result = 0;
    while ($a > 0) {
        if ($a % 2 == 1) {
            $result += $b;
        }
        $a >>= 1;
        $b <<= 1;
    }
    
    return $result;
}

if (russianPeasant(5, 15) != 75) {
    echo "Test failed.";
} else {
    echo "Test passed.";
}
