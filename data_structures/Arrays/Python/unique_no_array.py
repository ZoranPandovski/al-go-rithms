numbers = [20, 20, 30, 30, 40]
unique = []
for number in numbers:
        if number not in unique:
            unique.append(number)
print(unique)