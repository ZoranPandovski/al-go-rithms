#We check if a string is palindrome or not

#Accept a string input
inputString = input("Enter any string:")

#Caseless Comparison
inputString = inputString.casefold()

#check if the string is equal to its reverse
if list(inputString) == list(reversed(inputString)):
   print("Congrats! You typed in a PALINDROME!!")
else:
   print("This is not a palindrome. Try Again.")
