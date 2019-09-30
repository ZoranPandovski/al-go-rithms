# Function implementing Bubble Sort Algorithm
def bubble_sort (arr, size)
#########################################################################################################################
	#Bubble Sort Algorithm for sorting an array is as follows:
		# Iterate through the array size-1 times
		# In each iteration iterate from 0th index to (size-2-i)th index
		# Check 
			# If current element is greater than the next element => Swap the two elements
			# Else => Do nothing
#########################################################################################################################
	for i in 0..size-2
		for j in 0..(size-2-i)
			if (arr[j] > arr[j+1])
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			end
		end
	end
end


# Take size of the array and array as input and output the sorted array using bubble sort
print("Enter size of array: ")
size = gets.chomp.to_i
print("Enter the elements of the array: ")
arr = gets.split.map(&:to_i)
bubble_sort(arr, size)
print("Array after sorting: ")
for i in arr
	print(i.to_s + " ")
end
print("\n")
