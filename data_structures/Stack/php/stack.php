<?php 

class Stack{
    protected $stack;
    protected $limit;
    
    public function __construct($limit = 5) {
        // initialize the stack
        $this->stack = array();
        // stack can only contain this many items
        $this->limit = $limit;
    }

    public function push($item) {
        if (count($this->stack) < $this->limit) {
            // prepend item to the start of the array
            array_unshift($this->stack, $item);
        } else {
            throw new RunTimeException('Stack is full!'); 
        }
    }

    public function pop() {
        if ($this->isEmpty()) {
            // trap for stack underflow
	      throw new RunTimeException('Stack is empty!');
	  } else {
            // pop item from the start of the array
            return array_shift($this->stack);
        }
    }

    public function top() {
        return current($this->stack);
    }

    public function isEmpty() {
        return empty($this->stack);
    }
}

//Let’s add some items to the stack:
$myTasks = new Stack();

$myTasks->push('task one');
$myTasks->push('task two');
$myTasks->push('task three');
$myTasks->push('task four');
$myTasks->push('task five'); 

//To remove some items from the stack:
echo $myTasks->pop(); 
echo "<br/>";
echo $myTasks->pop(); 
echo "<br/>";

//Let’s see what’s at the top of the stack:
echo $myTasks->top();
echo "<br/>";

// add new item
$myTasks->push('task six');
echo $myTasks->pop(); 




?>