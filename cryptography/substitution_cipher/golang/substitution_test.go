package main

import "testing"

func TestEncrypt(t *testing.T) {
	testTable := []struct {
		Input  string
		Output string
		Error  error
	}{
		{"test", "gvhg", nil},
		{"gvhg", "test", nil},
		{"test space", "gvhg hkzxv", nil},
	}

	var st SubstitutionCipher
	for _, tt := range testTable {
		out, err := st.Encrypt(tt.Input)
		if out != tt.Output {
			t.Errorf("Invalid output! Expected: %s, Got: %s", tt.Output, out)
		}

		if err != tt.Error {
			t.Errorf("Invalid error! Expected: %v, Got: %v", tt.Error, err)
		}
	}
}

func TestAlphabetSizeMissmatch(t *testing.T) {

	var st SubstitutionCipher
	st.encriptionAlphabet = []byte("smaller")
	st.decriptionAlphabet = []byte("longer alphabet")

	_, err := st.Encrypt("test")
	if err != ErrSizeMissmatch {
		t.Errorf("Wrong alphabet error! Expected: %v, Got: %v", ErrSizeMissmatch, err)
	}
}

func TestWrongAlphabet(t *testing.T) {

	var st SubstitutionCipher
	st.encriptionAlphabet = []byte("wrong alpha")
	st.decriptionAlphabet = []byte("wrong alpha")

	_, err := st.Encrypt("q")
	if err != ErrWrongAlphabet {
		t.Errorf("Wrong alphabet error! Expected: %v, Got: %v", ErrWrongAlphabet, err)
	}
}
