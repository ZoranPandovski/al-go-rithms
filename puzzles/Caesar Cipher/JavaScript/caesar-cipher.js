function caesarShift (text, shiftBy) {
  if (shiftBy < 0) shiftBy += 26
  return text.split('').map(c => shiftLetter(c, shiftBy)).join('')
}

const isLetter = character => character.match(/[a-z]/i)

function shiftLetter (character, shiftBy) {
  if (!isLetter(character)) return character
  const characterCode = character.charCodeAt(0)
  const isUppercase = characterCode > 64 && characterCode < 91
  const codeForA = isUppercase ? 65 : 97
  const offsetFromA = (characterCode - codeForA + shiftBy) % 26
  const newCode = codeForA + offsetFromA
  return String.fromCharCode(newCode)
}

module.exports = caesarShift
