local morseCode = {}

local translatorMap = {
  ["A"]= ".-",     ["B"]= "-...",   [","] = "......",
  ["C"]= "-.-.",   ["D"]= "-..",    ["E"]= ".",
  ["F"]= "..-.",   ["G"]= "--.",    ["H"]= "....",
  ["I"]= "..",     ["J"]= ".---",   ["K"]= "-.-",
  ["L"]= ".-..",   ["M"]= "--",     ["N"]= "-.",
  ["O"]= "---",    ["P"]= ".--.",   ["Q"]= "--.-",
  ["R"]= ".-.",    ["S"]= "...",    ["T"]= "-",
  ["U"]= "..-",    ["V"]= "...-",   ["W"]= ".--",
  ["X"]= "-..-",   ["Y"]= "-.--",   ["Z"]= "--..",
  ["1"]= ".----",  ["2"]= "..---",  ["3"]= "...--",
  ["4"]= "....-",  ["5"]= ".....",  ["6"]= "-....",
  ["7"]= "--...",  ["8"]= "---..",  ["9"]= "----.",
  ["0"]= "-----",  ["!"]= "--..--", ["."]= ".-.-.-",
  ["?"]= "..--..", ["/"]= "-..-.",  ["-"]= "-....-",
  ["("]= "-.--.",  [")"]= "-.--.-", [" "]= "",
}

-- instead of looping every time to reverse the translation, i just create another table that is just the other map with key/value swapped
local translatorMapSwapped = {}

for key, value in pairs(translatorMap) do
    translatorMapSwapped[value] = key
end

morseCode.translateSingleLetter = function (word)
    return translatorMap[string.upper(word)]
end

morseCode.translateSingleMorse = function (morse)
    return translatorMapSwapped[morse]
end

morseCode.translateText = function (text)
    local translated = ""

    -- iterate over each character
    for token in string.gmatch(text, ".") do
        translated = translated .. morseCode.translateSingleLetter(token) .. " "
    end

    return translated
end

morseCode.translateMorse = function (morse)
    local translated = ""

    -- iterate over string as space separator
    for token in string.gmatch(morse, "(.-) ") do
        translated = translated .. morseCode.translateSingleMorse(token)
    end

    return translated
end

return morseCode