#!/usr/bin/php
<?php
/**
 * A Silly implementation of the polybious cypher
 * Extend table to include upper and lowercase as well as punctuation
 * Support passphrase as key, duplicate letters get skipped, passphrase gets put at beginning of cypher
 * convert each 2 digit decimal to ascii and output string of encoded characters
 * We only care about visible ascii, so offset ascii table by -32. (so ascii A (DEC 65) gets encoded as 32 less than the decimal (DEC 33))
 * 
 * Usage: php poly.php "String to encode" ["Passphrase to use"]
 * TODO support filename as alternate to string to encode
 */

$polyTable = [];
$polyTableX = 10;
$polyTableY = 10;
$polyTableMax = 95;
$asciiOffset = 32;
$characterTable = [];

for ($i = 32, $count = $polyTableMax + $asciiOffset; $i < $count; $i++)
{
    $characterTable[] = chr($i);
}

/**
 * Set up passphrase
 */
$passphrase = '';

if (isset($argv[2]))
{
    $uniqueCharacters = [];
    $passphraseCharacters = str_split($argv[2]);

    foreach ($passphraseCharacters as $character)
    {
        $uniqueCharacters[$character] = true;
    }

    $passphrase = implode('', array_keys($uniqueCharacters));

    foreach (array_keys($uniqueCharacters) as $char)
    {
        $index = array_search($char, $characterTable);
        unset($characterTable[$index]);
    }

    $characterTable = array_values((array_keys($uniqueCharacters) + $characterTable));
}

/**
 * Build table
 */
$total = 0;

for ($x = 0; $x < $polyTableX; $x++)
{
    for ($y = 0; $y < $polyTableY; $y++)
    {
        if (count($characterTable) == 0)
        {
            break;
        }

        $polyTable[$x][$y] = array_shift($characterTable);
    }
}

$originalString = $argv[1];
$originalStringCharacters = str_split($originalString);
$cryptString = '';

foreach ($originalStringCharacters as $char)
{
    foreach ($polyTable as $x => $polyRow)
    {
        $y = array_search($char, $polyRow);

        if ($y !== false)
        {
            $newCharCode = (int)($x.$y) + $asciiOffset;
            $cryptString .= chr($newCharCode);
            break;
        }
    }
}

print($cryptString);
