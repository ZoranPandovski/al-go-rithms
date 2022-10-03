def get_water(arr: list[int]) -> int:
    size = len(arr)
    res: int = 0
    lmax: list[int] = arr[:]
    rmax: list[int] = arr[:]
    for i in range(1, size, 1):
        lmax[i] = max(arr[i], lmax[i-1])
    for i in range(size-2, -1, -1):
        rmax[i] = max(arr[i], rmax[i+1])
    for i in range(size):
        res += (min(lmax[i], rmax[i]) - arr[i])

    print(f"The maximum amount of water that can be trapped is {res}")

def main() -> None:
    size = int(input("Enter the size of the bars: "))

    arr: list[int] = []
    print("Enter values for the bars:")
    for i in range(size):
        arr.append(int(input()))

    get_water(arr)

main()
