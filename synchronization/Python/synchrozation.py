import threading
import time
import random

# Haircut start signal
ready = threading.Semaphore(0)
# Haircut end semaphore
finish = threading.Semaphore(0)
# Mutually exclusive semaphore
mutex = threading.Lock()
b = threading.Lock()
# Initial number of haircuts
wait_customer = 0
# Waiting chairs are mutually exclusive
wchair = threading.Lock()
# Barber chairs are mutually exclusive
barber_chair = threading.Lock()
# Number of chairs
# CHAIRS = 6
# serial number
counter = 0
# Waiting queue
wchair_list = []
#
in_cut = 0
served_customer=0

def customer():
    # Customer Process
    global wait_customer, waiting_chair, mutex, wchair, finish, barber_chair, ready, counter, in_cut, served_customer
    time.sleep(4)
    # Enter the critical area, modify the number of people waiting
    mutex.acquire()
    if wait_customer <= waiting_chair:
        wait_customer += 1
        served_customer+=1
        counter += 1
        print("Customer {} is coming".format(counter))
        wchair_list.append("customer"+str(counter))
        print("The current number of customers is:", wait_customer)
        if (waiting_chair>0):
            print("The waiting queue is:", wchair_list)
        mutex.release()
        # Wait for the chair resource to be available
        wchair.acquire()
        # Waiting for haircut
        barber_chair.acquire()
        # You can have a haircut and release the waiting chair resources
        try:
            in_cut = wchair_list.pop(0)
        except:
            pass
        wchair.release()
        print("{} sat in the barber chair".format(in_cut))
        if (waiting_chair>0):
            print("The remaining waiting queue is:", wchair_list)
        # Send a signal to the barber
        ready.release()
        # Waiting for haircut
        finish.acquire()
        # Release barber chair resources
        print("The {} left the barber chair and walked out of the store happily! ".format(in_cut))
        barber_chair.release()
        # Modify the number of customers
        mutex.acquire()
        wait_customer -= 1
        mutex.release()
    else:
        counter += 1
        print("Customer {} is coming".format(counter))
        balk(counter)

def balk(counter):
    global waiting_chair
    if (waiting_chair>0):
        print("The waiting number is full, there are no seats, the customer {} leaves".format(counter))
    elif (waiting_chair==0):
        print("There are no waiting seats, the customer {} leaves".format(counter))
    else:
        print("There is no barber chair, the customer {} leaves".format(counter))
    mutex.release()


def barber():
    # Barber process
    print("The barber shop is open! ")
    print("--------------------------")
    global wait_customer, waiting_chair, mutex, ready, finish
    while True:
        if wait_customer == 0:
            print("No customers, sleep! ")
            time.sleep(1)
        # Waiting for the customer to make a request
        ready.acquire()
        cut_hair()
        # Haircut finished
        finish.release()


def cut_hair():
    print("The customer is getting a haircut! ")
    time.sleep(6)
    print("The haircut is over! ")


if __name__ == "__main__":
    total_chairs = int(input("Please enter the number of chairs in the barber shop:"))
    waiting_chair = total_chairs-1
    total_customers = int(input("Please enter the number of customers that will come in the barber shop:"))
    t1 = threading.Thread(target=barber)
    t1.start()
    t1.join(1)
    
    while True:
        try:
            b.acquire()
            if ( total_customers > 0):
                time.sleep(random.randint(1,2))
                t2 = threading.Thread(target=customer)
                t2.start()
                t2.join(1)
                total_customers -= 1
                b.release()

            elif (total_customers <= 0 and finish._value==0):
                b.release()
                time.sleep(15)
                if (served_customer>0):
                     print("Aaah, all done, served {} customers, going to sleep".format(served_customer))
                else:
                    print("no customers for today, barber is still asleep")
                break
        except:
            print("error! ")
            break