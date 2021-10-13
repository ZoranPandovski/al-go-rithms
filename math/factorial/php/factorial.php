<?php

function factorial ($num) {
    $result = 1;
    for ($i = 1; $i <= $num; $i++){
        $result = $result * $i;
    }
    return $result;
}

echo factorial(5);
echo factorial(8);
echo factorial(10);
