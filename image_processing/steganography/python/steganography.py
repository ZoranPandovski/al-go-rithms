from __future__ import print_function
from PIL import Image

def encode(image, string_to_encode):
    image_data = list(image.getdata())
    bin_string = "".join(["{0:08b}".format(ord(c)) for c in string_to_encode])

    print("Initial pixel values: ")
    print(image_data[:25], end=" ")
    print(",....")
    j = 0
    for i in range(0, len(bin_string), 2):
        # Replace LSB by bits_to_replace
        bits_to_replace = bin_string[i:i+2]

        data = bin(image_data[j])[2:]
        new_pixel = data[:len(data)-2] + bits_to_replace
        image_data[j] = int(new_pixel, 2)

        j += 1

    print("Encoded pixel values: ")
    print(image_data[:25], end=" ")
    print(",....")
    output_image = Image.new(image.mode, image.size)
    output_image.putdata(image_data)
    output_image.save('out.bmp')
    print("Encoded successfully")

def decode(image):
    image_data = list(image.getdata())

    output_string = ""
    temp_string = ""
    bits = 0
    for pixel in image_data:
        binary_pixel = bin(pixel)[2:]
        encoded_value = binary_pixel[-2:]
        temp_string += encoded_value
        bits += 2
        if(bits == 8):
            # Check if character is end of message
            if chr(int(temp_string,2)) == '$':
                break
            output_string += temp_string
            temp_string = ""
            bits = 0
    
    # Now convert binary string to ascii string
    ans = ""
    for i in range(0, len(output_string), 8):
        ans += chr(int(output_string[i:i+8],2))
    print("Decoded successfully: " + ans)

a = Image.open('bird.bmp', 'r')
print("Enter string to encode ended by $: ")
string_to_encode = input()
encode(a, string_to_encode)

b = Image.open('out.bmp', 'r')
decode(b)