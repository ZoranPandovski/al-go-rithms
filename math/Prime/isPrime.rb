# using trial division with 6k+-1 optimizaion
def prime?(number)
  return false if number == 1
  return true if [2, 3].include?(number)
  return false if (number % 2).zero? || (number % 3).zero?

  # we begin at 5 due to using using 6k+-1 optimizaion
  i = 5
  while i**2 <= number
    return false if (number % i).zero? || (number % (i + 2)).zero?

    i += 6
  end

  true
end

puts "5 is prime? #{prime?(5)}"
puts "6 is prime? #{prime?(6)}"
