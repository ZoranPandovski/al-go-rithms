package main

import "fmt"

func Encrypt(str string, depth int) string {
	w := len(str)
	grid := makeGrid(depth, w)
	dir, i := 1, 0
	for j := 0; j < w; j++ {
		grid[i][j] = string(str[j])
		i += dir * 1
		if i == depth-1 || i == 0 {
			dir *= -1
		}
	}
	printTable(grid)
	return readGrid(grid)
}

func readGrid(g [][]string) string {
	s := ""
	n := len(g)
	for i := 0; i < n; i++ {
		m := len(g[i])
		for j := 0; j < m; j++ {
			s += g[i][j]
		}
	}
	return s
}

func makeGrid(n int, w int) [][]string {
	grid := make([][]string, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]string, w)
	}
	return grid
}

func printTable(t [][]string) {
	fmt.Println("Matrix => ")
	n := len(t)
	for i := 0; i < n; i++ {
		m := len(t[i])
		for j := 0; j < m; j++ {
			fmt.Printf("%s |", t[i][j])
		}
		fmt.Println()
	}
}

func Decrypt(str string, depth int) string {
	s := ""
	l := len(str)
	cycle := (depth * 2) - 2
	extra := l % cycle
	rows := make([]int, depth)
	for i := 0; i < depth; i++ {
		rows[i] = (l / cycle) * 2
		if i == 0 || i == depth-1 {
			rows[i] = (l / cycle)
		}
	}
	i := 0
	for extra != 0 {
		rows[i]++
		extra--
		i = (i + 1) % depth
	}
	rowVals := make([][]string, depth)
	for i, j, k := 0, 0, 0; i < depth; i++ {
		rowVals[i] = make([]string, rows[i])
		k = 0
		for k < rows[i] {
			rowVals[i][k] = string(str[j])
			k++
			j++
		}
	}
	counts := make([]int, depth)
	for i := range counts {
		counts[i] = 0
	}
	dir := 1
	for i, j := 0, 0; i < l; i++ {
		s += rowVals[j][counts[j]]
		if counts[j] < rows[j] {
			counts[j]++
		}
		if j+1 == depth {
			dir = -1
		}
		if j == 0 {
			dir = 1
		}
		j = j + (1 * dir)

	}
	return s
}

func checkDepth(d int) error {
	if d < 2 {
		return fmt.Errorf("%s", "Depth is too low, use 2 or higher")
	}
	return nil
}

func main() {
	plainText := "helloworld"
	depth2 := 2
	depth3 := 3
	encrypted2 := Encrypt(plainText, depth2)
	fmt.Println("Encrypted text (depth 2): ", encrypted2)
	fmt.Println("Decrypted text (depth 2): ", Decrypt(encrypted2, depth2))
	fmt.Println()
	encrypted3 := Encrypt(plainText, depth3)
	fmt.Println("Encrypted text (depth 3): ", encrypted3)
	fmt.Println("Decrypted text (depth 3): ", Decrypt(encrypted3, depth3))
}
