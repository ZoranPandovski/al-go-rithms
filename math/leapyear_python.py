'''Leap year or not'''
def leapyear(year):
	if (year % 4 == 0) and (year % 100 != 0) or (year % 400==0) :  #checking for leap year
		print(year," is a leap year")   #input is a leap year
	else:
		print(year," is not a leap year")   #input is not a leap year

year=int(input("Enter the year: "))
while year<=999 or year>=10000:           #check whether the year is four digit number or not
    print("Enter a year having four digits.")
    year=int(input("Enter the year: "))

leapyear(year)	