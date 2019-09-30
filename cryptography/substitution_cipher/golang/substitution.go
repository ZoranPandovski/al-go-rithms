package main

import "errors"

var encAlphabet = []byte("abcdefghijklmnopqrstuvwxyz ")
var decAlphabet = []byte("zyxwvutsrqponmlkjihgfedcba ")

// ErrWrongAlphabet a char from text is not found in the encryption alphabet
var ErrWrongAlphabet = errors.New("char not fond in alphabet")

// ErrSizeMissmatch encryption and decryption alphabet sizes are not equal
var ErrSizeMissmatch = errors.New("alphabet size missmatch")

// SubstitutionCipher stores the encryption and decryption alphabets
type SubstitutionCipher struct {
	encriptionAlphabet []byte
	decriptionAlphabet []byte
}

// Encrypt the given text with alphabet
func (sc SubstitutionCipher) Encrypt(text string) (string, error) {
	encA := sc.encriptionAlphabet
	if sc.encriptionAlphabet == nil {
		encA = encAlphabet
	}

	decA := sc.decriptionAlphabet
	if sc.decriptionAlphabet == nil {
		decA = decAlphabet
	}

	if len(encA) != len(decA) {
		return "", ErrSizeMissmatch
	}

	encoded := make([]byte, 0, len(text))
	var idx int
	var err error
	for i := range text {
		idx, err = getIndex(encA, text[i])
		if err != nil {
			return "", err
		}
		encoded = append(encoded, decA[idx])
	}
	return string(encoded), nil
}

func getIndex(alphabet []byte, chr byte) (int, error) {
	for i, a := range alphabet {
		if a == chr {
			return i, nil
		}
	}
	return 0, ErrWrongAlphabet
}
