def Highest_Power_of_2(n: int) -> None:
    return n&(~(n-1))

def main() ->None:
    n=int(input())
    ans=Highest_Power_of_2(n)
    print(ans)

main()

#  Time complexity: O(1)
#  Space complexity: O(1)

"""
    Description:
    *This program calculates the highest power of 2 less than the given n.
    *The idea is to subtract calculate n&(~(n-1)) which would make all bits of the number 0 except the leading 1.
    *Thus the number is reduced to the greatest power of 2 less than it.
"""