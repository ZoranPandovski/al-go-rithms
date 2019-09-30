function isPrime(number)
  --Check if the number is prime
  for i=2,number-1 do
    if number%i == 0 then
      --If remainder number/1 eguals to 0 return not prime
      return "Not prime"
    end
  end
  return "is prime"
end
--call function and print result
print(isPrime(10))