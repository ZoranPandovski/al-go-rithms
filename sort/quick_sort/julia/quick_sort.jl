
function swap(array, i, j)
  tmp = array[i]
  array[i] = array[j]
  array[j] = tmp
end

function partition(array, left, right)
  pivotIndex = rand(left:right)
  pivot = array[pivotIndex]
  swap(array, pivotIndex, right)

  pos = left
  for i = left:right-1
    if array[i] < pivot
      swap(array, i, pos)
      pos = pos+1
    end
  end
  
  swap(array, pos, right)

  return pos
end

function quick_sort(array, left, right)
  if left < right
    pivotIndex = partition(array, left, right)
    quick_sort(array, left, pivotIndex-1)
    quick_sort(array, pivotIndex+1, right)
  end
end


function is_sorted(array)
  max = 0
  i = 1
  while i < length(array)
    if array[i] < max
      return false
    end
    max = array[i]
    i = i+1
  end
  return true
end

function generate_random_array(length)
  rand(0:length, length)
end


for i = 1:100
  array = generate_random_array(1000)
  quick_sort(array, 1, length(array))
  if !is_sorted(array)
    println("Error! Array is not sorted!")
    exit()
  end
end

println("Quick sort works fine!")
