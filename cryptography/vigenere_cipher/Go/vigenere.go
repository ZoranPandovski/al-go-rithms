package main

import (
	"fmt"
)

func Encrypt(text string, key string) string {
	if err := checkKey(key); err != nil {
		fmt.Println("Error: ", err.Error())
		return "Err"
	}
	j := 0
	n := len(text)
	res := ""
	for i := 0; i < n; i++ {
		r := text[i]
		if r >= 'a' && r <= 'z' {
			res += string((r+key[j]-2*'a')%26 + 'a')
		} else if r >= 'A' && r <= 'Z' {
			res += string((r+key[j]-2*'A')%26 + 'A')
		} else {
			res += string(r)
		}

		j = (j + 1) % len(key)
	}
	return res
}

func Decrypt(text string, key string) string {
	if err := checkKey(key); err != nil {
		fmt.Println("Error: ", err.Error())
		return "Err"
	}
	res := ""
	j := 0
	n := len(text)
	for i := 0; i < n; i++ {
		r := text[i]
		if r >= 'a' && r <= 'z' {
			res += string((r-key[j]+26)%26 + 'a')
		} else if r >= 'A' && r <= 'Z' {
			res += string((r-key[j]+26)%26 + 'A')
		} else {
			res += string(r)
		}

		j = (j + 1) % len(key)
	}
	return res
}

func checkKey(key string) error {
	if len(key) == 0 {
		return fmt.Errorf("Key length is 0")
	}
	for _, r := range key {
		if !(r >= 'a' && r <= 'z' || r >= 'A' && r <= 'Z') {
			return fmt.Errorf("Invalid Key")
		}
	}
	return nil
}

func main() {
	plainText := "helloworld"
	key := "keyword"
	encrypted := Encrypt(plainText, key)
	fmt.Println("Encrypted text: ", encrypted)
	fmt.Println("Plain text: ", Decrypt(encrypted, key))
}
