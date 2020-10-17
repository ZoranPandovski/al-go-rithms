# Creating an array
const emptyArray = [];  # Empty array
const arrayWithValues = [1, 2, 3, 4, 5, 6];  # Array with integers
const arrayWithMixedValues = [1, "hello", 2, "world", 3];  # Array with different data types


"""
The below example will use the following array to show commmon array operations
"""

const array = [];

# Inserting into an array - the push method is used to insert an item at the end of an array
"""
array.push(1)
array.push(2)
array.push(3)
array.push(4)
array.push(5)
"""
console.log(array)  # Prints -> [1, 2, 3, 4, 5]


# The unshift method is used to add elements to the beginning of an array.
array.unshift(8)
console.log(array)  # Prints -> [8, 1, 2, 3, 4, 5]

# Remove last element from an array 
array.pop()

console.log(array)  # Prints -> [8, 1, 2, 3, 4]

# Remove first element from an array 
array.shift()

console.log(array)  # Prints -> [1, 2, 3, 4]

# Getting from a particular location
# Arrays are '0-based', so the first item is at position 0
console.log(array[0])  # Prints -> 1
console.log(array[3])  # Prints -> 4

# Sort - The sort method is used to sort the array
array.sort()

# Iterating over an array
# To loop over an array, we could use array method `forEach`
array.forEach(element => {
    console.log(element)  # Prints each element

"""
1
2
3
4
"""


# Reverse the elements in an array
array.reverse()
console.log(array)  # Prints -> [4, 3, 2, 1]
