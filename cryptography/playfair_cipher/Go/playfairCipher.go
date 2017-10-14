package main

import (
	"fmt"
	"strings"
)

var matrix [5][5]string

func Encrypt(str string, key string) string {
	res := ""
	text := cleanText(str)
	text, n := textLen(text)
	matrix = generatMatrix(key)
	printTable(matrix)
	for i := 0; i < n-1; i += 2 {
		r1, c1 := findChar(text[i])
		r2, c2 := findChar(text[i+1])
		//fmt.Printf("R1,C1\tR2,C2\n%d,%d\t%d,%d\n", r1, c1, r2, c2)
		r := ""
		if r1 == r2 {
			r = matrix[r1][(c1+1)%5] + matrix[r2][(c2+1)%5]
		} else if c1 == c2 {
			r = matrix[(r1+1)%5][c1] + matrix[(r2+1)%5][c2]
		} else {
			r = matrix[r1][c2] + matrix[r2][c1]
		}
		res += r
	}
	return res
}

func Decrypt(str string, key string) string {
	res := ""
	n := len(str)
	text := strings.ToUpper(str)
	matrix = generatMatrix(key)
	printTable(matrix)
	for i := 0; i < n-1; i += 2 {
		r1, c1 := findChar(text[i])
		r2, c2 := findChar(text[i+1])
		//fmt.Printf("R1,C1\tR2,C2\n%d,%d\t%d,%d\n", r1, c1, r2, c2)
		r := ""
		if r1 == r2 {
			c11, c22 := c1-1, c2-1
			if c11 < 0 {
				c11 = 5 + c11
			}
			if c22 < 0 {
				c22 = 5 + c22
			}
			r = matrix[r1][(c11)%5] + matrix[r2][(c22)%5]
		} else if c1 == c2 {
			r11, r22 := r1-1, r2-1
			if r11 < 0 {
				r11 = 5 + (r11)
			}
			if r22 < 0 {
				r22 = 5 + (r22)
			}
			r = matrix[(r11)%5][c1] + matrix[(r22)%5][c2]
		} else {
			r = matrix[r1][c2] + matrix[r2][c1]
		}
		res += r
	}
	return res
}

func generatMatrix(key string) [5][5]string {
	//fmt.Println("Key: ", key)
	var (
		used   [26]bool
		matrix [5][5]string
	)
	used[9] = true // J used
	alphabets := strings.ToUpper(key) + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	i, j := 0, 0
	for k := range alphabets {
		c := alphabets[k]
		//log.Printf("c %v ", c)
		if !(c >= 'A' && c <= 'Z') {
			continue
		}
		d := c - 65
		//log.Printf("d %v ", d)
		if !used[d] {
			//log.Println("cc ", c)
			matrix[i][j] = string(c)
			//fmt.Println("added ", string(c))
			used[d] = true
			if (j + 1) == 5 {
				if (i + 1) == 5 {
					break
				} else {
					i++
				}
				j = 0
			} else {
				j++
			}

		}
	}
	return matrix
}

func cleanText(text string) string {
	cleanTxt := ""
	n := len(text)
	txt := strings.ToUpper(text)
	txt = strings.Replace(txt, "J", "I", -1)
	prevCh := "\u0000"
	for i := 0; i < n; i++ {
		nextCh := string(txt[i])
		if !(nextCh >= "A" && nextCh <= "Z") {
			continue
		}
		if nextCh == "J" {
			cleanTxt += "I"
		}
		if nextCh == prevCh {
			cleanTxt += "X" + nextCh
		} else {
			cleanTxt += nextCh
		}
		prevCh = nextCh
	}
	return cleanTxt
}

func textLen(text string) (string, int) {
	n := len(text)
	if n%2 == 0 {
		return text, n
	}
	if string(text[n-1]) != "X" {
		text += "X"
	} else {
		text += "Z"
	}
	return text, len(text)
}

func findChar(b byte) (int, int) {
	s := string(b)
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			if strings.Compare(matrix[i][j], s) == 0 {
				return i, j
			}
		}
	}
	return -1, -1
}

func printTable(t [5][5]string) {
	fmt.Println("Matrix => ")
	for i := 0; i < 5; i++ {
		for j := 0; j < 5; j++ {
			fmt.Printf("%s ", t[i][j])
		}
		fmt.Println()
	}
}

func main() {
	plainText := "helloworld"
	key := "keyword"
	encrypted := Encrypt(plainText, key)
	fmt.Println("Encrypted text: ", encrypted)
	fmt.Println("Plain text: ", Decrypt(encrypted, key))
}
