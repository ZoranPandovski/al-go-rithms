
def swap(array, i1, i2)
  tmp = array[i1]
  array[i1] = array[i2]
  array[i2] = tmp
end

def bubble_sort(to_sort)
  n = to_sort.size()
  (0...n).each do |i|
    (0...n-i-1).each do |j|
      if to_sort[j] > to_sort[j+1]
        swap(to_sort, j ,j+1)
      end
    end
  end
  to_sort
end


def generate_random_array(len)
  array = Array(Int32).new(len, 0)
  (0...len).each do |i|
    array[i] = i
  end
  array.shuffle()
end

# This bubble sort algorithm does an inplace sort

(0...100).each do |try|
  unsorted = generate_random_array(100)
  array_to_sort = unsorted.clone()
  bubble_sort(array_to_sort)
  if array_to_sort != unsorted.sort()
    puts "Sorting failed! Algorithm not working!"
  end
end


