def insertion_sort(arr)
	temp = arr
	length = arr.size
	length.times do |i|
		j = i
		while (j > 0) && (temp[j - 1] > temp[j])
			temp[j], temp[j - 1] = temp[j - 1], temp[j]
			j = j - 1
		end
	end
	return temp
end

sorted = insertion_sort( [1,90,34,7,16,85,66,99,12] )
sorted.each do |s|
	puts s
end
