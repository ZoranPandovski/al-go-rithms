puts "Enter a number: "
number = gets.to_i

aux = number-1
is_divisible = 0

while aux > 1 do
  if number%aux == 0
    is_divisible = 1
    break
  end
  aux -= 1
end

if  is_divisible == 0 or number == 2
  puts "The number " + number.to_s + " is prime\n"
else
  puts "The number " + number.to_s + " is not prime\n"
end
