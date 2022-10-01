HEXA = 16
OCTA = 8
BINA = 2

puts "Enter a decimal number: "
number = gets.to_i
##*Gets* will take input from console and it will always be string.
##*To_i* will convert the string into integer.

print(number.to_s(BINA)," in binary.\n")
print(number.to_s(OCTA)," in octal.\n")
print(number.to_s(HEXA), " in hexadecimal.\n")
