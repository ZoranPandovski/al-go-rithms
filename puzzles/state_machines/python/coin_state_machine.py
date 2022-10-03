"""
  Imagine a machine that gives you a quarter once you put in 25 cents. I suppose if you really like
  gumballs that is in someway useful. The machine will wait until it has reached a state of 25 cents, 
  then it will spit out a quarter. The machine is totally oblivious to what coins were added to reach
  its current state, all it knows is the state it is in, which is how it achieves the "no memory" standard.
  (at least conceptually)
 """
from enum import Enum

class coins(Enum):
    penny = 1
    nickel = 5
    dime = 10
    quarter = 25


def main():
    state = 0

    while state <= 25:

        print(f"Balance: {state}")
        coin = input("Please insert a coin(penny, nickel, dime, quarter): ")
        try:
            state+=coins[coin].value
        except:
            print("That's not a coin")
            continue

    print("Thanks, here's your quarter")

main()
