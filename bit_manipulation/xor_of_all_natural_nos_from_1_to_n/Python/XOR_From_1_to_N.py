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