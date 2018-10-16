package issquare

func isSquare(n int) bool {
	if n == 0 || n == 1 {
		return true
	}

	var min = 1
	var max = n
	var mid = min + (max-min)/2

	for min < max {

		if mid*mid > n {
			max = mid - 1
			mid = min + (max-min)/2
		} else if mid*mid < n {
			min = mid + 1
			mid = min + (max-min)/2
		}

		if mid*mid == n {
			return true
		}

	}
	return false
}
