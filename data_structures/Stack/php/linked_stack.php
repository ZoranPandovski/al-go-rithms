<?php

declare(strict_types=1);

class Node {
    public function __construct(private int $value, private ?Node $next = null){

    }
    public function push(int $value): Node {
        return new Node($value, $this);
    }

    public function print():void{
        echo $this->value . ' ';
        $this->next?->print();
    }

    public function pop():array{
        return [
            $this->value,
            $this->next
        ];
    }
}

$root = new Node(0);
$root->print();
echo PHP_EOL;
$root = $root->push(1);
$root->print();
echo PHP_EOL;
$root = $root->push(2);
$root->print();
echo PHP_EOL;
[$value, $root] = $root->pop();
echo 'popped value: ' . $value . ' ' . PHP_EOL;
$root->print();
echo PHP_EOL;
[$value, $root] = $root->pop();
echo 'popped value: ' . $value . ' ' . PHP_EOL;
$root->print();
echo PHP_EOL;
[$value, $root] = $root->pop();
echo 'popped value: ' . $value . ' ' . PHP_EOL;
$root?->print();

/**
 Produced output:
0
1 0
2 1 0
popped value: 2
1 0
popped value: 1
0
popped value: 0
 */