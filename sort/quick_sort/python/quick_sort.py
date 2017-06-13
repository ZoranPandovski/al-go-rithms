def quick_sort(list):
	if len(list) <= 1:
		return list
	else:
		pivot = list[0]
		left , right = [] , []
		for x in list[1:]:
			if x > pivot:
				right.append(x)
			else:
				left.append(x)
		return quick_sort(left) + [pivot] + quick_sort(right)


def test():
	list = [12,3,55,1,2,7,4]
	sorted_list = quick_sort(list)
	assert (sorted_list == sorted(list)) == True


if __name__ == '__main__':
    test()
	
