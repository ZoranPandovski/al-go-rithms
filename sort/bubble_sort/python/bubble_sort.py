def bubble_sort(list):
	sorted = False
	while not sorted:
		sorted = True
		for i in range(len(list) -1):
			if list[i] > list[i + 1]:
				sorted = False
				temp = list[i]
				list[i] = list[i+1]
				list[i+1] = temp
	return list


def test():
	list = [2, 1, 2, 7, 88, 4, 3, 6]
	sorted_list = bubble_sort(list)
	assert (sorted(list) == sorted_list)
	

if __name__ == '__main__':
    test()
