def pan(st):
    uniqueChar = list()
    for i in st:
        if(i.lower() not in uniqueChar and i.lower().isalpha()):
            uniqueChar.append(i)

    if(len(uniqueChar) == 26):
        return True
    else:
        return False

string = input("Enter a string for checking ")
print(pan(string))