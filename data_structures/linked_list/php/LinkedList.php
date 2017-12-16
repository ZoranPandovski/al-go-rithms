<?php

class LinkedList
{
    /**
     * @var Node
     */
    public $head;

    /**
     * @param mixed $afterElement
     * @param mixed $newElement
     */
    public function insertAfter($afterElement, $newElement)
    {
        $node = $this->find($afterElement);
        $newNode = new Node($newElement);
        $newNode->next = $node->next;
        $newNode->previous = $node;
        $node->next = $newNode;
    }

    /**
     * @param mixed $beforeElement
     * @param mixed $newElement
     */
    public function insertBefore($beforeElement, $newElement)
    {
        $node = $this->find($beforeElement);
        $newNode = new Node($newElement);

        if (!$node->previous) {
            $this->head = $newNode;
        } else {
            $previousNode = $node->previous;
            $previousNode->next = $newNode;
            $newNode->previous = $previousNode;
        }

        $node->previous = $newNode;
        $newNode->next = $node;
    }

    /**
     * @param mixed $element
     */
    public function remove($element)
    {
        $node = $this->find($element);

        if ($node->previous) {
            $node->previous->next = $node->next;
        }

        if ($node->next) {
            $node->next->previous = $node->previous;
        }
    }

    /**
     * @param $element
     * @return Node|null
     * @throws \Exception
     */
    public function find($element)
    {
        $currentNode = $this->head;

        while ($currentNode) {
            if ($currentNode->element === $element) {
                return $currentNode;
            }

            $currentNode = $currentNode->next;

            if ($currentNode === $this->head) {
                break;
            }
        };

        throw new \Exception('Cannot find element.');
    }

    /**
     * @return array
     */
    public function toArray()
    {
        $array = [];

        $currentNode = $this->head;

        while ($currentNode) {
            $array[] = $currentNode->element;
            $currentNode = $currentNode->next;

            if ($currentNode === $this->head) {
                break;
            }
        };

        return $array;
    }
}
