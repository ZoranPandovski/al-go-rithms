<?php

function isSquare($num): bool
{
    $value = sqrt($num);
    if (($value - (int)$value) == 0) {
        return true;
    } else {
        return false;
    }
}

echo isSquare(4);
echo isSquare(6);