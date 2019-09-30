def fact(n)
	return 1 if n <= 1 else n * fact(n-1)
end

puts "Enter a number: "
number = gets.to_i
number = fact(number)
puts "Result: " + number.to_s + " "
