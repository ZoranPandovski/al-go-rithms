const { encrypt, decrypt } = require('./substitution_cipher')

describe('substitution_cipher', () => {
  it('encrypts "abcABC xyzXYZ" as "qweQWE bnmBNM" using qwerty layout as key', () => {
    expect(encrypt('abcABC xyzXYZ')).toEqual('qweQWE bnmBNM')
  })
  it('decrypts "qweQWE bnmBNM" as "abcABC xyzXYZ" using qwerty layout as key"', () => {
    expect(decrypt('qweQWE bnmBNM')).toEqual('abcABC xyzXYZ')
  })
})
