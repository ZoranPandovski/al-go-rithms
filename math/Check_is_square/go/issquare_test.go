package issquare

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestIsSquare(t *testing.T) {
	assert.Equal(t, true, isSquare(4))
	assert.Equal(t, true, isSquare(16))
	assert.Equal(t, false, isSquare(17))
}
