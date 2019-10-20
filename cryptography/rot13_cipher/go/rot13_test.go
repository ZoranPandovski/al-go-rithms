package main

import "testing"

var tests = []struct {
	input    string
	expected string
}{
	{"AAA", "NNN"},
	{"NNN", "AAA"},
	{"BBB", "OOO"},
	{"OOO", "BBB"},
	{"bbb", "ooo"},
	{"ooo", "bbb"},
	{"helloworld", "uryybjbeyq"},
	{"uryybjbeyq", "helloworld"},
	{"Guvf vf harapelcgrq fnzcyr grkg", "This is unencrypted sample text"},
	{"This is unencrypted sample text", "Guvf vf harapelcgrq fnzcyr grkg"},
}

func TestRot13(t *testing.T) {
	for _, test := range tests {
		if actual := Rot13(test.input); actual != test.expected {
			t.Errorf("Rot13(%q) = %q, expected %q.",
				test.input, actual, test.expected)
		}
	}
}
