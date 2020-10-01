# Calculator factorial
def factorial(n)
  (1..n).inject :*
end
######################

puts "Enter a number: "
number = gets

index = number.length - 2
result = 0
while index >= 0 do
  result += factorial(number[index].to_i)
  index -= 1
end

if  result == number.to_i
  puts "The number " + number + " is a strong number\n"
else
  puts "The number " + number + " is not a strong number\n"
end
