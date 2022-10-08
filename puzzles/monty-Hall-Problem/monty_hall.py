import random
from typing import Tuple

SIMULATION_COUNT = 100


def show_goat(choice: int, car: int) -> int:
    prizes = [1,2,3]
    prizes.remove(car)
    if choice == car:
        return random.choice(prizes)
    else:
        prizes.remove(choice)
        return prizes[0]


def simulate() -> Tuple[bool, bool]:
    doors = [1,2,3]
    # put the car in a random door
    car = random.randint(1,3)
    # make a random choice
    choice = random.randint(1,3)
    doors.remove(choice)
    # show a goat
    shown = show_goat(choice, car)
    doors.remove(shown)
    # decide to switch
    switch = random.choice([True, False])
    if switch:
        choice = doors[0]

    return(switch, choice==car)
        

def main():
    switching = 0
    winning = 0
    for i in range(SIMULATION_COUNT):
        switch, win = simulate()
        if switch:
            switching += 1
        if win:
            winning += 1

    print(f"Percentage of switching is {switching}")
    print(f"Percentage of winning is {winning}")

main()