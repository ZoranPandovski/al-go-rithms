package gcd

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestGCD(t *testing.T) {
	assert.Equal(t, 4, gcd(12, 8))
	assert.Equal(t, 6, gcd(54, 24))
	assert.Equal(t, 12, gcd(48, 180))
}
