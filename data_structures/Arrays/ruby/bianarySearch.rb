def binary_search(array, value)
  max = array.length - 1
  min = 0
  while min <= max
    middle = (min + max) / 2
    if array[mid] == value
      return middle
    elsif value < array[mid]
      max = mid - 1
    else
      min = mid + 1
    end
  end
  return nil
end
