# Porta Cipher

[From Practicalcryptography.com](http://practicalcryptography.com/ciphers/porta-cipher/):

The Porta Cipher is a polyalphabetic substitution cipher invented by Giovanni Battista della Porta. 
Where the Vigenere cipher is a polyalphabetic cipher with 26 alphabets, the Porta is basically the same except it only uses 13 alphabets. 
The 13 cipher alphabets it uses are reciprocal, so enciphering is the same as deciphering.

The algorithm used here is the same as that used by the American Cryptogram Association.

## The Algorithm

The 'key' for a porta cipher is a key word. e.g. 'FORTIFICATION'

The Porta Cipher uses the following tableau to encipher the plaintext:
````
  Keys| a b c d e f g h i j k l m n o p q r s t u v w x y z
  ---------------------------------------------------------
  A,B | n o p q r s t u v w x y z a b c d e f g h i j k l m
  C,D | o p q r s t u v w x y z n m a b c d e f g h i j k l
  E,F | p q r s t u v w x y z n o l m a b c d e f g h i j k 
  G,H | q r s t u v w x y z n o p k l m a b c d e f g h i j
  I,J | r s t u v w x y z n o p q j k l m a b c d e f g h i
  K,L | s t u v w x y z n o p q r i j k l m a b c d e f g h
  M,N | t u v w x y z n o p q r s h i j k l m a b c d e f g
  O,P | u v w x y z n o p q r s t g h i j k l m a b c d e f
  Q,R | v w x y z n o p q r s t u f g h i j k l m a b c d e
  S,T | w x y z n o p q r s t u v e f g h i j k l m a b c d
  U,V | x y z n o p q r s t u v w d e f g h i j k l m a b c
  W,X | y z n o p q r s t u v w x c d e f g h i j k l m a b
  Y,Z | z n o p q r s t u v w x y b c d e f g h i j k l m a
````
*There are a few slightly different tableaus floating around the net, I have gone with the one used by the ACA, also referenced in Helen Fouche Gaines book "Cryptanalysis".

To encipher a message, repeat the keyword above the plaintext:
````
FORTIFICATIONFORTIFICATIONFO
DEFENDTHEEASTWALLOFTHECASTLE
````
Now we take the first key letter 'F', and find it on the first column (the key column containing two letters) on the tableau. Then, we move along the 'F' row of the tableau until we come to the column with the 'D' at the top (The 'D' is the first plaintext letter), the intersection is our ciphertext character, 'S'. The same process is repeated for all the characters.

So, the ciphertext for the above plaintext is:
````
FORTIFICATIONFORTIFICATIONFO
**DEFENDTHEEASTWALLOFTHECASTLE**
synnjscvrnrlahutukucvryrlany
````
---
You may notice that it is possible for two different keywords to produce exactly the same enciphered message. The encryption and decryption process for this cipher is identical, so encrypting a piece of text twice with the same key will return the original text.

[Example from Practicalcryptography.com](http://practicalcryptography.com/ciphers/porta-cipher/#javascript-example)

Example in Python at [https://gist.github.com/jameslyons/8910253](https://gist.github.com/jameslyons/8910253)
