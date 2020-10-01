package probabilistic

/**
* Usage:
* bloom := NewBloomFilter(50, 3)
* bloom.Add("foo")
* bloom.MightContain("foo")
* bloom.MightContain("bar")
* bloom.CalculateFPP()
**/

import (
	"bytes"
	"encoding/gob"
	"math"

	"github.com/spaolacci/murmur3"
	"github.com/willf/bitset"
)

type BloomFilter struct {
	capacity  int
	hashCount int
	keySize   int
	bits      bitset.BitSet
}

/**
The Add function will hash the key for multiple hash functions and
set the corresponding bit to 1.
*/
func (filter *BloomFilter) Add(key interface{}) {
	indexes := filter.getIndexes(key)

	for i := 0; i < len(indexes); i++ {
		filter.bits.Set(indexes[i])
	}

	filter.keySize += 1
}

/**
The MightContain function will verify is an element was possibly added. May
return false positives but never false negatives.
*/
func (filter *BloomFilter) MightContain(key interface{}) bool {
	indexes := filter.getIndexes(key)

	for i := 0; i < len(indexes); i++ {
		found := filter.bits.Test(indexes[i])
		if !found {
			return false
		}
	}

	return true
}

/**
Calculate the expected false positive probability.
*/
func (filter *BloomFilter) CalculateFPP() float64 {
	exp := float64(-filter.hashCount*filter.keySize) / float64(filter.capacity)
	base := math.Pow(math.E, exp)
	return math.Pow(float64(1-base), float64(filter.hashCount))
}

/**
Generate the hashes from the key. Please refer to Less Hashing, Same Performance:
Building a Better Bloom Filter (Adam Kirsch, Michael Mitzenmacher) that proves
how it is possible create the multiple hashes using only 2 hash functions.
*/
func (filter *BloomFilter) getIndexes(key interface{}) []uint {
	indexes := make([]uint, filter.hashCount)
	keyBytes, _ := getBytes(key)
	max := uint(filter.capacity)
	h1, h2 := murmur3Hash(keyBytes)

	for hashIndex := 0; hashIndex < filter.hashCount; hashIndex++ {
		i := uint(hashIndex)
		indexes[i] = (uint(h1) + i*uint(h2) + i*i) % max
	}

	return indexes
}

func murmur3Hash(keyBytes []byte) (uint64, uint64) {
	return murmur3.Sum128(keyBytes)
}

func getBytes(key interface{}) ([]byte, error) {
	var buf bytes.Buffer
	enc := gob.NewEncoder(&buf)
	err := enc.Encode(key)
	if err != nil {
		return nil, err
	}
	return buf.Bytes(), nil
}

func NewBloomFilter(capacity int, hashCount int) *BloomFilter {
	return &BloomFilter{keySize: 0, capacity: capacity, hashCount: hashCount, bits: *bitset.New(uint(capacity))}
}
