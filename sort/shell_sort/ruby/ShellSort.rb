def shellsort(numbers)
  gap = numbers.length / 2
  #sort
  while gap > 0 do
    i = gap
    while i < numbers.length do
      temp = numbers[i]
      j = i
      while j >= gap &&  numbers[j-gap] > temp do
        numbers[j] = numbers[j-gap]
        j-=gap
      end
      numbers[j] = temp
      i+=1
    end
    	
    gap = gap / 2
  end
  return numbers
end

result =  shellsort(Array.new(10) { rand(1...1000) })
puts result.inspect

#test
pass = true
i = 0
while i < result.length-1 do
  if result[i] > result[i+1]
    pass = false
    break
  end
  i+=1
end

if pass
  puts "Success: Array is sorted."
else
  puts "FAIL: Array is not sorted."
end