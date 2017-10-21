<?php

function permute(string $entry, int $level = 0)
{
    static $num = 0;
    $length = strlen($entry);

    if ($level === $length) {
        print(++$num.". $entry\n");
        return;
    }

    for($ix = $level; $ix < $length; $ix++) {
        $entry = swap($entry, $level, $ix);
        permute($entry, $level + 1);
    }
}

function swap(string $input, int $fromIndex, int $toIndex) : string
{
    $swapFrom = $input[$fromIndex];
    $input[$fromIndex] = $input[$toIndex];
    $input[$toIndex] = $swapFrom;

    return $input;
}

permute('abc');
