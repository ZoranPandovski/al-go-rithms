Each wheel contains the printable ascii characters.

Find the letter to be encoded on the first wheel.
Follow letter down the column to the final wheel and output letter.

After every letter encoded, rotate the wheels as described.

add wheels as necessary, increasing the rotation for each one to be the next
prime number.

minimum of 2 wheels are necessary for this cipher.

Minimal example:
wheel #1: a b c d e f (rotates left by 2) (shift, push)
wheel #2: d e f a b c (starts and rotates right by 3) (pop, unshift)
wheel #3: f a b c d e (starts and rotates left by 5)
wheel #4: f a b c d e (starts and rotates right by 7)
...

Using the above 4 wheels, the letter 'd' would be output as 'c'.

Using the full letter range for each wheel:
Using 2 wheels, the message RUN NOW! becomes U][2ekxG.
