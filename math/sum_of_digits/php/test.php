<?php

require_once 'sumOfDigits.php';

function test($expected, $given) {
    if ($expected !== $given) {
        echo sprintf('Invalid sum. Expected %d, got %d', $expected, $given) . PHP_EOL;
    }
}

test(6, sumOfDigits(123));
test(6, sumOfDigits('123'));
test(45, sumOfDigits(123456789));

