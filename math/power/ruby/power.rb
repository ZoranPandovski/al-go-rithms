def power (number = 0, n = 1)
  if number < 0 || n <0
    return -1
  end
  
  if n == 0
    return 1
  elsif ((n%2)==0)
    return power(number*number, n/2)
  else
    return number*power(number*number, n/2)
  end

end

# Take a number and the exponent value from the user as input and output the the result of expression (number^n)
print("Enter a positive integer value (base):")
number = gets.chomp.to_i
print("Now, enter a positive integer value (exponent):")
n = gets.chomp.to_i

result = power(number, n)
if(result==-1)
  puts "Sorry, Invalid Number! Negative number informed."
else
  print("The result of " + number.to_s + "^" + n.to_s + " is "+ result.to_s + "\n")
end
