def isPalindrome(num):
    num = str(num)
    if len(num) % 2 == 0:
        return num[:len(num)//2] == num[:len(num)//2-1:-1]
    else:
        return num[:len(num)//2] == num[:len(num)//2:-1]