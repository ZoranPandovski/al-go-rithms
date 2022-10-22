# Introduction

Encryption is the process of obscuring information to make it unreadable without special knowledge. For centuries, people have devised schemes to encrypt messages — some better than others — but the advent of the computer and the Internet revolutionized the field. These days, it’s hard not to encounter some sort of encryption, whether you are buying something online or logging into Athena.

A cipher is an algorithm for performing encryption (and the reverse, decryption). The original information is called plaintext. After it is encrypted, it is called ciphertext. The ciphertext message contains all the information of the plaintext message, but it’s not in a format readable by a human or computer without the proper mechanism to decrypt it; it should resemble random gibberish to those not intended to read it.

A cipher usually depends on a piece of auxiliary information, called a key. The key is incorporated into the encryption process; the same plaintext encrypted with two different keys should have two different ciphertexts. Without the key, it should be difficult to decrypt the resulting ciphertext into readable plaintext.



# Caesar Cipher

The basic idea in this cipher is that you pick an integer for a key, and shift every letter of your message by the key. For example, if your message was “hello” and your key was 2, “h” becomes “j”, “e” becomes “g”, and so on. If you’re interested in learning more about the Caesar cipher, check out the [Wikipedia article](https://en.wikipedia.org/wiki/Caesar_cipher).
Here is a variant of the standard Caesar cipher where the space character is included in the shifts: space is treated as the letter after “z”, so with a key of 2, “y” would become ” “, “z” would become “a”, and ” ” would become “b”.