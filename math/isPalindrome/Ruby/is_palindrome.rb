def is_palidrome (name = 0)
  name = name.tr('^A-Za-z0-9', '') # only letters and numbers
  aux = name
  j = aux.length-1
	for i in 0..(name.length-1)
		if name[i]!=aux[j]
      return false
    end
    j=j-1
	end
	return true

end

print("Enter anything: ")
name = gets.chomp
if is_palidrome(name) 
  print("It's a palindrome")
else
  print("Nah!")
end
