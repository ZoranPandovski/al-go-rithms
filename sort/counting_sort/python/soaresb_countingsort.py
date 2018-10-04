
"""
Two different scenarios: given max element in list and not given.
Based on: http://www.geekviewpoint.com/python/sorting/countingsort

"""


def countingsort_2(unsorted):
	k = max(unsorted)
	counter = [0] * (k + 1)
	for i in unsorted:
		counter[i]+=1

	listIndex = 0
	for i in range(len(counter)):
		while counter[i] > 0:
			unsorted[listIndex]=i
			listIndex+=1
			counter[i]-=1

	return unsorted


def test():
	test1 = test2 = [1,3,2,4,7,5,6,10,3,23,5]
	test3 = test4 = [1,8,4,10]
	test5 = test6 = [100,4,12,5,6,12,13,17,9,0,1,54,1]
	test7 = test8 = [1,5,10,2,11,9,4,6]


	test1 = countingsort_2(test1)
	test3 = countingsort_2(test3)
	test5 = countingsort_2(test5)
	test7 = countingsort_2(test7)

	assert(test1 == sorted(test2))
	assert(test3 == sorted(test4))
	assert(test5 == sorted(test6))
	assert(test7 == sorted(test8))

if __name__ == '__main__':
	test()



