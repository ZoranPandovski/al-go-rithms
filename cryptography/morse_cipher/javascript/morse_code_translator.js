// Stores the morse code of each character
morseCode = {
  "A": ".-", "B": "-...",
  "C": "-.-.", "D": "-..", "E": ".",
  "F": "..-.", "G": "--.", "H": "....",
  "I": "..", "J": ".---", "K": "-.-",
  "L": ".-..", "M": "--", "N": "-.",
  "O": "---", "P": ".--.", "Q": "--.-",
  "R": ".-.", "S": "...", "T": "-",
  "U": "..-", "V": "...-", "W": ".--",
  "X": "-..-", "Y": "-.--", "Z": "--..",
  "1": ".----", "2": "..---", "3": "...--",
  "4": "....-", "5": ".....", "6": "-....",
  "7": "--...", "8": "---..", "9": "----.",
  "0": "-----", ",": "--..--", ".": ".-.-.-",
  "?": "..--..", "/": "-..-.", "-": "-....-",
  "(": "-.--.", ")": "-.--.-", " ": ""
}

// Encrypts a string
function encrypt(message) {
  encrypted = message.toUpperCase().split("").map(char => {
    return morseCode[char] + " "
  })
  return encrypted.join("")
}

// Decrypts a string
function decrypt(messages) {
  decrypted = messages.split("  ")        // Splits into words
  decrypted = decrypted.map(word => {     // Splits into characters
    return word.split(" ").map(char => {  // Decrypts each character
      return Object.keys(morseCode)[Object.values(morseCode).indexOf(char)]
    }).join("")
  })
  return decrypted.join(" ")
}

// Main function
console.log(encrypt('ALICE KILED BOB'))
console.log(decrypt('-.- . ...- .. -.  ... .--. .- -.-. . -.--  .. ...  -.- . -.-- ... . .-.  ... --- --.. .'))