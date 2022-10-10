def Equal_Sum_and_XOR(n: int) ->None:
    count=0
    while n>0:
        if n%2==0:
            count+=1
        n/=2
    ans=1<<count
    print(ans)

def main() -> None:
    Equal_Sum_and_XOR(int(input()))

main()

# Time complexity O(lg(n))
# Space Complexity O(1)

"""
Description:
    * Using the identity n+x = n^x + 2*(n&x), we see that n+x = n^x holds iff n&x=0.
    * Hence, in order to obtain n&x=0, for every set bit of n, the corresponding bit of x should be unset.
    * For every unset bit of n, the bit of x has 2 possibilities, 1 or 0.
    * Hence the required ans is math.pow(2,no of unset bits)*math.pow(1,no of set bits) = pow(2,no of unset bits)
    * Also for faster implementation, we use 1<<k instead of math.pow(2,k)
"""