<?php

include 'bubble_sort.php';

$elements = [99, 30, 53, 55, 90, 54, 8, 7, 81, 30];
$expectedElements = [7, 8, 30, 30, 53, 54, 55, 81, 90, 99];

$sortedElements = bubbleSort($elements);

if ($expectedElements !== $sortedElements) {
    echo sprintf(
        'Arrays are different, expected: [%s], got: [%s]',
        implode(',', $expectedElements),
        implode(',', $sortedElements)
    );
} else {
    echo "Elements are sorted correctly.";
}

echo PHP_EOL;
