package wordsearch

import (
	"sort"
)

// WordSearch is solution for word search problem
type WordSearch struct {
	board [][]byte
}

// Exist is for checking existing word within boards
func (w *WordSearch) Exist(word string) bool {
	for i, h := range w.board {
		for j := range h {
			if w.dfs(w.board, word, i, j) == true {
				return true
			}
		}
	}
	return false
}

// dfs deep first search
func (w *WordSearch) dfs(board [][]byte, word string, i, j int) bool {
	//fmt.Println(board)
	if len(word) == 0 {
		return true
	}

	if i < 0 ||
		i >= len(board) ||
		j < 0 ||
		j >= len(board[0]) ||
		board[i][j] != word[0] {
		return false
	}
	//fmt.Println(board, word, i, j, len(board),len(board[0]), board[i][j]!=word[0], word[0], word[1:], board[i][j]  )
	tmp := board[i][j]
	board[i][j] = '#'
	result := w.dfs(board, word[1:], i+1, j) ||
		w.dfs(board, word[1:], i-1, j) ||
		w.dfs(board, word[1:], i, j+1) ||
		w.dfs(board, word[1:], i, j-1)
	board[i][j] = tmp
	return result
}

// NewWordSearch for create new instance wordsearch
func NewWordSearch(board [][]byte) *WordSearch {
	return &WordSearch{
		board: board,
	}
}

func (w *WordSearch) FindWords(words []string) []string {
	words = removeDuplicates(words)
	sort.Strings(words)
	var results = []string{}
	for _, word := range words {
		if w.Exist(word) {
			results = append(results, word)
		}
	}

	return results
}

func removeDuplicates(elements []string) []string {
	// Use map to record duplicates as we find them.
	encountered := map[string]bool{}
	result := []string{}

	for v := range elements {
		if encountered[elements[v]] == true {
			// Do not add duplicate.
		} else {
			// Record this element as an encountered element.
			encountered[elements[v]] = true
			// Append to result slice.
			result = append(result, elements[v])
		}
	}
	// Return the new slice.
	return result
}
