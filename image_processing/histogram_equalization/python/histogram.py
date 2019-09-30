from PIL import Image

def grayscale(image):
    new = Image.new("RGB",(image.size[0],image.size[1]),(0,0,0))
    for i in range(image.size[0]):
        for j in range(image.size[1]):
            p = image.getpixel((i,j))
            media = int((p[0]+p[1]+p[2])/3)
            new.putpixel((i,j),(media,media,media))
    return new


def histogram(image):
    histogram = []
    for i in range(256):
        histogram.append(0)
    for i in range(image.size[0]):
        for j in range(image.size[1]):
            p = image.getpixel((i,j))
            ind = int((p[0]+p[1]+p[2])/3)
            quant = histogram[ind]
            quant = quant + 1
            histogram[ ind ] = quant
    return histogram

def normalization(image,hist):
    norma = []
    n = image.size[0]*image.size[1]
    for i in range(256):
        norma.append(0)
    for i in range(256):
        temp = hist[i] / n
        norma[i] = temp
    return norma

def eq(norm):
    freq = []
    for i in range(256):
        freq.append(0)
    for i in range(256):
        if i == 0:
            freq[i] = 256*norm[i]
        else:
            freq[i] = 256*norm[i] + freq[i-1]
    return freq

def around(eq):
    r = []
    for i in range(256):
        r.append(0)
    for i in range(256):
        temp = int(eq[i])
        r[i] = temp
    return r

def returnToImage(image,rounded):
    new = Image.new("RGB",(image.size[0],image.size[1]),(0,0,0))
    for i in range(image.size[0]):
        for j in range(image.size[1]):
            p = image.getpixel((i,j))
            ind = int( (p[0]+p[1]+p[2])/3 )
            new.putpixel((i,j),(rounded[ind],rounded[ind],rounded[ind]))
    return new

def histogram_equalization(image):
    hist = histogram(image)
    nor = normalization(image,hist)
    equa = eq(nor)
    rounded = around(equa)
    new = returnToImage(image,rounded)
    return new

