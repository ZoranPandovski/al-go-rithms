# Python implementation of the Polybius algorithm
# The algorithm uses an extended encryption table that allows to use numbers
import re
from typing import OrderedDict

ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"


# Function to build the Polybius checkerboard
def make_table(key):
    try:
        key = str(key)
    except Exception as e:
        print("Invalid input! Cannot convert to string!!!")
        print(e)

    # Build the encryption table using the key
    table = (key + ALPHABET).lower()

    # Remove invalid characters
    table = re.sub(r"[\W]", "", table)

    # Turn the string into an ordered dictionary to remove duplicates
    # then read its keys and make it into a string again
    table = "".join(OrderedDict.fromkeys(table).keys())

    # The extended table (english alphabet + numbers) has 36 characters
    # Recovering the index of a character is as easy as dividing its
    # position by 6 (floor is the row) and getting the rest (column)

    return table


# Encrypting function
def polybius_enc(data, key):

    try:
        data = str(data).lower()
        key = str(key)
    except Exception as e:
        print("Invalid input! Cannot convert to string!!!")
        print(e)

    table = make_table(key)

    encrypted = ""

    for char in data:
        try:
            idx = table.index(char)
            # Find the position of the character in the 6x6 polybius table
            row = int(idx / 6)
            col = idx - (row * 6)
            encrypted += str(row) + str(col)
        except ValueError:
            # The character is not in the checkerboard
            # Just append the character
            encrypted += char

    return encrypted


# Decrypting function
def polybius_dec(data, key):
    try:
        data = str(data).lower()
        key = str(key)
    except Exception as e:
        print("Invalid input! Cannot convert to string!!!")
        print(e)

    table = make_table(key)

    # Initialize decrypted string and index for cyle
    decrypted = ""
    idx = 0

    while idx < len(data):
        # Recognize limit cases
        if idx == len(data) - 1:
            couple = data[idx:]
        else:
            couple = data[idx: idx + 2]

        if couple.isdecimal():
            # If there is a couple of numbers, find row and column
            row = int(data[idx])
            col = int(data[idx + 1])

            # Extract data from the 6x6 polybius table
            decrypted += table[6 * row + col]
            idx += 2
        else:
            decrypted += data[idx]
            idx += 1

    return decrypted


# Testing the code

key = r"this is a key"
data = r"EnCoDe Me: There are some $p3c!4L çh/\r@cters"

encrypted = polybius_enc(data, key)
decrypted = polybius_dec(encrypted, key)

print(f"Data to encrypt:\t'{data}'")
print(f"Encryption string is:\t'{encrypted}'")
print(f"Decrypted data:\t\t'{decrypted}'")
