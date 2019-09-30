def odd_magic_square(n)
  raise ArgumentError "Need odd positive number" if n.even? || n <= 0
  n.times.map{|i| n.times.map{|j| n*((i+j+1+n/2)%n) + ((i+2*j-5)%n) + 1} }
end
 
# Test
[3, 5, 9].each do |n|
  puts "\nSize #{n}, magic sum #{(n*n+1)/2*n}"
  fmt = "%#{(n*n).to_s.size + 1}d" * n
  odd_magic_square(n).each{|row| puts fmt % row}
end
