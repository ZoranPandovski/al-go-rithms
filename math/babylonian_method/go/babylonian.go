package babylonian

const error = 0.0000001

func sqrt(n float64) float64 {
	var x float64

	for x = n; (x - n/x) > error; x = (x + n/x) / 2 {
	}

	return x
}
