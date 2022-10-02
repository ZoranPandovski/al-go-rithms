def moore_voting(arr: list[int]) -> int:
    majority = arr[0]
    count = 0

    # first phase
    # find candidate for majority
    for i in arr:
        if i == majority:
            count+=1
        else:
            count-=1
        if count == 0:
            majority = i
            count = 1

    # second phase
    # check if majority is more than half of the elements
    count = arr.count(majority)
    if count < len(arr)/2:
        majority = None

    print(f'The majority element is {majority}')


def main() -> None:
    size = int(input("Enter the size of the sequence: "))

    arr: list[int] = []
    print("Enter values in the sequence:")
    for i in range(size):
        arr.append(input())

    moore_voting(arr)

main()
