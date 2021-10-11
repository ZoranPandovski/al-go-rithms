'''
Imagine a machine that gives you a quarter once you put in 25 cents. I suppose if you really like
gumballs that is in someway useful. The machine will wait until it has reached a state of 25 cents,
then it will spit out a quarter. The machine is totally oblivious to what coins were added to reach
its current state, all it knows is the state it is in, which is how it achieves the "no memory" standard.
(at least conceptually)
'''
from __future__ import print_function


def change_state(state):
    while state != 25:
        print("Balance: {}".format(state))
        print("Please insert a coin (penny, nickel, dime, quarter)")

        coin = input()
        if coin == "penny":
            state += 1
        elif coin == "nickel":
            state += 5
        elif coin == "dime":
            state += 10
        elif coin == "quarter":
            state += 25
        else:
            print("Sorry that's not a coin")

    print("Thanks, here's your quarter")
    return state


if __name__ == '__main__':
    state = 0
    change_state(state)
