<?php

function balancedParentheses(string $input): bool
{
    $stacks = [
        new SplStack(),
        new SplStack(),
        new SplStack(),
    ];

    $length = strlen($input);

    for ($i = 0; $i < $length; $i++) {
        $char = $input[$i];
        switch ($char) {
            case '[':
                $stacks[0]->push($char);
                break;
            case '(':
                $stacks[1]->push($char);
                break;
            case '{':
                $stacks[2]->push($char);
                break;
            case ']':
                if ($stacks[0]->isEmpty()) { #when this happens it means that we have a closing parathenses before an opening one
                    return false;
                }
                $stacks[0]->pop();
                break;
            case ')':
                if ($stacks[1]->isEmpty()) {
                    return false;
                }
                $stacks[1]->pop();
                break;
            case '}':
                if ($stacks[2]->isEmpty()) {
                    return false;
                }
                $stacks[2]->pop();
                break;
        }
    }

    return $stacks[0]->isEmpty() && $stacks[1]->isEmpty() && $stacks[2]->isEmpty();
}

function test(string $input, bool $expectedOutput): string
{
    static $tests = 0;
    static $successfullTests = 0;

    $result  = balancedParentheses($input);
    $success = $result === $expectedOutput;

    printf(
        "The input string: %s is %s. The expected result is %s. [%s] \n",
        $input,
        $result ? 'balanced' : 'not balanced',
        $expectedOutput ? 'balanced' : 'not balanced',
        $success ? 'OK' : 'Not OK'
    );

    $tests++;

    if ($success) {
        $successfullTests++;
    }

    return sprintf("Total tests: %d Successfull Tests: %d", $tests, $successfullTests);
}

test('({}[](([{()}])))', true);
test('()', true);
test('{}', true);
test('[]', true);
test('[]]', false);
test('[]}', false);
test('[]{', false);
test('([{])', false);
test('([sdfazxc()dsfad_{}])', true);
$totalTests = test('()', true);

echo $totalTests;
/*** OUTPUT:
The input string: ({}[](([{()}]))) is balanced. The expected result is balanced. [OK] 
The input string: () is balanced. The expected result is balanced. [OK] 
The input string: {} is balanced. The expected result is balanced. [OK] 
The input string: [] is balanced. The expected result is balanced. [OK] 
The input string: []] is not balanced. The expected result is not balanced. [OK] 
The input string: []} is not balanced. The expected result is not balanced. [OK] 
The input string: []{ is not balanced. The expected result is not balanced. [OK] 
The input string: ([{]) is not balanced. The expected result is not balanced. [OK] 
The input string: ([sdfazxc()dsfad_{}]) is balanced. The expected result is balanced. [OK] 
The input string: () is balanced. The expected result is balanced. [OK] 
Total tests: 10 Successfull Tests: 10
 */
