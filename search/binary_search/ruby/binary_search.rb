def binary_search(array, num)
	low = 0
	high = array.size - 1

	while low <= high
		mid = (low + high) / 2

		if (array[mid] == num)
			return true
		elsif array[mid] < num
			low = mid + 1
		else
			high = mid - 1
		end	
	end

	return false
end

# test
puts binary_search([4, 5, 9, 88, 104, 203, 501, 670], 5)