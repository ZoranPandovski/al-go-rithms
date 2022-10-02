local vigenere = require("vigenere")

local secretKey = "iLoveLua"

local text = "Hello, World!"
local encrypted = vigenere.encrypt(text, secretKey)
local decrypted = vigenere.decrypt(encrypted, secretKey)

print("Original Text:  " .. text)
print("Encrypted Text: " .. encrypted)
print("Decrypted Text: " .. decrypted)

assert(text == decrypted)

do
    local key = "testkey1234567890"
    local text = "Encrypted Text"
    assert(vigenere.decrypt(vigenere.encrypt(text, key), key) == text)
end

do
    local key = "abcdefghijklmnopqrstuvwxyz"
    local text = "abcdefghijklmnopqrstuvwxyz"
    assert(vigenere.decrypt(vigenere.encrypt(text, key), key) == text)
end

print("Tests Passed")