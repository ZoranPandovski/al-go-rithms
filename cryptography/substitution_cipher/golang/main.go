package main

import "fmt"

func main() {
	var st SubstitutionCipher
	enc, err := st.Encrypt("hello world")
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(enc)

	dec, err := st.Encrypt(enc)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(dec)

	var st2 SubstitutionCipher
	st2.encriptionAlphabet = []byte("1234567890")
	st2.decriptionAlphabet = []byte("0987123456")
	enc2, _ := st2.Encrypt("1234567890")
	fmt.Println(enc2)
}
