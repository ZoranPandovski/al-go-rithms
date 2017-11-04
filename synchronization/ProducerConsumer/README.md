## Producer Consumer Problem

The Producer-Consumer Problem is a classic synchronization problem, where a bunch of producers produce some value and store it in a shared buffer. When the buffer is full, the producer has to wait for a consumer to consume before placing an item in the buffer. Another bunch of consumers consume from the buffer until its empty. Once the buffer is empty, they wait for the producer to produce an item and put it in the buffer.

Read more about the problem [here](https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem)
