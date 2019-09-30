public class Main {

    public static void main(String[] args) {
        Porta porta = new Porta("FORTIFICATION");
        System.out.println(porta.encipher("OXXVEOKTRVWMMLTQPFQKTRTWMMWX"));
    }


    /**
     * The Porta Cipher is a polyalphabetic substitution cipher, and has a key consisting of a word e.g. 'FORTIFICATION'.
     * The keyword, any word or phrase will do. Must consist of alphabetical characters only, no punctuation of numbers.
     */
    public static class Porta {
        String key;

        public Porta(String key){
            this.key = key.toUpperCase();
        }


        /**
         * Encipher string using Porta cipher according to initialised key. Punctuation and whitespace
         *         are removed from the input.
         *         Example:
         *             String ciphertext = new Porta('HELLO').encipher(plaintext);
         * @param input The string to encipher.
         * @return The enciphered string.
         */
        public String encipher(String input){
            input = input.replaceAll("[^a-zA-Z]", "").toUpperCase();
            String ret = "";
            int i = 0;
            for(char c: input.toCharArray()){
                i = i % key.length();
                if("AB".contains(String.valueOf(key.charAt(i)))){ ret += "NOPQRSTUVWXYZABCDEFGHIJKLM".charAt((int) c - 65);}
                if("CD".contains(String.valueOf(key.charAt(i)))){ ret += "ZNOPQRSTUVWXYBCDEFGHIJKLMA".charAt((int) c - 65);}
                if("EF".contains(String.valueOf(key.charAt(i)))){ ret += "YZNOPQRSTUVWXCDEFGHIJKLMAB".charAt((int) c - 65);}
                if("GH".contains(String.valueOf(key.charAt(i)))){ ret += "XYZNOPQRSTUVWDEFGHIJKLMABC".charAt((int) c - 65);}
                if("IJ".contains(String.valueOf(key.charAt(i)))){ ret += "WXYZNOPQRSTUVEFGHIJKLMABCD".charAt((int) c - 65);}
                if("KL".contains(String.valueOf(key.charAt(i)))){ ret += "VWXYZNOPQRSTUFGHIJKLMABCDE".charAt((int) c - 65);}
                if("MN".contains(String.valueOf(key.charAt(i)))){ ret += "UVWXYZNOPQRSTGHIJKLMABCDEF".charAt((int) c - 65);}
                if("OP".contains(String.valueOf(key.charAt(i)))){ ret += "TUVWXYZNOPQRSHIJKLMABCDEFG".charAt((int) c - 65);}
                if("QR".contains(String.valueOf(key.charAt(i)))){ ret += "STUVWXYZNOPQRIJKLMABCDEFGH".charAt((int) c - 65);}
                if("ST".contains(String.valueOf(key.charAt(i)))){ ret += "RSTUVWXYZNOPQJKLMABCDEFGHI".charAt((int) c - 65);}
                if("UV".contains(String.valueOf(key.charAt(i)))){ ret += "QRSTUVWXYZNOPKLMABCDEFGHIJ".charAt((int) c - 65);}
                if("WX".contains(String.valueOf(key.charAt(i)))){ ret += "PQRSTUVWXYZNOLMABCDEFGHIJK".charAt((int) c - 65);}
                if("YZ".contains(String.valueOf(key.charAt(i)))){ ret += "OPQRSTUVWXYZNMABCDEFGHIJKL".charAt((int) c - 65);}
                i++;
            }
            return ret;
        }


        /**
         * Decipher string using Porta cipher according to initialised key. Punctuation and whitespace
         *         are removed from the input. For the Porta cipher, enciphering and deciphering are the same operation.
         *         Example:
         *             String plaintext = new Porta('HELLO').decipher(ciphertext);
         * @param input The string to decipher
         * @return The deciphered string
         */
        public String decipher(String input){
            return this.decipher(input);
        }
    }
}
