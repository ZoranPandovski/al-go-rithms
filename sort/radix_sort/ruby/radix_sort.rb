# Extend Array class by adding radix sort
class Array
  def radix_sort(base = 10)
    ary = dup
    m, max = 1, ary.minmax.map(&:abs).max
    while m <= max
      buckets = Array.new(base){[]}
      ary.each {|n| buckets[(n.abs / m) % base] << n}
      ary = buckets.flatten
      m *= base
    end
    ary.partition{|n| n<0}.inject{|minus,plus| minus.reverse + plus}
  end
end

# Perform radix sort on a fixed array
p [210, 52, 30, -100, 3, 21, -750, 18, -12].radix_sort

# Perform radix sort on a randomly generated array
p Array.new(10) { rand(-500...500) }.radix_sort

# Benchmark radix sort
require 'benchmark'
puts Benchmark.measure {
  100_000.times do
    Array.new(10) { rand(-500...500) }.radix_sort
  end
}
