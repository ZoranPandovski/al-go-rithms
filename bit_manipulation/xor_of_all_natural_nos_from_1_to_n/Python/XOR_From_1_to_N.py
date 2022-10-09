def XOR_from_1_to_N(n: int) -> None:
    if n%4==0:
        ans=n
    elif n%4==1:
        ans=1
    elif n%4==2:
        ans=n+1
    else:
        ans=0
    print(ans)

def main() -> None:
    XOR_from_1_to_N(int(input()))

main()

# Time Complexity: O(1)
# Space Complexity: O(1)

"""
    Description:
    *When we do XOR of numbers, we get 0 as the XOR value just before a multiple of 4. 
    *This keeps repeating before every multiple of 4. (XOR of numbers upto 4k+3 is 0)
    *Using this fact, we can find the XOR of numbers of the form 4k,4k+1 and 4k+2.
"""