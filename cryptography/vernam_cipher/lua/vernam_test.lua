local vernam = require("vernam")

local secretKey = "iloveluaaa"

local text = "samelength"
local encrypted = vernam.encrypt(text, secretKey)
local decrypted = vernam.decrypt(encrypted, secretKey)

print("Original Text:  " .. text)
print("Encrypted Text: " .. encrypted)
print("Decrypted Text: " .. decrypted)

assert(text == decrypted)

print("Tests Passed")