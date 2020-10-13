<?php

class Node
{
    /**
     * @var Node
     */
    public $previous;

    /**
     * @var Node
     */
    public $next;

    /**
     * @var mixed
     */
    public $element;

    /**
     * Node constructor.
     * @param null $element
     */
    public function __construct($element = null)
    {
        $this->element = $element;
    }
}
