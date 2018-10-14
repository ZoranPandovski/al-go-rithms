const digitalRoot = require('./digitalroot')
const { expect } = require('chai')


it(`Should return same values as in the array`, () => {
	const expectedValues = [1, 6, 2, 4]
	const result = [1234, 321, 2000, 1984].map(n => digitalRoot(n))
	expect(result).to.eql(expectedValues)
})