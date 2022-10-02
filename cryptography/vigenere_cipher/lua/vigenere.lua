local vigenere = {}

vigenere.encrypt = function (text, key)
    local result = ""

    for i = 1, #text do
        local c = text:sub(i,i)
        local part = i % #key + 1
        result = result .. string.char(string.byte(c) + string.byte(key:sub(part, part)))
    end
    
    return result
end

vigenere.decrypt = function (vigeneretext, key)
    local result = ""

    for i = 1, #vigeneretext do
        local c = vigeneretext:sub(i,i)
        local part = i % #key + 1

        result = result .. string.char(string.byte(c) - string.byte(key:sub(part, part)))
    end
    
    return result
end

return vigenere