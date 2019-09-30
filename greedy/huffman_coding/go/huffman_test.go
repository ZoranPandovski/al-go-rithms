package main

import (
	"fmt"
	"reflect"
	"testing"
)

func TestFrequencyEmpty(t *testing.T) {
	m := ComputeFrequency([]byte(""))
	if len(m) != 0 {
		t.Error("len is not zero")
	}
}

func TestFrequencySingle(t *testing.T) {
	m := ComputeFrequency([]byte("a"))

	if m[byte('a')] != 1.0 {
		t.Error("Single frequency should be 1.0")
	}
}

func TestFrequencyMultiple(t *testing.T) {
	m := ComputeFrequency([]byte("aba"))

	// If we generalize this, we should use epsilon-based comparison.
	if m[byte('a')] != 0.6666667 {
		t.Error("'a' frequency should be 0.66 but is", m[byte('a')])
	}

	if m[byte('b')] != 0.33333334 {
		t.Error("'b' frequency should be 0.33 but is", m[byte('b')])
	}
}

func TestSortedFrequencyMultiple(t *testing.T) {
	m := ComputeFrequency([]byte("aba"))
	s := SortFrequencyList(m)
	expected := []byte{98, 97}
	for k, v := range s {
		if expected[k] != v {
			t.Error("Byte ordering by frequency did not work")
		}
	}
}

func TestTreeGeneration(t *testing.T) {
	tree := NewHuffmanTree([]byte("aaabbc"))

	if tree.Right.Value != byte('a') {
		t.Error("Expected a")
	}
	if tree.Left.Right.Value != byte('b') {
		t.Error("Expected b")
	}
	if tree.Left.Left.Value != byte('c') {
		t.Error("Expected c")
	}
}

func TestCodebookGeneration(t *testing.T) {
	tree := NewHuffmanTree([]byte("aababcabcd"))
	codebook := tree.GetCodebook()

	tests := [][]int{
		{1}, codebook[byte('a')],
		{0, 1}, codebook[byte('b')],
		{0, 0, 1}, codebook[byte('c')],
		{0, 0, 0}, codebook[byte('d')],
	}

	for k := 0; k < len(tests); k += 2 {
		expected := tests[k]
		result := tests[k+1]
		if !reflect.DeepEqual(expected, result) {
			t.Error("Expected other values!")
			fmt.Println("Expected=", expected)
			fmt.Println("Result=", result)
		}
	}
}
