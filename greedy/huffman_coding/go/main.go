package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	if len(os.Args) == 1 {
		fmt.Println("Usage:", os.Args[0], "<text>")
		return
	}

	data := strings.Join(os.Args[1:], " ")
	tree := NewHuffmanTree([]byte(data))
	codebook := tree.GetCodebook()
	for k, v := range codebook {
		display := ""
		if k > 48 && k < 127 {
			display = string(k)
		}
		fmt.Println(int(k), display, v)
	}
}
