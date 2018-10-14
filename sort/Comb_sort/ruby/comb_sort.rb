# Extend Array class
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

p [3, 21, 75, 47, 93, 30, 3, 9, 1, 51, 12, 14, 12, 57, 78].combsort!
