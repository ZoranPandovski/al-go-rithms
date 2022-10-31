import math

def checkPalindrome( number ):
    for i in range(math.floor(len(str(number))/2)):
        if( number[i] != number[len(str(number))-i-1]):
            return False
    return True

def printResult( isPalindrome ):
    if( isPalindrome == True ):
        print( "Your number is Palindrome !" )
    else:
        print( "Your number is not a Palindrome. " )


number = input("Please give a number : ")
printResult(checkPalindrome(number))