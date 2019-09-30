#!/usr/bin/php
<?php
/**
 * A Silly implementation of the polybious cypher
 * Extend table to include upper and lowercase as well as punctuation
 * Support passphrase as key, duplicate letters get skipped, passphrase gets put at beginning of cypher
 * convert each 2 digit decimal to ascii and output string of encoded characters
 * We only care about visible ascii, so offset ascii table by -32. (so ascii A (DEC 65) gets encoded as 32 less than the decimal (DEC 33))
 * 
 * Usage: stuffToDecode | php unpoly.php -p ["Passphrase to use"]
 * TODO support filename as alternate to encoded string
 */

$options = getopt('p::');

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

if (!empty($options['p']))
{
    $uniqueCharacters = [];
    $passphraseCharacters = str_split($options['p']);

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

while ($encryptedString = fgets(STDIN))
{
    $encryptedStringCharacters = str_split($encryptedString);
    $originalString = '';

    foreach ($encryptedStringCharacters as $char)
    {
        if ($char == ' ')
        {
            $originalString .= ' ';
            continue;
        }

        $dec = (ord($char) - $asciiOffset);

        if ($dec < 32 || $dec > 127)
        {
            continue;
        }

        $code = (string)$dec; // convert back to decimal
        
        if (strlen($code) == 1)
        {
            $code = '0'.$code;
        }

        $coords = str_split($code);
        $originalString .= $polyTable[$coords[0]][$coords[1]];
    }

    fwrite(STDOUT, $originalString.PHP_EOL);
}
