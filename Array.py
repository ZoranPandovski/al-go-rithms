# Initialize an array with 5 elements
my_array = [10, 20, 30, 40, 50]

# Access array elements
print(my_array[0])   # Output: 10
print(my_array[3])   # Output: 40

# Search for an element
element_to_search = 30
if element_to_search in my_array:
    print(f"Element {element_to_search} found at index {my_array.index(element_to_search)}")
else:
    print(f"Element {element_to_search} not found")

# Sort the array
sorted_array = sorted(my_array)
print(sorted_array)  # Output: [10, 20, 30, 40, 50]

# Insert an element
my_array.append(60)
print(my_array)      # Output: [10, 20, 30, 40, 50, 60]

# Delete an element
del my_array[2]
print(my_array)      # Output: [10, 20, 40, 50, 60]

# Resize the array
my_array = [1, 2, 3, 4, 5]
my_array = my_array[:3]    # Resize array to first 3 elements
print(my_array)            # Output: [1, 2, 3]
