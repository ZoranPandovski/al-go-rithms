def gcd(a, b)
  b == 0 ? a : gcd(b, a.modulo(b))
end
