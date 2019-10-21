def count_digits(number)
	cont=0
	while number != 0
		cont+=1
		number /= 10
	end
	return cont
end

soma=0
number = gets.to_i
aux=number
digits = count_digits(number)

loop do
	soma+= (number%10) ** digits
        number/=10;

	break if number == 0
end 

if(soma==aux)
	puts "This is an Armstrong number"
else
	puts "This is not an Armstrong number"
end
