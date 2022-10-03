package testLogic

import java.util.Base64
import javax.crypto.Cipher
import javax.crypto.spec.IvParameterSpec
import javax.crypto.spec.SecretKeySpec

/*
kotlin logic implements encrypted and decrypted strings using ciphers
*/

fun main() {
    val inputText = "Abdul Karim"
    val algorithm = "AES/CBC/PKCS5Padding"
    val key = SecretKeySpec("1234567890123456".toByteArray(), "AES")
    val iv = IvParameterSpec(ByteArray(16))

    val cipherText = encrypt(algorithm, inputText, key, iv)
    println(cipherText)
    val plainText = decrypt(algorithm, cipherText, key, iv)
    println(plainText)

    assert(inputText == plainText)

}
fun decrypt(algorithm:String, cipherText: String, key: SecretKeySpec, iv: IvParameterSpec): String{
    val cipher = Cipher.getInstance(algorithm)
    cipher.init(Cipher.DECRYPT_MODE, key, iv)
    val plainText = cipher.doFinal(Base64.getDecoder().decode(cipherText))
    return String(plainText)
}
fun encrypt(algorithm: String, inputText: String, key: SecretKeySpec, iv: IvParameterSpec):String{
    val cipher = Cipher.getInstance(algorithm)
    cipher.init(Cipher.ENCRYPT_MODE, key, iv)
    val cipherText = cipher.doFinal(inputText.toByteArray())
    return Base64.getEncoder().encodeToString(cipherText)
}
