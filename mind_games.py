import random

number = random.randint(1, 100)
print("I'm thinking of a number between 1 and 100. Guess what it is!")

guess = None
while guess != number:
    try:
        guess = int(input())
    except ValueError:
        print("Please enter a valid integer!")
        continue

    if guess < number:
        print("Too low! Guess again.")
    elif guess > number:
        print("Too high! Guess again.")
    else:
        print("Correct! You win!")
