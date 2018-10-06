import java.util.Scanner;
public class CaesarCipher {
    public static String encryption(String message, int key) {
        String encryptedMessage = "";
        char ch;
        for (int i = 0; i < message.length(); ++i) {
            ch = message.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                ch = (char) (ch + key);
                if (ch > 'z') {
                    ch = (char) (ch - 'z' + 'a' - 1);
                }
                encryptedMessage += ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = (char) (ch + key);
                if (ch > 'Z') {
                    ch = (char) (ch - 'Z' + 'A' - 1);
                }
                encryptedMessage += ch;
            } else {
                encryptedMessage += ch;
            }
        }
        return encryptedMessage;
    }
    public static String decryption(String message, int key) {
        String decryptedMessage = "";
        char ch;
        for (int i = 0; i < message.length(); ++i) {
            ch = message.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                ch = (char) (ch - key);
                if (ch < 'a') {
                    ch = (char) (ch + 'z' - 'a' + 1);
                }
                decryptedMessage += ch;
            } else if (ch >= 'A' && ch <= 'Z') {
                ch = (char) (ch - key);
                if (ch < 'A') {
                    ch = (char) (ch + 'Z' - 'A' + 1);
                }
                decryptedMessage += ch;
            } else {
                decryptedMessage += ch;
            }
        }
        return decryptedMessage;
    }
    public static void main(String[] args) {
        System.out.print("Enter message: ");
        Scanner sc = new Scanner(System.in);
        String message = sc.nextLine();
        System.out.print("Enter key: ");
        int key = sc.nextInt();
        String encMsg = encryption(message, key);
        System.out.println("Encrypted message: " + encMsg);
        System.out.println("Decrypted message: " + decryption(encMsg, key));
    }
}
