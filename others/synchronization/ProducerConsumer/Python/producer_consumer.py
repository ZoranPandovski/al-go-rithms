from __future__ import print_function
from threading import Thread, Lock, Condition
import random
import time

Q = []
lock = Lock()           #to avoid race condition
condition = Condition()     #Condition provides acquire() and release() which calls lock acquire() and release() internally,
                            #and so we can replace lock instances with condition instances.

BUF_SIZE = 10

class Producer(Thread):
    def run(self):
        array = range(5)
        global queue
        while True:
            condition.acquire()

            if len(Q) == BUF_SIZE:
                print("Q full : producer waiting")
                condition.wait()
                print("Space available, consumer notified the producer")

            item = random.choice(array)
            #lock.acquire()
            Q.append(item)
            print("produced", item)
            condition.notify()
            condition.release()
            #lock.release()
            time.sleep(random.random())

class Consumer(Thread):
    def run(self):
        global queue
        while True:
            condition.acquire()
            #lock.acquire()
            if not Q:
                print("Q empty : consumer is waiting!")
                condition.wait()
                print("producer added some item and notified the consumer")

            item = Q.pop(0)
            print("consumed", item)
            condition.release()
            #lock.release()
            time.sleep(random.random())

Producer().start()
Consumer().start()
