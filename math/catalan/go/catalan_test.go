package catalan

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCatalan(t *testing.T) {
	assert.Equal(t, 1, catalan(1))
	assert.Equal(t, 0, catalan(0))
	assert.Equal(t, 0, catalan(-33))
	assert.Equal(t, 549043018919064, catalan(33))
}
