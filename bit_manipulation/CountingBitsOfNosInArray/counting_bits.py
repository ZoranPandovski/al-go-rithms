def count_bits(num: int) -> None:
    arr: list[int] = [0] * (num+1)
    if (num == 0):
        print(arr)

    arr[1] = 1
    for i in range(1, num+1):
        if((i&1) == 1):
            arr[i] = 1 + arr[i-1]
        elif ((i&(i-1)) == 0):
            arr[i] = 1
        else:
            arr[i] = arr[int(i/2)]

    print(arr)


def main() -> None:
    count_bits(int(input("Enter the number : ")))


main()