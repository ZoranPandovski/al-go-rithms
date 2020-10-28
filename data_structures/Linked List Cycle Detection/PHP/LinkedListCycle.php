<?php
/**
 * Floyd's hare and tortoise algorithm to cycle detection
 * 
 * @see https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare
 *
 * @param int[] $nums An array with numbers starting (min. value 1)
 * @param bool  $debug A flag used to print the intermediate results
 *
 * @return bool Is there a cycle or not?
 */
function findCycle(array $nums, bool $debug = false):bool {
    $fast = $slow = $nums[0];
    $iteration = 0;

    if ($debug){
        printf(
            "slow = %d fast = %d iteration = %d \n",
            $slow,
            $fast,
            $iteration++
        );
    }
    
    while(
        array_key_exists($slow, $nums) 
        && array_key_exists($fast, $nums) 
        && array_key_exists($nums[$fast], $nums)
    ){
        $slow = $nums[$slow];
        $fast = $nums[$nums[$fast]];

        if ($debug){
            printf(
                "slow = %d fast = %d iteration = %d \n",
                $slow,
                $fast,
                $iteration++
            );
        }

        if ($slow === $fast) {
            return true;
        }

    }

    return false;
}

/**
 * This function will call our findCycle function and will output nicely the results and check if the results are
 * matching the expectations and return a string with the results of the tests
 * 
 * @param int[] $values
 * @param bool  $expected
 * @param bool  $debug
 * @return string  
 */
function test(array $values, bool $expected, bool $debug = false) {
    static $passedTests = 0;
    static $totalTests = 0;
    
    $totalTests++;
    
    $result = findCycle($values, $debug);
    
    if ($result === $expected) {
        $passedTests++;
    }
    
    printf(
        "input: [%s] expected: %s got: %s -> [%s]\n",
        implode(', ', $values),
        $expected ? 'true' : 'false',
        $result ? 'true' : 'false',
        $expected === $result ? 'OK' : 'NOT OK'
    );
    
    return sprintf("(%d/%d tests passed)\n", $passedTests, $totalTests);
}

test([1,1], true);
test([1,2,3], false);
test([1,2,2], true);
test([2,2,2], true);
test([2,1,3], false);
test([1,1,3], true);
$total = test([1,3,4,2,2], true);
echo $total;
