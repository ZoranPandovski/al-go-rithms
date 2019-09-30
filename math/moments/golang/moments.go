package main

//Using math and sort
import (
	"fmt"
	"math"
	"sort"
)

// Operation is the Binary Operation for func Accumulate()
type Operation func(float64, float64) float64

// Accumulate is the member function of []float64
func Accumulate(data []float64, initValue float64, f Operation) float64 {
	res := initValue
	for _, v := range data {
		res = f(res, v)
	}
	return res
}

// ArithmeticAverage returns the arithmetic average of data by Accumulate
func ArithmeticAverage(data []float64) float64 {
	return Accumulate(data, 0, func(a float64, b float64) float64 {
		return a + b
	}) / float64(len(data))
}

// GeometricMean returns the geometric average of data by Accumulate
func GeometricMean(data []float64) float64 {
	return math.Pow(Accumulate(data, 1, func(a float64, b float64) float64 {
		return a * b
	}), 1.0/float64(len(data)))
}

// HarmonicMean returns the harmonic average of data by Accumulate
func HarmonicMean(data []float64) float64 {
	return float64(len(data)) / Accumulate(data, 0, func(a float64, b float64) float64 {
		return a + 1.0/b
	})
}

// Reduce against mean with an exponent by Accumulate
func Reduce(data []float64, mean float64, exponent float64) float64 {
	return Accumulate(data, 0, func(a float64, b float64) float64 {
		return a + math.Pow(b-mean, exponent)
	})
}

// Variance returns unbiased variance of data by Reduce()
func Variance(data []float64, mean float64) float64 {
	return Reduce(data, mean, 2) / (float64(len(data)) - 1)
}

// Skewness returns skewness of data by Reduce()
func Skewness(data []float64, mean float64, variance float64) float64 {
	n := float64(len(data))
	return n * Reduce(data, mean, 3) / math.Pow(variance, 1.5) / (n - 1) / (n - 2)
}

// Kurtosis returns kurtosis of data by Reduce()
func Kurtosis(data []float64, mean float64, variance float64) float64 {
	n := float64(len(data))
	nm1 := n - 1
	nm2nm3 := (n - 2) * (n - 3)
	return n*(n+1)*Reduce(data, mean, 4)/nm1/nm2nm3/math.Pow(variance, 2) - 3.0*nm1*nm1/nm2nm3
}

// Median returns the median inside data
func Median(data []float64) float64 {
	size := len(data)
	sorted := data
	sort.Float64s(sorted)
	if size%2 == 0 {
		return (sorted[size/2-1] + sorted[size/2]) / 2.0
	}
	return sorted[size/2]
}

// Code to demonstrate
func main() {
	epilson := 1.0e-05
	vec := []float64{1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0}

	arithmeticMean := ArithmeticAverage(vec)
	fmt.Println(math.Abs(arithmeticMean-5.48889) < epilson)
	fmt.Println(math.Abs(GeometricMean(vec)-4.636355) < epilson)
	fmt.Println(math.Abs(HarmonicMean(vec)-3.652661) < epilson)
	fmt.Println(math.Abs(Median(vec)-5.599999) < epilson)

	variance := Variance(vec, arithmeticMean)
	fmt.Println(math.Abs(variance-8.086111) < epilson)
	fmt.Println(math.Abs(Skewness(vec, arithmeticMean, variance)-(-0.169877)) < epilson)
	fmt.Println(math.Abs(Kurtosis(vec, arithmeticMean, variance)-(-1.37685)) < epilson)
}
