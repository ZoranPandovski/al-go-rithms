package wordsearch

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCaseA(t *testing.T) {
	assert := assert.New(t)
	board := [][]byte{
		[]byte("CAA"),
		[]byte("AAA"),
		[]byte("BCD"),
	}

	nws := NewWordSearch(board)

	assert.Equal(nws.Exist("AAB"), true, "should return true")
}

func TestCaseB(t *testing.T) {
	assert := assert.New(t)
	board := [][]byte{
		[]byte("oaan"),
		[]byte("etae"),
		[]byte("ihkr"),
		[]byte("ihkr"),
	}

	nws := NewWordSearch(board)
	words := []string{"oath", "pea", "eat", "rain"}
	assert.Equal(nws.FindWords(words), []string{"eat", "oath"}, "should return []string{\"oath\",\"eat\"}")
}

func TestCaseC(t *testing.T) {
	assert := assert.New(t)
	board := [][]byte{
		[]byte("a"),
	}

	nws := NewWordSearch(board)
	words := []string{"a", "a"}
	assert.Equal(nws.FindWords(words), []string{"a"}, "should return a")
}
