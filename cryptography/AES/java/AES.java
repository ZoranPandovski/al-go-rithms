/**
 * AES
 * Nb = 4 (using 128-bit key)
 *
 */
public class AES {
    private static final int NK = 4;
    private static final int NB = 4;
    private static final int NR = 10;
    private static final byte[] sBox = new byte[] {
         0x63,  0x7c,  0x77,  0x7b, -0x0e,  0x6b,  0x6f, -0x3b,  0x30,  0x01,  0x67,  0x2b, -0x02, -0x29, -0x55,  0x76,
        -0x36, -0x7e, -0x37,  0x7d, -0x06,  0x59,  0x47, -0x10, -0x53, -0x2c, -0x5e, -0x51, -0x64, -0x5c,  0x72, -0x40,
        -0x49, -0x03, -0x6d,  0x26,  0x36,  0x3f, -0x09, -0x34,  0x34, -0x5b, -0x1b, -0x0f,  0x71, -0x28,  0x31,  0x15,
         0x04, -0x39,  0x23, -0x3d,  0x18, -0x6a,  0x05, -0x66,  0x07,  0x12, -0x80, -0x1e, -0x15,  0x27, -0x4e,  0x75,
         0x09, -0x7d,  0x2c,  0x1a,  0x1b,  0x6e,  0x5a, -0x60,  0x52,  0x3b, -0x2a, -0x4d,  0x29, -0x1d,  0x2f, -0x7c,
         0x53, -0x2f,  0x00, -0x13,  0x20, -0x04, -0x4f,  0x5b,  0x6a, -0x35, -0x42,  0x39,  0x4a,  0x4c,  0x58, -0x31,
        -0x30, -0x11, -0x56, -0x05,  0x43,  0x4d,  0x33, -0x7b,  0x45, -0x07,  0x02,  0x7f,  0x50,  0x3c, -0x61, -0x58,
         0x51, -0x5d,  0x40, -0x71, -0x6e, -0x63,  0x38, -0x0b, -0x44, -0x4a, -0x26,  0x21,  0x10, -0x01, -0x0d, -0x2e,
        -0x33,  0x0c,  0x13, -0x14,  0x5f, -0x69,  0x44,  0x17, -0x3c, -0x59,  0x7e,  0x3d,  0x64,  0x5d,  0x19,  0x73,
         0x60, -0x7f,  0x4f, -0x24,  0x22,  0x2a, -0x70, -0x78,  0x46, -0x12, -0x48,  0x14, -0x22,  0x5e,  0x0b, -0x25,
        -0x20,  0x32,  0x3a,  0x0a,  0x49,  0x06,  0x24,  0x5c, -0x3e, -0x2d, -0x54,  0x62, -0x6f, -0x6b, -0x1c,  0x79,
        -0x19, -0x38,  0x37,  0x6d, -0x73, -0x2b,  0x4e, -0x57,  0x6c,  0x56, -0x0c, -0x16,  0x65,  0x7a, -0x52,  0x08,
        -0x46,  0x78,  0x25,  0x2e,  0x1c, -0x5a, -0x4c, -0x3a, -0x18, -0x23,  0x74,  0x1f,  0x4b, -0x43, -0x75, -0x76,
         0x70,  0x3e, -0x4b,  0x66,  0x48,  0x03, -0x0a,  0x0e,  0x61,  0x35,  0x57, -0x47, -0x7a, -0x3f,  0x1d, -0x62,
        -0x1f, -0x08, -0x68,  0x11,  0x69, -0x27, -0x72, -0x6c, -0x65,  0x1e, -0x79, -0x17, -0x32,  0x55,  0x28, -0x21,
        -0x74, -0x5f, -0x77,  0x0d, -0x41, -0x1a,  0x42,  0x68,  0x41, -0x67,  0x2d,  0x0f, -0x50,  0x54, -0x45,  0x16
    };
    private static final byte[] rCon = new byte[] {
        0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, -0x80, 0x1b, 0x36
    };
    public byte[] key = new byte[4*NK];
    public byte[][] state = new byte[4][NB];
    public byte[][] keySchedule = new byte[NR+1][NB*4];

    public AES(String stringKey) {
        if (stringKey.length() == NK*8) {
            this.key = hexStringToBytes(stringKey);
        }
    }
    private static byte[] hexStringToBytes(String key) {
        byte[] bytesKey = new byte[NK * 4];
        for (int i = 0; i < 4 * NK; i++) {
            bytesKey[i] = (byte) Integer.parseInt(key.substring(2 * i, 2 * (i + 1)), 16);
        }
        return bytesKey;
    }
    public void setKey(String stringKey) {
        if (stringKey.length() == NK*8) {
            this.key = hexStringToBytes(stringKey);
        }
    }
    /**
     * returns string of ciphertext
     * @param plainText text to encrypt
     * @return ciphertext
     */
    public String encrypt(String plainText) {
        if (plainText.length() != 8 * NB || key.length != 4 * NK) {
            return null;
        }
        byte[] bytePlainText = hexStringToBytes(plainText);
        // place plaintext in state array
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < NB; c++) {
                state[r][c] = bytePlainText[4 * c + r];
            }
        }
        keyExpansion();
        addRoundKey(0); // round 0
        for (int round = 1; round < NR; round++) {
            subBytes();
            shiftRows();
            mixColumns();
            addRoundKey(round);
        }
        subBytes();
        shiftRows();
        addRoundKey(10);
        return stateToOutput(state);
    }
    /**
     * coverts state array to output string
     * @param bytes state array
     * @return bytes of state array ordered into a string
     */
    private String stateToOutput(byte[][] bytes) {
        StringBuilder res = new StringBuilder();
        for (int c = 0; c < NB; c++) {
            for (int r = 0; r < 4; r++) {
                String sB = Integer.toString(bytes[r][c] & 0xff, 16);
                res.append(sB.length() == 1 ? '0' + sB : sB);
            }
        }
        return res.toString();
    }
    /**
     * XORes the state with the appropriate words from the key schedule
     * @param round current round to choose which word to use
     */
    public void addRoundKey(int round) {

        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < NB; c++) {
                state[r][c] ^= keySchedule[round][4 * c + r];
            }
        }
    }
    /**
     * creates key schedule for the algorithm from encryption key
     */
    public void keyExpansion() {
        System.arraycopy(key, 0, keySchedule[0], 0, 4*NK); // copy key into first indices of key schedule
        for (int i = NK; i < NB * (NR + 1); i++) {
            byte[] previousWord = new byte[4], temp;
            System.arraycopy(keySchedule[(i - 1) / NK], 4 * ((i - 1) % NK), previousWord, 0, 4);
            if (i % NK == 0) {
                temp = subWord(rotateWord(previousWord));
                temp[0] ^= rCon[i / NK - 1]; // xor with the rConstant
            } else {
                temp = previousWord;
            }
            // copy the new word into the key schedule
            for (int j = 0; j < 4; j++) {
                keySchedule[i / NK][4 * (i % 4) + j] = (byte) (keySchedule[i / NK  - 1][4 * (i % 4) + j] ^ temp[j]);
            }
        }
    }
    /**
     * passes word through sBox for keyExpansion
     * @param word word to sBox
     * @return sBoxed word
     */
    private static byte[] subWord(byte[] word) {
        byte[] subbedWord = new byte[4];
        for (int i = 0; i < 4; i++) {
            subbedWord[i] = sBox[word[i] & 0xff];
        }
        return subbedWord;
    }
    /**
     * rotates the word by one byte to the left
     * @param word word to rotate
     * @return rotate word
     */
    public byte[] rotateWord(byte[] word) {
        byte[] shiftedWord = new byte[4];
        for (int i = 0; i < 4; i++) {
            shiftedWord[i] = word[(i + 1) % 4];
        }
        return shiftedWord;
    }
    /**
     * applies mixColumns operation on state array
     */
    public void mixColumns() {
        for (int c = 0; c < NB; c++) {
            byte[] tempColumn = new byte[4];
            // first preform operation on temp array so not to overwrite the original needed values
            for (int r = 0; r < 4; r++) {
                tempColumn[r] = mixColumnsHelper(r, c);
            }

            for (int r = 0; r < 4; r++) {
                state[r][c] = tempColumn[r];
            }
        }
    }
    /**
     * returns XOR operation needed for mixColumns
     * @param r row of byte
     * @param c column of byte
     * @return new value for byte in state array
     */
    public byte mixColumnsHelper(int r, int c) {
        return (byte) (multiplyBy02(state[r][c])
               ^ multiplyBy03(state[(r + 1) % 4][c])
               ^ state[(r + 2) % 4][c]
               ^ state[(r + 3) % 4][c]);
    }

    /**
     * preforms multiplication by two in GF(2^8)
     * @param val value to multiply with
     * @return product
     */
    public byte multiplyBy02(byte val) {
        return (byte) ((val << 1) ^ ((val & 0x80) == 0x00 ? 0x00 : 0x11b));
    }

    public byte multiplyBy03(byte i) {
        // 3 * z = 2 * z + 1 * z
        return (byte) (multiplyBy02(i) ^ i);
    }

    /**
     * applies the shiftRows operation on the state array
     */
    public void shiftRows() {
        for (int r = 1; r < 4; r++) {
            byte[] tempRow = new byte[NB];
            System.arraycopy(state[r], 0, tempRow, 0, NB);
            for (int c = 0; c < NB; c++) {
                state[r][c] = tempRow[(r + c) % NB];
            }
        }
    }

    /**
     * preforms the sBox operation on the state array
     */
    public void subBytes() {
        for (int r = 0; r < NB; r++) {
            for (int c = 0; c < NB; c++) {
                state[r][c] = sBox[state[r][c] & 0xff];
            }
        }
    }

    public static void main(String[] args) {
        AES aes = new AES("2b7e151628aed2a6abf7158809cf4f3c");
        System.out.println("Cipher Text: " + aes.encrypt("3243f6a8885a308d313198a2e0370734"));
    }
}