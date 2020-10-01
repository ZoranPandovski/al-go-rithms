import java.math.BigInteger;
public class DigitalSignature
{
    static class Keys
    {
        BigInteger n = new BigInteger("9617");
        BigInteger d = new BigInteger("3869");
        BigInteger e = new BigInteger("17");
    }
    public static void main(String[] args)
    {
        Keys keys = new Keys();
        String message = "Hello, how are you?";
        int blockSize = 4;
        DigitalSignature obj = new DigitalSignature();
        System.out.println("A's keys:");
        System.out.println("e: " + keys.e);
        System.out.println("d: " + keys.d);
        System.out.println("n: " + keys.n);
        while (message.length() % (blockSize / 2) != 0)
        {
            message += "-";
        }
        System.out.println("A's extended message:\n"+ message);
        String encodedMsg = obj.encode(message);
        String signature = obj.doRSA(encodedMsg, keys.d, keys.n, blockSize);

        System.out.println("A's digital signature\n"+ signature);
        String signedMsg = message + "_" + signature;
        System.out.println("A's signed message:\n"+ signedMsg);
        String extractedMsgText = signedMsg.substring(0, signedMsg.indexOf('_'));

        System.out.println("B's extracted message text:\n"+ extractedMsgText);
        String extractedSignature = signedMsg.substring(signedMsg.indexOf('_') + 1);
        System.out.println("B's extracted digital signature:\n" + extractedSignature);
        String decipheredSignature = obj.doRSA(extractedSignature, keys.e, keys.n, blockSize);
        String decodedSignature = obj.decode(decipheredSignature);
        System.out.println("B's decoded digital signature:\n"+ decodedSignature);

        if (extractedMsgText.equals(decodedSignature))
        {
            System.out.println("B's conclusion: Valid signature");
        }
        else
        {
            System.out.println("B's conclusion: Invalid signature");
        }
    }
    String encode(String message)
    {
        byte[] textChars = message.getBytes();
        String temp = "";
        String encodedMsg = "";
        for (int cnt = 0; cnt<message.length();cnt++)
        {
            temp = String.valueOf(textChars[cnt] - ' ');
            if (temp.length() < 2)
            {
                temp = "0" + temp;
            }
            encodedMsg += temp;
        }
        return encodedMsg;
    }
    String decode(String encodedMsg)
    {
        String temp = "";
        String decodedText = "";
        for (int cnt = 0; cnt<encodedMsg.length();cnt += 2)
        {
            temp = encodedMsg.substring(cnt, cnt + 2);
            int val = Integer.parseInt(temp) + 32;
            decodedText += String.valueOf((char) val);
        }
        return decodedText;
    }
    String doRSA(String inputString, BigInteger exp, BigInteger n, int blockSize)
    {
        BigInteger block;
        BigInteger output;
        String temp = "";
        String outputString = "";
        for (int cnt = 0; cnt<inputString.length();cnt += blockSize)
        {
            temp = inputString.substring(cnt, cnt + blockSize);
            block = new BigInteger(temp);
            output = block.modPow(exp, n);
            temp = output.toString();
            while (temp.length() <blockSize)
            {
                temp = "0" + temp;
            }
            outputString += temp;
        }
        return outputString;
    }
}
