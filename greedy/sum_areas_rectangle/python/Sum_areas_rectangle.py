# Python3 code to find sum 
# of all area rectangle 
# possible 

# Function to find 
# area of rectangles 
def MaxTotalRectangleArea(a, n) : 
	
	# sorting the array in 
	# descending order 
	a.sort(reverse = True) 

	# store the final sum of 
	# all the rectangles area 
	# possible 
	sum = 0
	flag = False

	# temporary variable to store 
	# the length of rectangle 
	len = 0
	i = 0
	
	while (i < n-1) : 
		if(i != 0) : 
			i = i + 1
			
		# Selecting the length of 
		# rectangle so that difference 
		# between any two number is 1 
		# only. Here length is selected 
		# so flag is set 
		if ((a[i] == a[i + 1] or
			a[i] - a[i + 1] == 1) 
			and flag == False) : 
					
			# flag is set means 
			# we have got length of 
			# rectangle 
			flag = True

			# length is set to 
			# a[i+1] so that if 
			# a[i+1] is less than a[i] 
			# by 1 then also we have 
			# the correct chice for length 
			len = a[i + 1] 

			# incrementing the counter 
			# one time more as we have 
			# considered a[i+1] element 
			# also so. 
			i = i + 1

		# Selecting the width of rectangle 
		# so that difference between any 
		# two number is 1 only. Here width 
		# is selected so now flag is again 
		# unset for next rectangle 
		elif ((a[i] == a[i + 1] or
			a[i] - a[i + 1] == 1) 
				and flag == True) : 
					
			# area is calculated for 
			# rectangle 
			sum = sum + a[i + 1] * len
			
			# flag is set false 
			# for another rectangle 
			# which we can get from 
			# elements in array 
			flag = False

			# incrementing the counter 
			# one time more as we have 
			# considered a[i+1] element 
			# also so. 
			i = i + 1
		
	return sum

# Driver code 
a = [ 10, 10, 10, 10, 11, 10, 
		11, 10, 9, 9, 8, 8 ] 
n = len(a) 

print (MaxTotalRectangleArea(a, n))  
