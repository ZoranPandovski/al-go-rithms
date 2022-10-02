ROMAN = [
    (1000, "M"),
    ( 900, "CM"),
    ( 500, "D"),
    ( 400, "CD"),
    ( 100, "C"),
    (  90, "XC"),
    (  50, "L"),
    (  40, "XL"),
    (  10, "X"),
    (   9, "IX"),
    (   5, "V"),
    (   4, "IV"),
    (   1, "I"),
]

def int_to_roman(number):
    result = []
    for (arabic, roman) in ROMAN:
        (factor, number) = divmod(number, arabic)
        result.append(roman * factor)
        if number == 0:
            break
    return "".join(result)

if __name__ == "__main__":
    test_numbers = [1, 10, 550, 4565]
    for num in test_numbers:
        print(int_to_roman(num))
