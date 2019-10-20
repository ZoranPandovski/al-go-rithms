package babylonian

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestBabylonianSQRT(t *testing.T) {
	assert.Equal(t, true, (4-sqrt(16)) < error)
	assert.Equal(t, true, (5-sqrt(25)) < error)
	assert.Equal(t, true, (1.4142135623746899-sqrt(2)) < error)
}
