# Affine cipher Algorithm in Cryptography

### About
The affine cipher is a type of monoalphabetic substitution cipher, wherein each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter. The formula used means that each letter encrypts to one other letter, and back again, meaning the cipher is essentially a standard substitution cipher with a rule governing which letter goes to which. As such, it has the weaknesses of all substitution ciphers. Each letter is enciphered with the function (ax + b) mod 26, where b is the magnitude of the shift.

### Description
In the affine cipher the letters of an alphabet of size m are first mapped to the integers in the range 0 … m − 1. It then uses modular arithmetic to transform the integer that each plaintext letter corresponds to into another integer that correspond to a ciphertext letter. The encryption function for a single letter is

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/ce97efc40966ca638f45782fa519ae02104a116b)

where modulus m is the size of the alphabet and a and b are the key of the cipher. The value a must be chosen such that a and m are coprime. The decryption function is

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/adbe16cfe744243bbbe963bd46047c9d77d35128)

where a−1 is the modular multiplicative inverse of a modulo m. I.e., it satisfies the equation

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/80be61f6dee11aeecb0c3a29f779411dcd7b4c78)

The multiplicative inverse of a only exists if a and m are coprime. Hence without the restriction on a, decryption might not be possible. It can be shown as follows that decryption function is the inverse of the encryption function,

![](https://wikimedia.org/api/rest_v1/media/math/render/svg/316f8c0e9f6e5b308ec4d5b9d2d3d1dc51a1ec44)
