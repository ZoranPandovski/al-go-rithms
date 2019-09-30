# Extend Array class by adding comb sort
class Array
  def combsort!
    gap = size
    swaps = true
    while gap > 1 || swaps
      gap = [1, (gap / 1.25).to_i].max
      swaps = false
      0.upto(size - gap - 1) do |i|
        if self[i] > self[i + gap]
          self[i], self[i + gap] = self[i + gap], self[i]
          swaps = true
        end
      end
    end
    self
  end
end

# Perform comb sort on a fixed array
[3, 21, 75, 47, 93, 30, 3, 9, 1, 51, 12, 14, 12, 57, 78].combsort!

# Perform comb sort on a randomly generated array
Array.new(10) { rand(-500...500) }.combsort!

# Benchmark comb sort
require 'benchmark'
puts Benchmark.measure {
  100_000.times do
    Array.new(10) { rand(-500...500) }.combsort!
  end
}
