### PlayFair Cipher

The Playfair cipher uses a 5 by 5 table containing a key word or phrase. Memorization of the keyword and 4 simple rules was all that was required to create the 5 by 5 table and use the cipher.
To generate the key table, one would first fill in the spaces in the table with the letters of the keyword (dropping any duplicate letters), then fill the remaining spaces with the rest of the letters of the alphabet in order (usually omitting "J" or "Q" to reduce the alphabet to fit; other versions put both "I" and "J" in the same space). The key can be written in the top rows of the table, from left to right, or in some other pattern, such as a spiral beginning in the upper-left-hand corner and ending in the center. The keyword together with the conventions for filling in the 5 by 5 table constitute the cipher key.
To encrypt a message, one would break the message into digrams (groups of 2 letters) such that, for example, "HelloWorld" becomes "HE LL OW OR LD", and map them out on the key table. If needed, append an uncommon monogram to complete the final digram. The two letters of the digram are considered as the opposite corners of a rectangle in the key table. Note the relative position of the corners of this rectangle. Then apply the following 4 rules, in order, to each pair of letters in the plaintext:
1. If both letters are the same (or only one letter is left), add an "X" after the first letter. Encrypt the new pair and continue. Some variants of Playfair use "Q" instead of "X", but any letter, itself uncommon as a repeated pair, will do.
2. If the letters appear on the same row of your table, replace them with the letters to their immediate right respectively (wrapping around to the left side of the row if a letter in the original pair was on the right side of the row).
3. If the letters appear on the same column of your table, replace them with the letters immediately below respectively (wrapping around to the top side of the column if a letter in the original pair was on the bottom side of the column).
4. If the letters are not on the same row or column, replace them with the letters on the same row respectively but at the other pair of corners of the rectangle defined by the original pair. The order is important – the first letter of the encrypted pair is the one that lies on the same row as the first letter of the plaintext pair.

To decrypt, use the INVERSE (opposite) of the last 3 rules, and the 1st as-is (dropping any extra "X"s, or "Q"s that do not make sense in the final message when finished).

#### Execution and test cases:

```
$ python3 playfair.py 
------------------PLAYFAIR ENCRYPTION------------------
1.Encryption
2.Decryption
3.Exit
Enter an option : 1
Enter the plain text : hello
Enter the key for encryption : cipher
Plain Text :  HELLO
THE DI_GRAPH IS : ['H', 'E', 'L', 'X', 'L', 'O']
THE KEY MATRIX IS AS FOLLOWS : 
['C', 'I', 'P', 'H', 'E']
['R', 'A', 'B', 'D', 'F']
['G', 'K', 'L', 'M', 'N']
['O', 'Q', 'S', 'T', 'U']
['V', 'W', 'X', 'Y', 'Z']
Cipher Text :  ECSPGS
1.Encryption
2.Decryption
3.Exit
Enter an option : 2
Enter the cipher text : ecspgs
Enter the key for decryption : cipher
Cipher Text :  ECSPGS
THE DI_GRAPH IS : ['E', 'C', 'S', 'P', 'G', 'S']
THE KEY MATRIX IS AS FOLLOWS : 
['C', 'I', 'P', 'H', 'E']
['R', 'A', 'B', 'D', 'F']
['G', 'K', 'L', 'M', 'N']
['O', 'Q', 'S', 'T', 'U']
['V', 'W', 'X', 'Y', 'Z']
HELLO
1.Encryption
2.Decryption
3.Exit
Enter an option : 3
Bye bye...
```
