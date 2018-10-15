def cycleSort!(array)
  writes = 0
 
  # Loop through the array to find cycles to rotate.
  for cycleStart in 0 .. array.size-2
    item = array[cycleStart]
 
    # Find where to put the item.
    pos = cycleStart
    for i in cycleStart+1 ... array.size
      pos += 1  if array[i] < item
    end
 
    # If the item is already there, this is not a cycle.
    next  if pos == cycleStart
 
    # Otherwise, put the item there or right after any duplicates.
    pos += 1  while item == array[pos]
    array[pos], item = item, array[pos]
    writes += 1
 
    # Rotate the rest of the cycle.
    while pos != cycleStart
 
      # Find where to put the item.
      pos = cycleStart
      for i in cycleStart+1 ... array.size
        pos += 1  if array[i] < item
      end
 
      # Put the item there or right after any duplicates.
      pos += 1  while item == array[pos]
      array[pos], item = item, array[pos]
      writes += 1
    end
  end
  writes
end 
 
p a = [0, 1, 2, 2, 2, 2, 1, 9, 3.5, 5, 8, 4, 7, 0, 6]
puts "writes : #{cycleSort!(a)}"
p a