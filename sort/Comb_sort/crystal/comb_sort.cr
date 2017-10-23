def comb_sort(arr)
		gap = arr.size
		shrink = 1.3
		is_sorted = false
		temp = arr
		while is_sorted == false
				gap = (gap / shrink).floor.to_i 
				if gap > 1
						is_sorted = false
				else
						gap = 1
						is_sorted = true
				end
				i = 0
				while i + gap < temp.size
						if temp[i] > temp[i + gap]
								temp[i], temp[i + gap] = temp[i + gap], temp[i]
								is_sorted = false
						end
						i = i + 1
				end
		end
		return temp
end

sorted = comb_sort( [1,99,12,88,36,44,78,3,96] )
sorted.each do |s|
		puts s
end
