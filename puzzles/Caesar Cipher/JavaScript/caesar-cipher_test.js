const caesarShift = require('./caesar-cipher')

describe('ceasarShift', () => {
  it('encrypts "abcABC xyzXYZ" as "bcdBCD yzaYZA" when shifting by 1', () => {
    expect(caesarShift('abcABC xyzXYZ', 1)).toEqual('bcdBCD yzaYZA')
  })
  it('encrypts "abcABC xyzXYZ" as "zabZAB wxyWXY" when shifting by -1', () => {
    expect(caesarShift('abcABC xyzXYZ', 1)).toEqual('bcdBCD yzaYZA')
  })
})
