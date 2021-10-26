local morseCode = require("morse_code")

local originalText = string.upper("i love lua!")

local morseText = morseCode.translateText(originalText)
local translatedTextTest = morseCode.translateMorse(morseText)

print("Original Text:   " .. originalText)
print("Morse Text:      " .. morseText)
print("Translated Text: " .. translatedTextTest)

assert(translatedTextTest == originalText)

assert(morseCode.translateMorse(morseCode.translateText("ABCDEFGHIJKLMNOPQRSTUVWXYZ?!,().-1234567890 ")) == "ABCDEFGHIJKLMNOPQRSTUVWXYZ?!,().-1234567890 ")

print("Tests passed")