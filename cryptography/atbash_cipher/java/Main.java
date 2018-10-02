public class Main{
	public static String encrypt(String plain_text){
		
		String cipher_text = "";

		for(int i=0;i< plain_text.length();i++){
			char ch = (char)(219 - (int)plain_text.charAt(i));
			cipher_text = cipher_text + ch; 	
		}
		return cipher_text;
	}
	public static String decrypt(String cipher_text){
		
		String plain_text = "";

		for(int i=0;i< cipher_text.length();i++){
			char ch = (char)(219 - (int)cipher_text.charAt(i));
			plain_text = plain_text + ch; 	
		}
		return plain_text;
	}
	public static void main(String args[]){
		String plain_text = "thestringthatshouldbeencrypted";
		System.out.println(plain_text);
		String cipher_text = encrypt(plain_text);
		System.out.println(cipher_text);
		plain_text = decrypt(cipher_text);
		System.out.println(plain_text);
	}
}
