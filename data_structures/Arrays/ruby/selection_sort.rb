def selection_sort(array)
  return array if array.size <= 1

  0.upto(array.length-2) do |i|
    min = i
    (i+1).upto(array.length-1) { |k| min = k if array[k] < array[min] }
    array[i], array[min] = array[min], array[i] if i != min
  end

  return array
end
