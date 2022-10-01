<?php

declare(strict_types=1);


function transposeMatrix(array $matrix):array{
    $transposed = [];
    foreach ($matrix as $rowIndex => $row){
        foreach ($row as $columnIndex => $value) {
            $transposed[$columnIndex][$rowIndex] = $value;
        }
    }
    return $transposed;
}

function printMatrix(array $matrix):void{
    foreach ($matrix as $row){
        printf("[%s]%s", implode(' ', $row), PHP_EOL);
    }
}

$example = [
    [1, 5],
    [7, 3],
    [8, 2]
];

echo 'original matrix:' . PHP_EOL;
printMatrix($example);
echo 'transposed matrix:' . PHP_EOL;
$secondMatrix = transposeMatrix($example);
printMatrix($secondMatrix);
echo 'transposed transposed matrix (should be identical to the original matrix):' . PHP_EOL;
$thirdMatrix = transposeMatrix($secondMatrix);
printMatrix($thirdMatrix);


/**
Output:
original matrix:
[1 5]
[7 3]
[8 2]
transposed matrix:
[1 7 8]
[5 3 2]
transposed transposed matrix (should be identical to the original matrix):
[1 5]
[7 3]
[8 2]

 */