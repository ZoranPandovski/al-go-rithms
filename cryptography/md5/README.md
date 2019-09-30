# Message-Digest algorithm 5 (MD5)

MD5 processes a variable-length message into a fixed-length output of 128 bits.
The input message is broken up into chunks of 512-bit blocks (sixteen 32-bit words); the message is padded so that its length is divisible by 512.
The padding works as follows: first a single bit, 1, is appended to the end of the message. This is followed by as many zeros as are required to bring the length of the message up to 64 bits fewer than a multiple of 512.
The remaining bits are filled up with 64 bits representing the length of the original message, modulo 2**64.

Its not recommended to use this hash in production since it has collisions, but its an interesting algorithm to study.

More at [Wikipedia](https://en.wikipedia.org/wiki/MD5).

