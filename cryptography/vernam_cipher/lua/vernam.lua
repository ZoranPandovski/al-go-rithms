local vernam = {}

local alphabet = 
            {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
             'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
             'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
             'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}

local alphabetSwapped = {}
for key, value in pairs(alphabet) do
    alphabetSwapped[value] = key
end

vernam.encrypt = function (text, key)
    local result = ""

    for i = 1, #text do
        local c = text:sub(i, i)
        print(alphabetSwapped[c] + alphabetSwapped[key:sub(i, i)])
        result = result .. alphabet[alphabetSwapped[c] + alphabetSwapped[key:sub(i, i)]]
    end
    
    return result
end

vernam.decrypt = function (vernamtext, key)
    local result = ""

    for i = 1, #vernamtext do
        local c = vernamtext:sub(i, i)
        result = result .. alphabet[alphabetSwapped[c] - alphabetSwapped[key:sub(i, i)]]
    end
    
    return result
end

return vernam