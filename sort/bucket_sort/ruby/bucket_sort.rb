def bucket_sort(array)
  if array.empty?
    return
  end
  
  bucket_size = array.length

  # Determine minimum and maximum values
  min_value = array.min
  max_value = array.max

  # Initialise buckets
  bucket_count = ((max_value - min_value) / bucket_size).floor + 1
  buckets = Array.new(bucket_count)
  (0...buckets.length).each do |i|
    buckets[i] = []
  end

  # Distribute input array values into buckets
  (0...array.length).each do |i|
    buckets[((array[i] - min_value) / bucket_size).floor].push(array[i])
  end

  # Sort buckets and place back into input array
  array.clear
  (0...buckets.length).each do |i|
    buckets[i].sort!
    buckets[i].each do |value|
      array.push(value)
    end
  end
end

array = [8, 5, 3, 1, 9, 6, 0, 7, 4, 2, 5]
puts "Before: ", array.inspect
bucket_sort(array)
puts "After:", array.inspect
