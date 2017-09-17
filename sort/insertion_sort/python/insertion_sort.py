def insertion_sort(list):	
	for index in range(1, len(list)):
		current_value = list[index]
		i = index - 1
		while i >= 0 and current_value < list[i]:
			list[i + 1] = list[i]
			list[i] = current_value
			i = i - 1
	
	return list


def test():
	list = [5, 7, 6, 2, 1, 7, 3]
	sorted_list = insertion_sort(list)
	assert (sorted(list) == sorted_list)

if __name__ == '__main__':
    test()	
