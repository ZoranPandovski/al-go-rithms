<?php
/***
 * This function removes empty spaces ' ' and converts the strings to lowercase.
 */
function isAnagram(string $stringA, string $stringB): bool {
    [$stringA, $stringB] = str_replace(' ', '', [$stringA, $stringB]);

    $stringA = strtolower($stringA);
    $stringB = strtolower($stringB);

    $stringA = str_split($stringA);
    $stringB = str_split($stringB);

    sort($stringA);
    sort($stringB);

    return $stringA === $stringB;

}

function test(string $stringA, string $stringB, bool $expectedOutput): string
{
    static $tests = 0;
    static $successfullTests = 0;

    $result  = isAnagram($stringA, $stringB);
    $success = $result === $expectedOutput;

    printf(
        "The strings: '%s' and  '%s' are %s an anagram. [%s] \n",
        $stringA,
        $stringB,
        $result ? '' : 'not',
        $success ? 'OK' : 'Not OK'
    );

    $tests++;

    if ($success) {
        $successfullTests++;
    }

    return sprintf("Total tests: %d Successfull Tests: %d", $tests, $successfullTests);
}

test('chair', 'archi', true);
test('Elbow', 'Below', true);
test('More', 'Moore', false);
test('Johnathan', 'Jonathan', false);
test('Dormitory', 'Dirty Room', true);
$totalTests = test('Conversation', 'Voices rant on', true);

echo $totalTests;
/*** OUTPUT:
The strings: 'chair' and  'archi' are  an anagram. [OK] 
The strings: 'Elbow' and  'Below' are  an anagram. [OK] 
The strings: 'More' and  'Moore' are not an anagram. [OK] 
The strings: 'Johnathan' and  'Jonathan' are not an anagram. [OK] 
The strings: 'Dormitory' and  'Dirty Room' are  an anagram. [OK] 
The strings: 'Conversation' and  'Voices rant on' are  an anagram. [OK] 
Total tests: 6 Successfull Tests: 6
 */
