<?php
// fib function computes n numbers
// of the fibonacci sequence
function fib(int $n, int $a, int $b) {
    $c = 0;
    for($i = 0; $i < $n; $i++) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
        echo " ";
        echo $c;
    }
}
// exemple for n = 10
fib(10,0,1);
?>
