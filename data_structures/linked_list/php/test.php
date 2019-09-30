<?php

require_once 'Node.php';
require_once 'LinkedList.php';

function testList(array $expected, LinkedList $list)
{
    $array = $list->toArray();

    if ($expected != $array) {
        echo sprintf(
            'Invalid list. Expected: %s, got: %s',
            print_r($expected, true),
            print_r($array, true)
        );
    }
}

$list = new LinkedList();

testList([], $list);

$head = new Node(12);
$list->head = $head;
testList([12], $list);

$list->insertAfter(12, 99);
testList([12, 99], $list);

$list->insertAfter(99, 37);
testList([12, 99, 37], $list);

$list->insertAfter(12, 56);
testList([12, 56, 99, 37], $list);

$list->insertBefore(56, 100);
testList([12, 100, 56, 99, 37], $list);

$list->insertBefore(12, 1);
testList([1, 12, 100, 56, 99, 37], $list);

$list->remove(12);
testList([1, 100, 56, 99, 37], $list);
