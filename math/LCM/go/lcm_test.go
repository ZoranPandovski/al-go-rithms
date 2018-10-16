package lcm

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLCM(t *testing.T) {
	assert.Equal(t, 6, lcm(2, 3))
	assert.Equal(t, 12, lcm(4, 3))
	assert.Equal(t, 18, lcm(2, 9))
	assert.Equal(t, 12, lcm(4, 6))
}
