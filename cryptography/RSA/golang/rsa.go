// RSA implementation using bigInt
package main

import (
	"fmt"
	"math/big"
)

// Code to demonstrate RSA algorithm
func main() {
	// Defined big.Int in value: 1
	one := new(big.Int).SetInt64(1)

	// Two random prime numbers
	p := new(big.Int).SetInt64(3)
	q := new(big.Int).SetInt64(7)

	// n = pq
	n := new(big.Int).Mul(p, q)

	// Message
	msg := new(big.Int).SetInt64(12)

	// Start finding other part of public key
	// 1 < e < phi(n)
	e := new(big.Int).SetInt64(2)

	// phi(n)
	phi := new(big.Int).Mul(new(big.Int).Sub(p, one), new(big.Int).Sub(q, one))

	// Find e, which GCD(e, phi) == 1, e starts from 2
	for e.Cmp(phi) == -1 {
		if new(big.Int).GCD(nil, nil, e, phi).Cmp(one) == 0 {
			break
		} else {
			e.Add(e, one)
		}
	}

	// Private key
	d := e
	d.ModInverse(d, phi)

	// Encrypted
	c := new(big.Int).Exp(msg, e, n)
	// Decrypted
	m := new(big.Int).Exp(c, d, n)

	fmt.Printf("Message data = %d\n", msg)
	fmt.Printf("Encrypted data = %d\n", c)
	fmt.Printf("Original Message Sent = %d\n", m)
}
