const sampleKey = 'qwertyuiopasdfghjklzxcvbnm'

function encrypt (text, key = sampleKey) {
  if (!validateKey(key)) throw new Error('A key must contain all 26 letters.')
  key = key.toLowerCase()
  return text.split('').map(character => encryptCharacter(character, key)).join('')
}

function decrypt (text, key = sampleKey) {
  if (!validateKey(key)) throw new Error('A key must contain all 26 letters.')
  return text.split('').map(character => decryptCharacter(character, key)).join('')
}

function validateKey (key) {
  // There must be 26 unique characters
  if ([ ...new Set(key.split(''))].length !== 26) return false
  // All characters must be letters
  return /^[a-zA-Z]+$/.test(key)
}

const isLetter = character => character.match(/[a-z]/i)
const isLowerCase = character => character.match(/[a-z]/)
const codeForLowercaseA = 97

function encryptCharacter (character, key) {
  if (!isLetter(character)) return character
  const letterIndex = character.toLowerCase().charCodeAt(0) - codeForLowercaseA
  const encrypted = key.charAt(letterIndex)
  return isLowerCase(character) ? encrypted : encrypted.toUpperCase()
}

function decryptCharacter (character, key) {
  if (!isLetter(character)) return character
  const letterIndex = key.indexOf(character.toLowerCase())
  const decrypted = String.fromCharCode(codeForLowercaseA + letterIndex)
  return isLowerCase(character) ? decrypted : decrypted.toUpperCase()
}

module.exports = { encrypt, decrypt }
