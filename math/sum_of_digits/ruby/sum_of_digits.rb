# Function to calculate the sum of digits
def sum_of_digits (num = 0)
#########################################################################################################################
	#The Algorithm for finding the sum_of_digits(num) of a given number is as follows:
		# If num = 0 then sum_of_digits(num) = 0
		# Else 
			# extract the last digit of num
			# add the last digit to the total sum 
			# drop the last digit of the number
		# Repeat until num is not equal to 0
#########################################################################################################################
	sum = 0
	while (num != 0)
		digit = num % 10	# To extract the last digit of the number
		num /= 10		# Drop the last digit of the number 
		sum += digit		# Add the digit to the total sum
	end
	return sum
end

# Take a number from the user as input and output the sum of the digits of the number
print("Enter a number: ")
num = gets.chomp.to_i
sum = sum_of_digits(num)
print("The sum of digits of " + num.to_s + " is " + sum.to_s + "\n")
