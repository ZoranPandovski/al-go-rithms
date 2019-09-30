<?php

class Queue {
    protected $limit = 0;
    private $queue = NULL;

    public function __construct($limit){
        $this->limit = $limit;
        $this->queue = array();
    }

    public function is_empty(){
        return $this->get_size() == 0;
    }

    public function is_full(){
        return $this->get_size() >= $this->limit;
    }

    public function enqueue($item){
        if ($this->is_full()){
            throw new Exception("Queue is already full");
        }
        array_push($this->queue, $item);
    }

    public function dequeue(){
        if ($this->is_empty()){
            throw new Exception("Queue is empty");
        }
        return array_shift($this->queue);

    }

    public function get_size(){
        return count($this->queue);
    }
}