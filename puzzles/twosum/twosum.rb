def twoSum arr, sum
  sums = []
  hash = {}
  arr.each_with_index do |el, index| # for each element in the array
    difference = sum - el # calculate needed_sum - current element
    if hash[difference] # check if this number exists in hash, if so then we found a pair of numbers that sum to needede sum
      sums << [el, difference]
      # Incase only first result is needed
      # sums = [el, difference]
      # break

      # incase index is needed
      # sums << [i, hash[difference]]
    end
    # add the current number to the hash
    hash[el] = index # Doesn't matter what u are stoing here, if you don't need the element's index in the end. Last case in the above if statement
  end
  sums
end

twoSum([3, 5, 2, -4, 8, 11], 7)
