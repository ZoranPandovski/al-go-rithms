# ROT-13

The ROT-13 cipher is a substitution cipher that works by shifting an alphabet
to the left by 13 places. It is a special case of the Caesar cipher, which
works by shifting an alphabet to the left by a certain number of letters. Using
ROT-13, the letter "A" would become "N" (the letter 13 places to the right of
"A" and the 14th letter of the English alphabet).

Since the English alphabet has 26 letters, decoding and encoding utilize the
same step: shift each of the letters in the message to its respective
counterpart 13 letters to the right. Because of this, ROT-13 is not
cryptographically strong at all and provides virtually no cryptographic value.
However, due to this fact, it has become the de facto mode of communication for
many online chats, forums, and discussion boards when users don't want to
reveal spoilers, answers to riddles, punchlines, etc. There are now many
[sites](http://www.rot13.com/) online that can easily encode/decode ROT-13 for
any who wishes to use it.

Since ROT-13 is trivially easy to decipher, [ROT-47](https://rot47.net/) is a
related cipher that uses numbers and symbols instead of the A-Z alphabet to
encode messages.

## In this folder

Each of the implementations include code packaged as a function that takes in a
string to be encoded/decoded, and performs the necessary operations to
encode/decode it. The Java implementation allows the programmer to specify an
arbitrary number of places to shift the letters.

There are currently no implementations of ROT-47 in this folder.
