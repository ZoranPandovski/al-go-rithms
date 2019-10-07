def converte(number)
	if(number==0)
		return
	end
	converte(number/2)
	print number%2
end



number = gets.chomp.to_i
printf("The number %d in binary is:", number) 
puts converte(number)

