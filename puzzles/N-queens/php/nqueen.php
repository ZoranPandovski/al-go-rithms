<?php

declare(strict_types=1);

/**
 * This file is written in PHP 8.0
 */

/** N is the number of queens and also the number os rows and columns */
const N = 4;

function getEmptyBoard():array{
    return array_fill(
        0,
        N,
        array_fill(
            0,
            N,
            0
        )
    );
}

function printBoard(array $board): void{
    foreach($board as $line) {
        echo implode(' ', $line) . PHP_EOL;
    }
}

function solveNQueensUntil(array &$board, int $col): bool
{
    if ($col >= N){
        return true;
    }

    for($i = 0; $i < N; $i++){
        if (isSafe($board, $i, $col)) {
            $board[$i][$col] = 1;

            if (solveNQueensUntil($board, $col + 1)) {
                return true;
            }

            $board[$i][$col] = 0; // BACKTRACK
        }
    }
    
    return false;
}

function isSafe($board, $row, $col): bool
{
    /* Check this row on left side */
    for ($i = 0; $i < $col; $i++){
        if ($board[$row][$i]) {
            return false;
        }
    }

    for ($i = $row, $j = $col; $i >= 0 && $j >= 0; $i--, $j--) {
        if ($board[$i][$j]) {
            return false;
        }
    }
  
    for ($i = $row, $j = $col; $j >= 0 && $i < N; $i++, $j--) {
        if ($board[$i][$j]) {
            return false;
        }
    }
  
    return true;
}

$board = getEmptyBoard();

$result = solveNQueensUntil($board, 0);

if ($result === false){
    printf('There is no solution for the N = %d',  N);
} else {
    printBoard($board);
}

