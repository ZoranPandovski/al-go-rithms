## Steganography

Steganography (pronounced STEHG-uh-NAH-gruhf-ee, from Greek steganos, or "covered," 
and graphie, or "writing") is the hiding of a secret message within an ordinary message
and the extraction of it at its destination. Steganography takes cryptography a step 
farther by hiding an encrypted message so that no one suspects it exists. Ideally, 
anyone scanning your data will fail to know it contains encrypted data.

1. The encoding is pretty simple. Each image consists of pixels. Each pixel can be written 
as a value between 0-255 (for bitmap images). 
2. We convert the message into ASCII values and then to a binary string.
3. We convert the pixel values into binary and replace the least significant 2 bits with 
2 bits from the binary message.
4. Since the LSB's don't store much data in the image, the final image (stego image) is 
almost identical to the input for the human eye.

### Input Image:
![Input](https://image.ibb.co/mnGKjK/bird.png)

### Output Image after encoding "Hey$"
![Encoded Image](https://image.ibb.co/gGRKjK/out.png)

### Execution:
![Output](https://user-images.githubusercontent.com/9103920/46569988-01040080-c97b-11e8-84c8-34fc96cdc7e7.png)

