package main

import "testing"

func TestFibonacci(t *testing.T) {
	tcs := map[string]struct {
		n        int
		expected int
	}{
		"n = 1":   {1, 1},
		"n = 2":   {2, 1},
		"n = 50":  {50, 12586269025},
		"n = 200": {200, 280571172992510140037611932413038677189525},
	}

	for name, tc := range tcs {
		t.Run(name, func(t *testing.T) {
			res := fib(tc.n)
			if res != tc.expected {
				t.Fatalf("want %v, got %v\n", tc.expected, res)
			}
		})
	}
}
