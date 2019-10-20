## Factorial function ###
class Integer
  def !
    (1..self).inject(:*)
  end
end
#########################

# Function to calculate the sum of factorials
def is_stronger (num = 0)
  strong_number = num
	sum = 0
	while (num != 0)
		digit = num % 10	# To extract the last digit of the number
		num /= 10		# Drop the last digit of the number 
		sum += !digit		# Add the digit to the total sum
	end
	return strong_number==sum
end

# Take a number from the user as input and output the sum of the digits of the number
print("Enter a number: ")
num = gets.chomp.to_i

if is_stronger (num)
  print("This is a strong number")
else 
  print("Isn't a strong number ")
end
