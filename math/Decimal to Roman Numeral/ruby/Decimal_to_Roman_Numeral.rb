# Fill the string result with the roman number
def fill( c = 0, n = 1 )
  roman = ''
  while n>0
    roman = roman + c
	n = n - 1
  end
  return roman
end

# Select roman numeral to filled
def decimal_to_roman( number = 0 )
  if number < 0
    return '-1'
  end
    
  if (number < 4)
    return  fill('I', number)
  elsif (number < 6)
    return fill('I', 5 - number) + 'V'
  elsif (number < 9)
    return 'V' + fill('I', number - 5 )
  elsif (number < 11)
    return fill('I', 10 - number ) + 'X'
  elsif (number < 40)
    return fill('X', number / 10 ) + decimal_to_roman( number%10 )
  elsif (number < 60)
    return fill('X', number - 5 ) + 'L' + decimal_to_roman( number%10 )
  elsif (number < 90)
    return 'L' + fill('X', (number/10) - 5 ) + decimal_to_roman( number%10 )
  elsif (number < 110)
    return fill('X', 10 - (number / 10) ) + 'C' + decimal_to_roman( number%10 )
  elsif (number < 400)
    return fill('C', number / 100 ) + decimal_to_roman( number%100 )
  elsif (number < 600)
    return fill('C', 5 - (number / 100) ) + 'D' + decimal_to_roman( number%100 )
  elsif (number < 900)
    return 'D' + fill('C', (number / 100) - 5 ) + decimal_to_roman( number%100 )
  elsif (number < 1100)
    return fill('C', 10 - (number / 100) ) + 'M' + decimal_to_roman( number%1000 )
  else
    return 'M' + decimal_to_roman( number - 1000 )
  end
  
end

# Take a number to convert in roman numeral
print("Enter a decimal to convert:")
number = gets.chomp.to_i
result = decimal_to_roman(number)

if result=='-1'
  puts "Sorry, Invalid Number! Negative number informed."
else
  print("The Decimal " + number.to_s + " is "+ result.to_s + " in Roman\n")
end
