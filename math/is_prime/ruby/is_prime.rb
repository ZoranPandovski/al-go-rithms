puts "Enter a number: "
number = gets.to_i

aux = number-1 	# numbers between "number" and "one", for test your divisibility
is_divisible = 0

while aux > 1 do
  if number%aux == 0	# zero indicates with number is divisible for other, than himself or one
    is_divisible = 1	
    break
  end
  aux -= 1
end

if  is_divisible == 0
  puts "The number " + number.to_s + " is prime\n"
else
  puts "The number " + number.to_s + " is not prime\n"
end
