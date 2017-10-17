def selection_sort(arr)
  return arr if arr.length <= 1

  min_idx = nil

  (0..arr.length-2).each do |i|
    min_idx = i
    j = i + 1
    while j < arr.length
      if arr[j] < arr[min_idx]
        min_idx = j
      end
      j += 1
    end
    arr[i], arr[min_idx] = arr[min_idx], arr[i]
  end
  arr
end

arr = [6,5,3,1,8,7,2,4];
p selection_sort(arr);
