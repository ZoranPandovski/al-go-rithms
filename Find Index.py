haystack = "sadbutsad"
needle = "sad"

# Create a list of indices where the needle matches the haystack
indices = [i for i, _ in enumerate(haystack) if haystack[i:i+len(needle)] == needle]

if indices:
    print("The index of the first occurrence of the needle is:", indices[0])
else:
    print("The needle was not found in the haystack.")
