from __future__ import print_function
cipherTexts = [ '7ECC555AB95BF6EC605E5F22B772D2B34FF4636340D32FABC29B',
                '73CB4855BE44F6EC60594C2BB47997B60EEE303049CD3CABC29B', 
                '64C6401BAF45F6A930435F3DF875C4E102F8742A45C824AFCA9B', 
                '7AC24F5EAF17F0A0754D5834BC3CC3A90ABD7B2A52C222ABC89B', 
                '72C24A52B550B3B8624D4F22F86BD2B30ABD642C498122A1D29B', 
                '73CC5457BF17E7A4750C5423B178D0A44FFF756355C03CABC28A', 
                '74CC0155B443B3A8795F4224AA7E97B507F2632606CF3FA0D59B' ]
hexMap = {'0': 0,
          '1': 1,
          '2': 2,
          '3': 3,
          '4': 4,
          '5': 5,
          '6': 6,
          '7': 7,
          '8': 8,
          '9': 9,
          'A': 10,
          'B': 11,
          'C': 12,
          'D': 13,
          'E': 14,
          'F': 15}

englishMap = {-65:' ',
              -32:'A',
              -31:'B',
              -30:'C',
              -29:'D',
              -28:'E',
              -27:'F',
              -26:'G',
              -25:'H',
              -24:'I',
              -23:'J',
              -22:'K',
              -21:'L',
              -20:'M',
              -19:'N',
              -18:'O',
              -17:'P',
              -16:'Q',
              -15:'R',
              -14:'S',
              -13:'T',
              -12:'U',
              -11:'V',
              -10:'W',
               -9:'X',
               -8:'Y',
               -7:'Z',
                0:'a',
                1:'b',
                2:'c',
                3:'d',
                4:'e',
                5:'f',
                6:'g',
                7:'h',
                8:'i',
                9:'j',
               10:'k',
               11:'l',
               12:'m',
               13:'n',
               14:'o',
               15:'p',
               16:'q',
               17:'r',
               18:'s',
               19:'t',
               20:'u',
               21:'v',
               22:'w',
               23:'x',
               24:'y',
               25:'z'}

l = len(cipherTexts)
print(cipherTexts)
messageLen = len(cipherTexts[0])
combCipherTexts = []
for text in range(l):
    for text_2 in range(text+1, l):
        processedCipher = ''
        for var in range(messageLen):
            xorVal = hexMap[cipherTexts[text][var]] ^ hexMap[cipherTexts[text_2][var]]
            processedCipher += hex(xorVal)[-1].capitalize()

        combCipherTexts.append(processedCipher)

print()
print(combCipherTexts)

commonWords = ['the','hello','way','well','her','day','there','with','chinese','baking','tea','notable','could','tea tree','do not']

def hexValueForWord(word):
    hexString = ''
    for letter in word:
        string = hex((ord(letter)))[-2:].capitalize()
        if(string[0].isalpha()):
            string = string[0].capitalize() + string[1]
        if(string[1].isalpha()):
            string = string[0] + string[1].capitalize()
        hexString += string

    return hexString

commonWordsHex = []
for word in commonWords:
    commonWordsHex.append(hexValueForWord(word))

print(commonWordsHex)

def convertToEnglish(hexString):
    string = ''
    for var in range(0,len(hexString)-1,2):
        word = hexString[var:var+2]
        val = 16*hexMap[word[0]] + hexMap[word[1]]
        if (val-97) not in englishMap:
            return None
        string += englishMap[val-97]

    return string

# print convertToEnglish(commonWordsHex[0])

def cribDrag(commonWordsHex, combCipherTexts):
    for word in commonWordsHex:
        for text in combCipherTexts:
            print("XORed with", convertToEnglish(word))
            word_len = len(word)
            for i in range(len(text)-word_len):
                subText = text[i:i + word_len]
                newText = ''
                for var in range(word_len):
                    xorVal = hexMap[subText[var]] ^ hexMap[word[var]]
                    newText += hex(xorVal)[-1].capitalize()
                
                newText = convertToEnglish(newText)
                if newText != None:
                    print(newText, " ", end=' ')
            print()

cribDrag(commonWordsHex,combCipherTexts)