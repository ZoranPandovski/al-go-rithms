# Takes a string and a number representing the base that the string is written in (two arguments), and converts it to base 10. Works for bases less than 10.

# Takes a string and a number representing the base that the string is written in (two arguments), and converts it to base 10. Works up to base 16 (Hexadecimal)

def base_array_to_int(base_array)
  base_array.map! do |item|
    item.downcase!
    if item.match(/\d/) 
      item.to_i 
    elsif item.match(/[a-fA-F]/)
      "abcdef".index(item) + 10
    end
  end
  base_array
end

def convert_to_decimal(base_string, base)
  base_array = base_string.split("").reverse
  highest_power = base_array.length
  i=0
  decimal = 0
  base_array_integers = base_array_to_int(base_array)
  while i < highest_power
    multiplier = base_array_integers[i]
    decimal += (base**i) * multiplier
    i+=1
  end
  decimal  
end

# Can test using the Ruby method .to_i(base)

# Decimal result is 4095
puts convert_to_decimal("FFF", 16) == "FFF".to_i(16) # true

 # Decimal result is 25765
puts convert_to_decimal("12AB1", 12) == "12AB1".to_i(12) # true

# Decimal result is 9
puts convert_to_decimal("1001", 2) == "1001".to_i(2) # true