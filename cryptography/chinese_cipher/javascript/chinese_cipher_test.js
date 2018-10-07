const { encrypt, decrypt } = require('./chinese_cipher')

describe('chinese_cipher', () => {
  it('encrypts "ABCDEFGHIJKLM" as the correct 5x3 grid', () => {
    const input = 'ABCDEFGHIJKLM'
    const expected = [' JIDC', ' KHEB', 'MLGFA'].join('\r\n')
    expect(encrypt(input)).toEqual(expected)
  })
  it('decrypts the "ABCDEFGHIJKLM" grid correctly"', () => {
    const input = [' JIDC', ' KHEB', 'MLGFA'].join('\r\n')
    const expected = 'ABCDEFGHIJKLM'
    expect(decrypt(input)).toEqual(expected)
  })
})
