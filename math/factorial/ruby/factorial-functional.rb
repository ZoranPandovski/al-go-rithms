def fact(n)
  (1..n).inject :*
end

puts "Enter number: "
n = gets.to_i
puts "#{n}! = #{fact(n)}"
