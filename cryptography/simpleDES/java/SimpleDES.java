/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package simpledes;

import java.io.*;
import java.security.*;
import java.security.spec.AlgorithmParameterSpec;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
public class SimpleDES {
    private static Cipher encrypt;
    private static Cipher decrypt;
    private static final byte[] initialization_vector = {22, 33, 11, 44, 55, 99, 66, 77};
    public static void main(String[] args) {
        String clearFile = "C:\\Users\\A\\Desktop\\DESInputData.txt";
        String encryptedFile = "C:\\Users\\A\\Desktop\\DESEncData.txt";
        String decryptedFile = "C:\\Users\\A\\Desktop\\DESDecData.txt";
        try {
            SecretKey secret_key = KeyGenerator.getInstance("DES").generateKey();
            AlgorithmParameterSpec alogrithm_specs = new IvParameterSpec(
                    initialization_vector);
            encrypt = Cipher.getInstance("DES/CBC/PKCS5Padding");
            encrypt.init(Cipher.ENCRYPT_MODE, secret_key, alogrithm_specs);
            decrypt = Cipher.getInstance("DES/CBC/PKCS5Padding");
            decrypt.init(Cipher.DECRYPT_MODE, secret_key, alogrithm_specs);
            encrypt(new FileInputStream(clearFile), new FileOutputStream(
                    encryptedFile));
            decrypt(new FileInputStream(encryptedFile), new FileOutputStream(
                    decryptedFile));
            System.out.println("End of Encryption/Decryption procedure!");
        } catch (NoSuchAlgorithmException | NoSuchPaddingException
                | InvalidKeyException | InvalidAlgorithmParameterException
                | IOException e) {
            e.printStackTrace();
        }
    }
    private static void encrypt(InputStream input, OutputStream output)
            throws IOException {
        output = new CipherOutputStream(output, encrypt);
        writeBytes(input, output);
    }
    private static void decrypt(InputStream input, OutputStream output)
            throws IOException {
        input = new CipherInputStream(input, decrypt);
        writeBytes(input, output);
    }
    private static void writeBytes(InputStream input, OutputStream output)
            throws IOException {
        byte[] writeBuffer = new byte[512];
        int readBytes = 0;
        while ((readBytes = input.read(writeBuffer)) >= 0) {
            output.write(writeBuffer, 0, readBytes);
        }
        output.close();
        input.close();
    }
}
