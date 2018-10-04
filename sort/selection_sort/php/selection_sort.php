<?php

function selectionSort(&$elements) {
    $elementCount = count($elements);
    for ($i = 0; $i < $elementCount - 1; $i++) {
        $min = $i;
        for ($pointer = $i + 1; $pointer < $elementCount; $pointer++) {
            $min = ($elements[$pointer] < $elements[$min] ? $pointer : $min);
        }
        $tmp = $elements[$i];
        $elements[$i] = $elements[$min];
        $elements[$min] = $tmp;
    }
}

$elements = [31,25,14,18,36,95,81,5,11,44,77];
$sortedElements = [5,11,14,18,25,31,36,44,77,81,95];

selectionSort($elements);
if ($elements !== $sortedElements) {
    echo sprintf(
        "Test failed, array was not sorted properly. \nSorted array: %s\nExpected array: %s",
        implode(", ", $elements), 
        implode(", ", $sortedElements)
    );
} else {
    echo "Test passed.";
}
