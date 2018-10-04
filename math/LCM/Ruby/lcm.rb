def gcd(m, n)
  m, n = n, m % n until n.zero?
  m.abs
end
 
def lcm(m, n)
  (m * n).abs / gcd(m, n)
end

print("Enter 2 Numbers: ")
a, b = gets.split.map(&:to_i)
lcm_ab = lcm(a, b)
print("LCM of " + a.to_s + " and " + b.to_s + " is " + lcm_ab.to_s + "\n")
