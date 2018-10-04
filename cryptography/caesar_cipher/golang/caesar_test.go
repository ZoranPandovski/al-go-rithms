package main

import "testing"

func TestCaesar(t *testing.T) {
	testTable := []struct {
		Input  string
		Shift  int
		Output string
	}{
		{"test", 3, "whvw"},
		{"whvw", -3, "test"},
		{"the quick brown fox jumps over the lazy dog", 10, "dro aesmu lbygx pyh tewzc yfob dro vkji nyq"},
		{"dro aesmu lbygx pyh tewzc yfob dro vkji nyq", -10, "the quick brown fox jumps over the lazy dog"},
	}

	for _, tt := range testTable {
		out := Caesar(tt.Input, tt.Shift)
		if tt.Output != out {
			t.Errorf("Output missmatch! Expected: %s, Got: %s", tt.Output, out)
		}
	}
}
