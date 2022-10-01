#checking if number entered is divisible by any of the prime numbers less than 10, ie. 2, 3, 5,7

num = int(input("Enter number : "))

remainder_2 = num%2
remainder_3 = num%3
remainder_5 = num%5
remainder_7 = num%7

if remainder_2 == 0 :
	print("Divisible by 2")

if remainder_3 == 0 :
	print("Divisible by 3")

if remainder_5 == 0 :
	print("Divisible by 5")

if remainder_7 == 0 :
	print("Divisible by 7")
