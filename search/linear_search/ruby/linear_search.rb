# Function implementing Linear search Algorithm
def linear_search (arr, size,  num)
#########################################################################################################################
	#The Linear Search Algorithm for finding if a number is present in an array is as follows:
		# Iterate linearly through the array
		# If the current number is equal to the number to be searched => Return the INDEX of the current number
		# Else go to next number
		# If number not found in the given array => Return -1
#########################################################################################################################
	for i in 0..(size-1)
		if(arr[i] == num)
			return i
		end
	end
	return -1
end

# Take the size of the array, the array and the number to search as an input and output the INDEX of the number if it is present else output "Number not found!"
print("Enter size of the arrray: ")
size = gets.chomp.to_i
print("Enter the elements of the array: ")
arr = gets.split.map(&:to_i)
print("Enter the number to be searched: ")
num = gets.chomp.to_i

idx = linear_search(arr, size, num)

if(idx == -1)
	print("Number not found!\n")
else
	print("Number found in the array at index " + idx.to_s + "\n")
end
