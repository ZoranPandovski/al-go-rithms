def fibonacci (num = 0)
if num < 0
  puts "Sorry, this number is invalid!"
elsif num == 0
  return 0
elsif num == 1
  return 1
else
  return fibonacci(num-2)+fibonacci(num-1)
end

end

# Take a number from the user as input and output the nth element of fibonacci sequece
print("Tell which element of the fibonacci sequence!")
num = gets.chomp.to_i
number = fibonacci(num)
print("The " + num.to_s + "th element of fibonacci is " + number.to_s + "\n")
