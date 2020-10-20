<?php
/**
 * This code requires PHP7.2 with pthreads installed.
 * You can use the Docker image: programster/ubuntu16.04-pthreads-7.2 to run it.
 *
 * There is no mechanism is place to take care of race conditions! Unexpected behaviour is expected!
 */

const LOOP_SIZE   = 10; //Number of tries before finishing
const BUFFER_SIZE = 5; //Max size of the buffer

class Operations extends Threaded
{

    private $queue;

    public function __construct(array $elements)
    {
        $this->queue = $elements;
    }

    /**
     * The name of this function is myPush because the Threaded class already defines a pop function that we don't
     * want to override. So we are using myPush and myPop to keep the naming consistency.
     */
    public function myPush($element): self
    {
        if (count($this->queue) > BUFFER_SIZE) {
            printf("The buffer is full, rejecting: %d \n", $element);

            return $this;
        }

        printf("Pushed: %d \n", $element);
        $this->queue[] = $element;

        return $this;
    }

    public function myPop()
    {
        $pop = $this->queue->pop();
        printf("Poped: %d \n", $pop);

        return $pop;
    }

    public function isEmpty(): bool
    {
        return count($this->queue) === 0;
    }

    public function dump(): void
    {
        var_dump($this->queue);
    }
}

class Producer extends Thread
{

    private $operations;

    public function __construct(Operations $operations)
    {
        $this->operations = $operations;
    }

    public function run()
    {

        $x = 0;
        while ($x < LOOP_SIZE) {
            echo 'Producer run' . PHP_EOL;
            $this->operations->myPush(rand(0, 100));
            sleep(rand(0, 5));
            $x++;
        }
    }
}

class Consumer extends Thread
{
    private $operations;

    public function __construct(Operations $operations)
    {
        $this->operations = $operations;
    }

    public function run()
    {
        $x = 0;
        while ($x < LOOP_SIZE) {
            echo 'Consumer run' . PHP_EOL;

            if ($this->operations->isEmpty()) {
                echo ' -the queue is empty- ' . PHP_EOL;
            } else {
                $this->operations->myPop();
            }

            sleep(rand(0, 5));
            $x++;
        }
    }
}

$operations = new Operations([]); //This object will hold the items that we are being produced/consumed
$producer   = new Producer($operations); //We instantiate a producer that will use the operations to produce
$consumer   = new Consumer($operations); //We instantiate a consumer that will use the operations to consume

#here we are starting our threads, so we can produce and consume async
$producer->start();
$consumer->start();

#here we need to wait for it to end
$producer->join();
$consumer->join();

#before we print out what is left in our queue
$operations->dump();

/*********************
****Output sample:****
**********************
[docker://programster/ubuntu16.04-pthreads-7.2/]:php /opt/project/tmp/producer_consumer.php
Producer run
Pushed: 89
Consumer run
Poped: 89
Consumer run
-the queue is empty-
Consumer run
-the queue is empty-
Producer run
Pushed: 24
Consumer run
Poped: 24
Consumer run
-the queue is empty-
Producer run
Pushed: 10
Consumer run
Poped: 10
Producer run
Pushed: 100
Consumer run
Poped: 100
Producer run
Pushed: 55
Consumer run
Poped: 55
Producer run
Pushed: 50
Producer run
Pushed: 61
Consumer run
Poped: 61
Consumer run
Poped: 50
Producer run
Pushed: 61
Producer run
Pushed: 4
Producer run
Pushed: 93
object(Volatile)#2 (3) {
[7]=>
int(61)
[8]=>
int(4)
[9]=>
int(93)
}

Process finished with exit code 0
*/
