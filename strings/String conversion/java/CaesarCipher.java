import java.util.Scanner;

public class CaesarCipher {

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String s = scanner.nextLine();

        int k = scanner.nextInt();

        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String alphabet = "abcdefghijklmnopqrstuvwxyz";

        if(k>2 ) k = k%26;
        String modifiedAlphabet = alphabet.substring(k) + alphabet.substring(0,k);

        String encryptedWord = "";

        for(int i = 0;i < s.length();i++){
            int indexInOriginalAlphabet = alphabet.indexOf(s.toLowerCase().charAt(i));
            if(indexInOriginalAlphabet>-1) {
                if(!Character.isUpperCase(s.charAt(i)))
                    encryptedWord += modifiedAlphabet.charAt(indexInOriginalAlphabet);
                else
                    encryptedWord += Character.toUpperCase(modifiedAlphabet.charAt(indexInOriginalAlphabet));
            }
            else {
                encryptedWord += s.charAt(i);
            }
        }

        System.out.println(encryptedWord);
    }
}
