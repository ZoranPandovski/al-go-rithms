def kadane(array = [])
  max_ending_here = max_so_far = array[0]

  for x in array[1..-1]
    max_ending_here = max(x, max_ending_here + x)
    max_so_far = max(max_so_far, max_ending_here)
  end

  max_so_far
end