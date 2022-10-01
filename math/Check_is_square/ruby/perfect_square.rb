def is_perfect_square (num = 0)

  rest = Math.sqrt(num) % 1 
	return rest == 0
end


print("Enter a number: ")
num = gets.chomp.to_i

if is_perfect_square (num)
  print("Is perfect square")
else 
  print("Isn't perfect square")
end
